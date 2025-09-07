#include <stdio.h>
#include <stdlib.h> /* calloc(), free() */
#include <time.h>   /* time() */

/* optimized version 2 is implemented after rotate_solution.c review */

typedef char matrix_data_t;

typedef struct
{
  size_t cols;
  size_t rows;
  matrix_data_t *data;
} matrix_t;

matrix_t create_matrix(const size_t rows, const size_t cols);
void fill_matrix_random_characters(matrix_t *mtx);
void print_matrix(matrix_t *mtx);
void rotate_matrix_clockwise90(matrix_t *mtx);
void free_matrix(matrix_t *mtx);

int main(void)
{
  matrix_t m[3] = {
      {8u, 3u, NULL},
      {5u, 5u, NULL},
      {4u, 6u, NULL},
  };

  for (size_t i = 0u; i < 3; i++)
  {
    printf("---- Matrix #%zu ---- \n", i);
    m[i] = create_matrix(m[i].rows, m[i].cols);
    fill_matrix_random_characters(&m[i]);
    printf("Original:\n");
    print_matrix(&m[i]);
    rotate_matrix_clockwise90(&m[i]);
    printf("Rotated:\n");
    print_matrix(&m[i]);
    free_matrix(&m[i]);
  }

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
    mtx->data[x] = (matrix_data_t)(rand() % 26 + 'a');
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

/*
rotate matrix mtx with help of additional matrix
( using VLA, for big matrix heap malloc/free is better )
*/
void rotate_matrix_clockwise90(matrix_t *mtx)
{
  size_t tmp;
  matrix_data_t rot_mtx[mtx->cols * mtx->rows]; /* VLA for temorary matrix */
  size_t idx = 0u;
  for (size_t col = 0u; col < mtx->cols; col++)
    for (size_t row = mtx->rows; row > 0; row--)
      rot_mtx[idx++] = mtx->data[(row - 1) * mtx->cols + col];
  /*
  OR
    for (int row = mtx->rows-1; row >=0; row--)
      rot_mtx[idx++] = mtx->data[row * mtx->cols + col];
  */
  /* copy from stack to heap */
  for (size_t idx = 0u; idx < mtx->cols * mtx->rows; idx++)
    mtx->data[idx] = rot_mtx[idx];
  /* rearrange cols vs rows */
  tmp = mtx->cols;
  mtx->cols = mtx->rows;
  mtx->rows = tmp;
}

void free_matrix(matrix_t *mtx)
{
  free(mtx->data);
  mtx->data = NULL;
}
