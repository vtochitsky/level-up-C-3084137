#ifndef _CALC_SCR_H_
#define _CALC_SCR_H_

/* states of frame */
enum
{
  NOEXEC = 0,
  FIRST,
  SPARE,
  STRIKE1,
  STRIKE2,
  DONE
};

typedef struct frame
{
  int first;
  int second;
  int third; /* only for frame #10 */
  int total;
  int state;
} frame_t;

void calc_score(frame_t *frames, int i);

#endif /* _CALC_SCR_H_ */
