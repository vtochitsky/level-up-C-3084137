#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

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
  printf("Left(%d): %s\n", targs->len, left(targs->input, targs->len));
  return NULL;
}

void *call_right(void *args)
{
  ThreadArgs *targs = (ThreadArgs *)args;
  printf("Right(%d): %s\n", targs->len, right(targs->input, targs->len));
  return NULL;
}

void *call_mid(void *args)
{
  ThreadArgs *targs = (ThreadArgs *)args;
  printf("Mid(%d, %d): %s\n", targs->offset, targs->len, mid(targs->input, targs->offset, targs->len));
  return NULL;
}

int main()
{
  char *input = strdup("Once upon a time, there was a string");

  pthread_t t1, t2, t3;
  ThreadArgs args1 = {input, 0, 10}; // left 10 chars
  ThreadArgs args2 = {input, 0, 10}; // right 10 chars
  ThreadArgs args3 = {input, 5, 10}; // mid from offset 5, length 10

  pthread_create(&t1, NULL, call_left, &args1);
  pthread_create(&t2, NULL, call_right, &args2);
  pthread_create(&t3, NULL, call_mid, &args3);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);

  free(input);
  return 0;
}
