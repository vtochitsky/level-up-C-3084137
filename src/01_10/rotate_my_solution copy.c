#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
  NO,
  CLOCKWISE_90,
  CLOCKWISE_180,
  CLOCKWISE_270,
  COUNTERCLOCKWISE_90,
  COUNTERCLOCKWISE_180,
  COUNTERCLOCKWISE_270,
} direction_t;

typedef char matrix_data_t;

typedef struct
{
  size_t cols;
  size_t rows;
  matrix_data_t *data;
} matrix_t;

matrix_t create_matrix(const size_t cols, const size_t rows);
// void set(matrix_t mtx, const size_t cols, const size_t rows, const matrix_data_t value);
// matrix_data_t get(matrix_t mtx, const size_t cols, const size_t rows);
void fill_matrix_random_characters(matrix_t mtx);
void print_matrix(matrix_t mtx);
void rotate_matrix(matrix_t mtx, direction_t direction);
void free_matrix(matrix_t mtx);

int main(void)
{
  matrix_t m1;
  matrix_t m2;
  matrix_t m3;

  /* ---- Matrix #1 ---- */
  m1 = create_matrix(3u, 8u);
  fill_matrix_random_characters(&m1);
  print_matrix(m1);
  rotate_matrix(m1, CLOCKWISE_90);
  print_matrix(m1);
  free_matrix(m1);

  /* ---- Matrix #2 ---- */
  // TODO: implement me

  /* ---- Matrix #3 ---- */
  // TODO: implement me

  return (EXIT_SUCCESS);
}

matrix_t create_matrix(const size_t cols, const size_t rows)
{
  matrix_t mtx;
  mtx.cols = cols;
  mtx.rows = rows;
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
  srand((unsigned)clock());
  // (matrix_data_t)rand();
  // TODO: implement me
}

void print_matrix(matrix_t mtx)
{
  // TODO: implement me
}

void rotate_matrix(matrix_t mtx, direction_t direction)
{
  // TODO: implement me
}

void free_matrix(matrix_t mtx)
{
  free(mtx.data);
  mtx.data = NULL;
}
