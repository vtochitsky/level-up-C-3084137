#include <assert.h>
#include "functions.h"

static char buf[BUFFER_LENGTH];

char *left(char *s, int len)
{
  assert(len < BUFFER_LENGTH);
  int i;
  for (i = 0; i < len; i++)
  {
    buf[i] = s[i];
  }
  buf[i] = 0;
  return buf;
}

char *right(char *s, int len)
{
  /* evaluate 's' length */
  int length = 0;
  char *tmp = s;
  while (*tmp++)
  {
    length++;
  }

  /* result */
  return s + length - len;
}

char *mid(char *s, int offset, int len)
{
  assert(len < BUFFER_LENGTH);
  int i;
  for (i = 0; i < len; i++)
  {
    buf[i] = s[offset + i];
  }
  buf[i] = 0;
  return buf;
}
