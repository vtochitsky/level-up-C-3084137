#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
  NO,
  CLOCKWISE_90,
} direction_t;

typedef char matrix_data_t;

char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

typedef struct
{
  size_t cols;
  size_t rows;
  matrix_data_t *data;
} matrix_t;

matrix_t create_matrix(const size_t rows, const size_t cols);
void fill_matrix_random_characters(matrix_t *mtx);
void print_matrix(matrix_t *mtx);
void rotate_matrix(matrix_t *mtx, direction_t direction);
void free_matrix(matrix_t *mtx);

int main(void)
{
  matrix_t m1;
  matrix_t m2;
  matrix_t m3;

  puts("---- Matrix #1 ---- ");
  m1 = create_matrix(8u, 3u);
  fill_matrix_random_characters(&m1);
  printf("Original:\n");
  print_matrix(&m1);
  rotate_matrix(&m1, CLOCKWISE_90);
  printf("Rotated:\n");
  print_matrix(&m1);
  free_matrix(&m1);

  puts("---- Matrix #2 ---- ");
  m2 = create_matrix(5u, 5u);
  fill_matrix_random_characters(&m2);
  printf("Original:\n");
  print_matrix(&m2);
  rotate_matrix(&m2, CLOCKWISE_90);
  printf("Rotated:\n");
  print_matrix(&m2);
  free_matrix(&m2);

  puts("---- Matrix #3 ---- ");
  m3 = create_matrix(4u, 6u);
  fill_matrix_random_characters(&m3);
  printf("Original:\n");
  print_matrix(&m3);
  rotate_matrix(&m3, CLOCKWISE_90);
  printf("Rotated:\n");
  print_matrix(&m3);
  free_matrix(&m3);

  return (EXIT_SUCCESS);
}

matrix_t create_matrix(const size_t rows, const size_t cols)
{
  matrix_t mtx;
  mtx.rows = rows;
  mtx.cols = cols;
  mtx.data = calloc(cols * rows, sizeof(matrix_data_t));
  if (NULL == mtx.data)
  {
    fprintf(stderr, "'create_matrix(%zu,%zu)' error\n", cols, rows);
    exit(EXIT_FAILURE);
  }
  return mtx;
}

void fill_matrix_random_characters(matrix_t *mtx)
{
  srand((unsigned)time(NULL));
  for (size_t x = 0u; x < mtx->cols * mtx->rows; x++)
    mtx->data[x] = (matrix_data_t)charset[rand() % (sizeof(charset) - 1)];
}

void print_matrix(matrix_t *mtx)
{
  for (size_t row = 0u; row < mtx->rows; row++)
  {
    for (size_t col = 0u; col < mtx->cols; col++)
      printf(" %c ", mtx->data[row * mtx->cols + col]);
    puts("");
  }
}

void rotate_matrix(matrix_t *mtx, direction_t direction)
{
  // TODO: implement me
}

void free_matrix(matrix_t *mtx)
{
  free(mtx->data);
  mtx->data = NULL;
}
