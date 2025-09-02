#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include "functions.h"

static int glb_error_cnt;

enum
{
  N_LEFT = 100,
  N_RIGTH = 100,
  N_MID = 100,
  MAX_TEST_LEN = 100,
  T_MID = 6,
  T_RIGTH = 3,
  T_LEFT = 4,
};

// Assume these are implemented elsewhere
char *left(char *s, int len);
char *right(char *s, int len);
char *mid(char *s, int offset, int len);

// Struct to pass arguments to threads
typedef struct
{
  char *input;
  int offset;
  int len;
} ThreadArgs;

void *call_left(void *args)
{
  ThreadArgs *targs = (ThreadArgs *)args;
  for (size_t i = 0u; i < N_LEFT; i++)
  {
    char buf[MAX_TEST_LEN];
    strcpy(buf, left(targs->input, targs->len));
    printf("Left(%d): %s\n", targs->len, buf);
    if (strcmp(buf, "Once upon a time"))
    {
      puts("LEFT ERROR");
      glb_error_cnt++;
    }
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = T_LEFT * 1000000; // T_LEFT milliseconds
    nanosleep(&ts, NULL);
  }
  return NULL;
}

void *call_right(void *args)
{
  ThreadArgs *targs = (ThreadArgs *)args;
  for (size_t i = 0u; i < N_RIGTH; i++)
  {
    char buf[MAX_TEST_LEN];
    strcpy(buf, right(targs->input, targs->len));
    printf("Right(%d): %s\n", targs->len, buf);
    if (strcmp(buf, "there was a string"))
    {
      puts("RIGTH ERROR");
      glb_error_cnt++;
    }
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = T_RIGTH * 1000000; // T_RIGTH milliseconds
    nanosleep(&ts, NULL);
  }
  return NULL;
}

void *call_mid(void *args)
{
  ThreadArgs *targs = (ThreadArgs *)args;
  for (size_t i = 0u; i < N_MID; i++)
  {
    char buf[MAX_TEST_LEN];
    strcpy(buf, mid(targs->input, targs->offset, targs->len));
    printf("Mid(%d, %d): %s\n", targs->offset, targs->len, buf);
    if (strcmp(buf, "time, there"))
    {
      puts("MID ERROR");
      glb_error_cnt++;
    }
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = T_MID * 1000000; // T_MID milliseconds
    nanosleep(&ts, NULL);
  }
  return NULL;
}

void *call_left2(void *args)
{
  ThreadArgs *targs = (ThreadArgs *)args;
  for (size_t i = 0u; i < N_LEFT; i++)
  {
    char buf[MAX_TEST_LEN];
    strcpy(buf, left(targs->input, targs->len));
    printf("Left(%d): %s\n", targs->len, buf);
    if (strcmp(buf, "Once"))
    {
      puts("LEFT ERROR");
      glb_error_cnt++;
    }
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = T_LEFT * 1000000; // T_LEFT milliseconds
    nanosleep(&ts, NULL);
  }
  return NULL;
}

int main()
{
  char *input = strdup("Once upon a time, there was a string");

  pthread_t t1, t2, t3, t4;
  ThreadArgs args1 = {input, 0, 16};  // left 16 chars
  ThreadArgs args2 = {input, 0, 18};  // right 18 chars
  ThreadArgs args3 = {input, 12, 11}; // mid from offset 12, length 11
  ThreadArgs args4 = {input, 0, 4};   // left 14 chars

  pthread_create(&t1, NULL, call_left, &args1);
  pthread_create(&t2, NULL, call_right, &args2);
  pthread_create(&t3, NULL, call_mid, &args3);
  pthread_create(&t4, NULL, call_left2, &args4);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);

  free(input);

  printf("Error counter: %d\n", glb_error_cnt);

  return 0;
}
