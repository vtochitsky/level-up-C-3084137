#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "calc_scr.h"

#define NFRAMES 10

void test_normal_frame0_a(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 3;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 3);

    frames[0].second = 4;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 7);
}

void test_normal_frame0_b(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 5;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 5);

    frames[0].second = 5;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10);
}

void test_normal_frame1_a(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 2;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 2);

    frames[0].second = 7;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 9);

    frames[1].first = 3;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 12);

    frames[1].second = 6;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 18);
}

void test_normal_frame1_b(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 2;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 2);

    frames[0].second = 7;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 9);

    frames[1].first = 4;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);

    frames[1].second = 0;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);
}

void test_normal_frame2_a(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 2;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 2);

    frames[0].second = 7;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 9);

    frames[1].first = 4;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);

    frames[1].second = 0;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);

    frames[2].first = 5;
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);
    CU_ASSERT_EQUAL(frames[2].total, 18);

    frames[2].second = 2;
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);
    CU_ASSERT_EQUAL(frames[2].total, 20);
}

void test_normal_frame3_a(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 2;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 2);

    frames[0].second = 7;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 9);

    frames[1].first = 4;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);

    frames[1].second = 0;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);

    frames[2].first = 5;
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);
    CU_ASSERT_EQUAL(frames[2].total, 18);

    frames[2].second = 2;
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);
    CU_ASSERT_EQUAL(frames[2].total, 20);

    frames[3].first = 0;
    calc_score(frames, 3);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);
    CU_ASSERT_EQUAL(frames[2].total, 20);
    CU_ASSERT_EQUAL(frames[3].total, 20);

    frames[3].second = 2;
    calc_score(frames, 3);
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);
    CU_ASSERT_EQUAL(frames[2].total, 20);
    CU_ASSERT_EQUAL(frames[3].total, 22);
}

void test_normal_frame10_a(void)
{
    frame_t frames[NFRAMES] = {0};

    for (int i = 0; i < 10; i++)
    {
        frames[i].first = 1;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, i + 1);
        // printf("%d %d\n", i, frames[i].total);

        frames[i].second = 0;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, i + 1);
        // printf("%d %d\n", i, frames[i].total);
    }
}

void test_normal_frame10_b(void)
{
    frame_t frames[NFRAMES] = {0};

    for (int i = 0; i < 10; i++)
    {
        frames[i].first = 0;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, i);
        // printf("%d %d\n", i, frames[i].total);

        frames[i].second = 1;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, i + 1);
        // printf("%d %d\n", i, frames[i].total);
    }
}

void test_normal_frame10_c(void)
{
    frame_t frames[NFRAMES] = {0};

    for (int i = 0; i < 10; i++)
    {
        frames[i].first = 1;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, i * 2 + 1);
        // printf("%d %d\n", i, frames[i].total);

        frames[i].second = 1;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, i * 2 + 2);
        // printf("%d %d\n", i, frames[i].total);
    }
}

void test_normal_frame10_d(void)
{
    frame_t frames[NFRAMES] = {0};

    for (int i = 0; i < 10; i++)
    {
        frames[i].first = 4;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, 4 * (i + 1) + 5 * i);
        // printf("%d %d\n", i, frames[i].total);

        frames[i].second = 5;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, 4 * (i + 1) + 5 * (i + 1));
        // printf("%d %d\n", i, frames[i].total);
    }
}

void test_spare_bonus_a(void) // spare, normal
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 5;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 5); // 5 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);

    frames[0].second = 5; // spare
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);

    frames[1].first = 4;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 14); // 10 + 4
    CU_ASSERT_EQUAL(frames[1].total, 18); // 14 + 4

    frames[1].second = 2;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 14); // not changed
    CU_ASSERT_EQUAL(frames[1].total, 20); // 18 + 2
}

void test_spare_bonus_b(void) // spare, spare, normal
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 5;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 5); // 5 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);

    frames[0].second = 5; // spare
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);

    frames[1].first = 4;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 14); // 10 + 4
    CU_ASSERT_EQUAL(frames[1].total, 18); // 14 + 4

    frames[1].second = 6; // spare again
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 14); // not changed
    CU_ASSERT_EQUAL(frames[1].total, 24); // 18 + 6 yet

    frames[2].first = 1;
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 14); // not changed
    CU_ASSERT_EQUAL(frames[1].total, 25); // 24 + 1
    CU_ASSERT_EQUAL(frames[2].total, 26); // 25 + 1

    frames[2].second = 4;
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 14); // not changed
    CU_ASSERT_EQUAL(frames[1].total, 25); // not changed
    CU_ASSERT_EQUAL(frames[2].total, 30); // 26 + 4
}

