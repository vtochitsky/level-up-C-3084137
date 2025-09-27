#ifndef _CALC_FRAMES_H_
#define _CALC_FRAMES_H_

// #define VER1
#define VER2

// for VER2 only
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
  int third; // !!! only for frame #10
  int total;
  int state; // for new implmentation
} frame_t;

#define NFRAMES 10

static inline int strike(frame_t frm)
{
  return 10 == frm.first;
}

static inline int spare(frame_t frm)
{
  return 10 != frm.first && 10 == (frm.first + frm.second);
}

void calc_frame_table(frame_t *frames, int frames_length, int i);

#endif /* _CALC_FRAMES_H_ */
