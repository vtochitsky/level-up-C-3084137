#include <stdio.h>
#include <stdlib.h> /* for srand() and rand() */
#include <time.h>   /* for time() */

enum
{
  HSIZE = 8, /* horizontal board size */
  VSIZE = 8, /* vertical board size */
};

enum
{
  NO_MOVE,
  UP_LEFT,
  UP,
  UP_RIGHT,
  RIGHT,
  DOWN_RIGHT,
  DOWN,
  DOWN_LEFT,
  LEFT,
  /* The last item is total number*/
  NUMBER_OF_MOVEMENTS
};

int is_king_on_board(const int x_pos, const int y_pos, const int h_size, const int v_size);
void move_king(int *x_pos, int *y_pos);
void print_board(int x_pos, int y_pos, const int h_size, const int v_size);

int main(void)
{
  int king_x = 5; /* start position x */
  int king_y = 4; /* start position y */
  int king_movement_counter = 0;

  srand((unsigned)time(NULL)); /* init random movements */

  do
  {
    printf("Step: %d\n", king_movement_counter);
    print_board(king_x, king_y, HSIZE, VSIZE);
    move_king(&king_x, &king_y);
    king_movement_counter++;
  } while (is_king_on_board(king_x, king_y, HSIZE, VSIZE));

  printf("Total number of king's movements: %d\n", king_movement_counter - 1);

  return 0;
}

int is_king_on_board(const int x_pos, const int y_pos, const int h_size, const int v_size)
{
  if (x_pos < 0 || h_size <= x_pos || y_pos < 0 || v_size <= y_pos)
    return 0; /* out of board */

  return 1; /* on board */
}

void move_king(int *x_pos, int *y_pos)
{
  int r = rand() % NUMBER_OF_MOVEMENTS;
  switch (r)
  {
  case (NO_MOVE):
    /* nothing to do */
    break;
  case (UP_LEFT):
    (*x_pos)--;
    (*y_pos)--;
    break;
  case (UP):
    (*y_pos)--;
    break;
  case (UP_RIGHT):
    (*x_pos)++;
    (*y_pos)--;
    break;
  case (RIGHT):
    (*x_pos)++;
    break;
  case (DOWN_RIGHT):
    (*x_pos)++;
    (*y_pos)++;
    break;
  case (DOWN):
    (*y_pos)++;
    break;
  case (DOWN_LEFT):
    (*x_pos)--;
    (*y_pos)++;
    break;
  case (LEFT):
    (*x_pos)--;
    break;
  default:
    /* nothing to do */
    break;
  }
}

void print_board(int x_pos, int y_pos, const int h_size, const int v_size)
{
  
}