void test_spare_bonus_c(void) // spare, normal, spare, normal
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 5;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 5); // 5 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[0].second = 5; // spare
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[1].first = 4;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 14); // 10 + 4
    CU_ASSERT_EQUAL(frames[1].total, 18); // 14 + 4
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[1].second = 5; // normal
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 14); // not changed
    CU_ASSERT_EQUAL(frames[1].total, 23); // 18 + 5 yet
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[2].first = 1;
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 14); // not changed
    CU_ASSERT_EQUAL(frames[1].total, 23); // not changed
    CU_ASSERT_EQUAL(frames[2].total, 24); // 23 + 1
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[2].second = 9; // spare
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 14); // not changed
    CU_ASSERT_EQUAL(frames[1].total, 23); // not changed
    CU_ASSERT_EQUAL(frames[2].total, 33); // 24 + 9 yet
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[3].first = 7;
    calc_score(frames, 3);
    CU_ASSERT_EQUAL(frames[0].total, 14); // not changed
    CU_ASSERT_EQUAL(frames[1].total, 23); // not changed
    CU_ASSERT_EQUAL(frames[2].total, 40); // 33 + 7
    CU_ASSERT_EQUAL(frames[3].total, 47); // 40 + 7

    frames[3].second = 3; // normal
    calc_score(frames, 3);
    CU_ASSERT_EQUAL(frames[0].total, 14); // not changed
    CU_ASSERT_EQUAL(frames[1].total, 23); // not changed
    CU_ASSERT_EQUAL(frames[2].total, 40); // not changed
    CU_ASSERT_EQUAL(frames[3].total, 50); // 47 + 3
}

void test_spare_bonus_d(void) // spare
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 5;
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 5); // 5 yet

    frames[0].second = 5; // spare
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10 yet
}

void test_strike_bonus_a(void) // strike, normal
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);

    frames[1].first = 3;
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 13); // 10 + 3 yet
    CU_ASSERT_EQUAL(frames[1].total, 16); // 13 + 3 yet

    frames[1].second = 6; // normal
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 19); // 13 + 6
    CU_ASSERT_EQUAL(frames[1].total, 28); // 19 + 3 + 6
}

void test_strike_bonus_b(void) // strike, strike, normal
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);
    CU_ASSERT_EQUAL(frames[2].total, 0);

    frames[1].first = 10; // strike
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 20); // 20 yet
    CU_ASSERT_EQUAL(frames[1].total, 30); // 20 + 10 yet
    CU_ASSERT_EQUAL(frames[2].total, 0);

    frames[2].first = 3;
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 23); // 20 + 3 stop
    CU_ASSERT_EQUAL(frames[1].total, 36); // 23+10 + 3
    CU_ASSERT_EQUAL(frames[2].total, 39); //

    frames[2].second = 5; // normal
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 23); //
    CU_ASSERT_EQUAL(frames[1].total, 41); //
    CU_ASSERT_EQUAL(frames[2].total, 49); //
}

void test_strike_bonus_c(void) // strike
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10
    CU_ASSERT_EQUAL(frames[1].total, 0);
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);
}

void test_strike_bonus_d(void) // strike, strike
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[1].first = 10; // strike
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 20); // 10 + 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 30); // 20 + 10 yet
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);
}

void test_strike_bonus_e(void) // strike, strike, strike
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[1].first = 10; // strike
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 20); // 10 + 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 30); // 20 + 10 yet
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[2].first = 10; // strike
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 30); // 20 + 10 stop
    CU_ASSERT_EQUAL(frames[1].total, 50); // 30 + 10 + 10 yet
    CU_ASSERT_EQUAL(frames[2].total, 60); // 50 + 10 yet
    CU_ASSERT_EQUAL(frames[3].total, 0);
}

void test_strike_bonus_f(void) // strike, strike, strike, strike
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[1].first = 10; // strike
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 20); // 10 + 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 30); // 20 + 10 yet
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[2].first = 10; // strike
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 30); // 20 + 10 stop
    CU_ASSERT_EQUAL(frames[1].total, 50); // 30 + 10 + 10 yet
    CU_ASSERT_EQUAL(frames[2].total, 60); // 50 + 10 yet
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[3].first = 10; // strike
    calc_score(frames, 3);
    CU_ASSERT_EQUAL(frames[0].total, 30);
    CU_ASSERT_EQUAL(frames[1].total, 60);
    CU_ASSERT_EQUAL(frames[2].total, 80);
    CU_ASSERT_EQUAL(frames[3].total, 90);
}

void test_strike_bonus_g(void) // strike, strike, strike, normal
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10); // 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 0);
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[1].first = 10; // strike
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 20); // 10 + 10 yet
    CU_ASSERT_EQUAL(frames[1].total, 30); // 20 + 10 yet
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[2].first = 10; // strike
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 30); // 20 + 10 stop
    CU_ASSERT_EQUAL(frames[1].total, 50); // 30 + 10 + 10 yet
    CU_ASSERT_EQUAL(frames[2].total, 60); // 50 + 10 yet
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[3].first = 4;
    calc_score(frames, 3);
    CU_ASSERT_EQUAL(frames[0].total, 30); // no change
    CU_ASSERT_EQUAL(frames[1].total, 54); // 40 + 10 + 4 stop
    CU_ASSERT_EQUAL(frames[2].total, 68); //
    CU_ASSERT_EQUAL(frames[3].total, 72); //

    frames[3].second = 5; // normal
    calc_score(frames, 3);
    CU_ASSERT_EQUAL(frames[0].total, 30); //
    CU_ASSERT_EQUAL(frames[1].total, 54); //
    CU_ASSERT_EQUAL(frames[2].total, 73); //
    CU_ASSERT_EQUAL(frames[3].total, 82); //
}

void test_strike_bonus_h(void) // 9 strikes and 1 fail
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    calc_score(frames, 0);
    CU_ASSERT_EQUAL(frames[0].total, 10);
    CU_ASSERT_EQUAL(frames[1].total, 0);
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[1].first = 10; // strike
    calc_score(frames, 1);
    CU_ASSERT_EQUAL(frames[0].total, 20);
    CU_ASSERT_EQUAL(frames[1].total, 30);
    CU_ASSERT_EQUAL(frames[2].total, 0);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[2].first = 10; // strike
    calc_score(frames, 2);
    CU_ASSERT_EQUAL(frames[0].total, 30);
    CU_ASSERT_EQUAL(frames[1].total, 50);
    CU_ASSERT_EQUAL(frames[2].total, 60);
    CU_ASSERT_EQUAL(frames[3].total, 0);

    frames[3].first = 10; // strike
    calc_score(frames, 3);
    CU_ASSERT_EQUAL(frames[0].total, 30);
    CU_ASSERT_EQUAL(frames[1].total, 60);
    CU_ASSERT_EQUAL(frames[2].total, 80);
    CU_ASSERT_EQUAL(frames[3].total, 90);

    frames[4].first = 10; // strike
    calc_score(frames, 4);
    CU_ASSERT_EQUAL(frames[0].total, 30);
    CU_ASSERT_EQUAL(frames[1].total, 60);
    CU_ASSERT_EQUAL(frames[2].total, 90);
    CU_ASSERT_EQUAL(frames[3].total, 110);
    CU_ASSERT_EQUAL(frames[4].total, 120);

    frames[5].first = 10; // strike
    calc_score(frames, 5);
    CU_ASSERT_EQUAL(frames[0].total, 30);
    CU_ASSERT_EQUAL(frames[1].total, 60);
    CU_ASSERT_EQUAL(frames[2].total, 90);
    CU_ASSERT_EQUAL(frames[3].total, 120);
    CU_ASSERT_EQUAL(frames[4].total, 140);
    CU_ASSERT_EQUAL(frames[5].total, 150);

    frames[6].first = 10; // strike
    calc_score(frames, 6);
    CU_ASSERT_EQUAL(frames[0].total, 30);
    CU_ASSERT_EQUAL(frames[1].total, 60);
    CU_ASSERT_EQUAL(frames[2].total, 90);
    CU_ASSERT_EQUAL(frames[3].total, 120);
    CU_ASSERT_EQUAL(frames[4].total, 150);
    CU_ASSERT_EQUAL(frames[5].total, 170);
    CU_ASSERT_EQUAL(frames[6].total, 180);

    frames[7].first = 10; // strike
    calc_score(frames, 7);
    CU_ASSERT_EQUAL(frames[0].total, 30);
    CU_ASSERT_EQUAL(frames[1].total, 60);
    CU_ASSERT_EQUAL(frames[2].total, 90);
    CU_ASSERT_EQUAL(frames[3].total, 120);
    CU_ASSERT_EQUAL(frames[4].total, 150);
    CU_ASSERT_EQUAL(frames[5].total, 180);
    CU_ASSERT_EQUAL(frames[6].total, 200);
    CU_ASSERT_EQUAL(frames[7].total, 210);

    frames[8].first = 10; // strike
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[0].total, 30);
    CU_ASSERT_EQUAL(frames[1].total, 60);
    CU_ASSERT_EQUAL(frames[2].total, 90);
    CU_ASSERT_EQUAL(frames[3].total, 120);
    CU_ASSERT_EQUAL(frames[4].total, 150);
    CU_ASSERT_EQUAL(frames[5].total, 180);
    CU_ASSERT_EQUAL(frames[6].total, 210);
    CU_ASSERT_EQUAL(frames[7].total, 230);
    CU_ASSERT_EQUAL(frames[8].total, 240);

    frames[9].first = 0;
    calc_score(frames, 9);
    frames[9].second = 0;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 240);
}

void test_tenth_frame_spare(void)
{
    frame_t frames[NFRAMES] = {0};
    frames[9].first = 7;
    frames[9].second = 3; // spare
    frames[9].third = 5;

    calc_score(frames, 9);

    CU_ASSERT_EQUAL(frames[9].total, 15); // 7 + 3 + 5
}

void test_tenth_frame_strike(void)
{
    frame_t frames[NFRAMES] = {0};
    frames[9].first = 10; // strike
    frames[9].second = 10;
    frames[9].third = 10;

    calc_score(frames, 9);

    CU_ASSERT_EQUAL(frames[9].total, 30); // 10 + 10 + 10
}

int main()
{
    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        puts("CU_initialize_registry");
        puts(CU_get_error_msg());
        return CU_get_error();
    }

    /* add a suites to the registry */
    CU_pSuite pSuite1, pSuite2, pSuite3;
    if (NULL == (pSuite1 = CU_add_suite("Normal frames i.e. less then spare and strike", 0, 0)) ||
        NULL == (pSuite2 = CU_add_suite("Spare bonus frames", 0, 0)) ||
        NULL == (pSuite3 = CU_add_suite("Strike bonus frames", 0, 0)))
    {
        puts("CU_add_suites ' error");
        puts(CU_get_error_msg());
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add a tests to the suite */
    if (
        NULL == CU_add_test(pSuite1, "Normal frame  0 a", test_normal_frame0_a) ||
        NULL == CU_add_test(pSuite1, "Normal frame  0 b", test_normal_frame0_b) ||
        NULL == CU_add_test(pSuite1, "Normal frame  1 a", test_normal_frame1_a) ||
        NULL == CU_add_test(pSuite1, "Normal frame  1 b", test_normal_frame1_b) ||
        NULL == CU_add_test(pSuite1, "Normal frame  2 a", test_normal_frame2_a) ||
        NULL == CU_add_test(pSuite1, "Normal frame  3 a", test_normal_frame3_a) ||
        NULL == CU_add_test(pSuite1, "Normal frame 10 a", test_normal_frame10_a) ||
        NULL == CU_add_test(pSuite1, "Normal frame 10 b", test_normal_frame10_b) ||
        NULL == CU_add_test(pSuite1, "Normal frame 10 c", test_normal_frame10_c) ||
        NULL == CU_add_test(pSuite1, "Normal frame 10 d", test_normal_frame10_d))
    {
        puts("CU_add_test to 'Normal frames' suite");
        puts(CU_get_error_msg());
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add a tests to the suite */
    if (NULL == CU_add_test(pSuite2, "spare, normal", test_spare_bonus_a) ||
        NULL == CU_add_test(pSuite2, "spare, spare, normal", test_spare_bonus_b) ||
        NULL == CU_add_test(pSuite2, "spare, normal, spare, normal", test_spare_bonus_c) ||
        NULL == CU_add_test(pSuite2, "spare", test_spare_bonus_d))
    {
        puts("CU_add_test to 'Spare bonus frames' suite");
        puts(CU_get_error_msg());
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add a tests to the suite */
    if (NULL == CU_add_test(pSuite3, "strike, normal", test_strike_bonus_a) ||
        NULL == CU_add_test(pSuite3, "strike, strike, normal", test_strike_bonus_b) ||
        NULL == CU_add_test(pSuite3, "strike", test_strike_bonus_c) ||
        NULL == CU_add_test(pSuite3, "strike, strike", test_strike_bonus_d) ||
        NULL == CU_add_test(pSuite3, "strike, strike, strike", test_strike_bonus_e) ||
        NULL == CU_add_test(pSuite3, "strike, strike, strike, strike", test_strike_bonus_f) ||
        NULL == CU_add_test(pSuite3, "strike, strike, strike, normal", test_strike_bonus_g) ||
        NULL == CU_add_test(pSuite3, "9 strikes, fail", test_strike_bonus_h))
    {
        puts("CU_add_test to 'Spare bonus frames' suite");
        puts(CU_get_error_msg());
        CU_cleanup_registry();
        return CU_get_error();
    }

    // CU_add_test(suite, "10th frame spare", test_tenth_frame_spare);
    // CU_add_test(suite, "10th frame strike", test_tenth_frame_strike);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    // CU_basic_run_tests();
    // CU_basic_run_suite(pSuite1);
    // CU_basic_run_suite(pSuite2);
    CU_basic_run_suite(pSuite3);

    CU_cleanup_registry();
    return CU_get_error();
}
