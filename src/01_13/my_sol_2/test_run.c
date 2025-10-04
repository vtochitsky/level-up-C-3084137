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

        frames[i].second = 0;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, i + 1);
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

        frames[i].second = 1;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, i + 1);
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

        frames[i].second = 1;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, i * 2 + 2);
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

        frames[i].second = 5;
        calc_score(frames, i);
        CU_ASSERT_EQUAL(frames[i].total, 4 * (i + 1) + 5 * (i + 1));
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

    frames[9].first = 0; // fail
    calc_score(frames, 9);
    frames[9].second = 0;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 240);
}

// ------------------------------------------------------------
// CUnit tests for calc_score() - Bowling scoring
// Each test iterates calc_score(frames, i) for i = 0..8
// Excludes 10th frame (index 9) as requested
// ------------------------------------------------------------

void test_open_frames_all(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 3;
    frames[0].second = 4; // 7
    frames[1].first = 2;
    frames[1].second = 5; // 7
    frames[2].first = 6;
    frames[2].second = 1; // 7
    frames[3].first = 0;
    frames[3].second = 8; // 8
    frames[4].first = 1;
    frames[4].second = 1; // 2
    frames[5].first = 5;
    frames[5].second = 3; // 8
    frames[6].first = 2;
    frames[6].second = 2; // 4
    frames[7].first = 9;
    frames[7].second = 0; // 9
    frames[8].first = 4;
    frames[8].second = 4; // 8

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 7);
    CU_ASSERT_EQUAL(frames[1].total, 14);
    CU_ASSERT_EQUAL(frames[2].total, 21);
    CU_ASSERT_EQUAL(frames[3].total, 29);
    CU_ASSERT_EQUAL(frames[4].total, 31);
    CU_ASSERT_EQUAL(frames[5].total, 39);
    CU_ASSERT_EQUAL(frames[6].total, 43);
    CU_ASSERT_EQUAL(frames[7].total, 52);
    CU_ASSERT_EQUAL(frames[8].total, 60);
}

void test_single_spare_at_3(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 1;
    frames[0].second = 1; // 2
    frames[1].first = 4;
    frames[1].second = 5; // 9
    frames[2].first = 3;
    frames[2].second = 2; // 5
    frames[3].first = 7;
    frames[3].second = 3; // spare
    frames[4].first = 6;
    frames[4].second = 2; // 8
    frames[5].first = 0;
    frames[5].second = 0; // 0
    frames[6].first = 2;
    frames[6].second = 7; // 9
    frames[7].first = 8;
    frames[7].second = 0; // 8
    frames[8].first = 5;
    frames[8].second = 4; // 9

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 2);
    CU_ASSERT_EQUAL(frames[1].total, 11);
    CU_ASSERT_EQUAL(frames[2].total, 16);
    CU_ASSERT_EQUAL(frames[3].total, 32); // 10 + next first (6)
    CU_ASSERT_EQUAL(frames[4].total, 40);
    CU_ASSERT_EQUAL(frames[5].total, 40);
    CU_ASSERT_EQUAL(frames[6].total, 49);
    CU_ASSERT_EQUAL(frames[7].total, 57);
    CU_ASSERT_EQUAL(frames[8].total, 66);
}

void test_single_strike_at_2(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 3;
    frames[0].second = 6; // 9
    frames[1].first = 2;
    frames[1].second = 2; // 4
    frames[2].first = 10; // strike
    frames[3].first = 4;
    frames[3].second = 3; // 7
    frames[4].first = 5;
    frames[4].second = 1; // 6
    frames[5].first = 0;
    frames[5].second = 5; // 5
    frames[6].first = 7;
    frames[6].second = 2; // 9
    frames[7].first = 1;
    frames[7].second = 0; // 1
    frames[8].first = 6;
    frames[8].second = 3; // 9

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);
    CU_ASSERT_EQUAL(frames[2].total, 30); // 10 + 4 + 3
    CU_ASSERT_EQUAL(frames[3].total, 37);
    CU_ASSERT_EQUAL(frames[4].total, 43);
    CU_ASSERT_EQUAL(frames[5].total, 48);
    CU_ASSERT_EQUAL(frames[6].total, 57);
    CU_ASSERT_EQUAL(frames[7].total, 58);
    CU_ASSERT_EQUAL(frames[8].total, 67);
}

void test_strike_then_spare(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    frames[1].first = 7;
    frames[1].second = 3; // spare
    frames[2].first = 4;
    frames[2].second = 4; // 8
    frames[3].first = 0;
    frames[3].second = 1; // 1
    frames[4].first = 6;
    frames[4].second = 0; // 6
    frames[5].first = 5;
    frames[5].second = 4; // 9
    frames[6].first = 2;
    frames[6].second = 2; // 4
    frames[7].first = 8;
    frames[7].second = 1; // 9
    frames[8].first = 3;
    frames[8].second = 5; // 8

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 20); // 10 + 7 + 3
    CU_ASSERT_EQUAL(frames[1].total, 34); // 10 + next first (4)
    CU_ASSERT_EQUAL(frames[2].total, 42);
    CU_ASSERT_EQUAL(frames[3].total, 43);
    CU_ASSERT_EQUAL(frames[4].total, 49);
    CU_ASSERT_EQUAL(frames[5].total, 58);
    CU_ASSERT_EQUAL(frames[6].total, 62);
    CU_ASSERT_EQUAL(frames[7].total, 71);
    CU_ASSERT_EQUAL(frames[8].total, 79);
}

void test_spare_then_strike(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 5;
    frames[0].second = 5; // spare
    frames[1].first = 10; // strike
    frames[2].first = 3;
    frames[2].second = 4; // 7
    frames[3].first = 2;
    frames[3].second = 2; // 4
    frames[4].first = 6;
    frames[4].second = 1; // 7
    frames[5].first = 0;
    frames[5].second = 0; // 0
    frames[6].first = 9;
    frames[6].second = 0; // 9
    frames[7].first = 1;
    frames[7].second = 8; // 9
    frames[8].first = 4;
    frames[8].second = 4; // 8

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 20); // 10 + next first (10)
    CU_ASSERT_EQUAL(frames[1].total, 37); // 10 + 3 + 4
    CU_ASSERT_EQUAL(frames[2].total, 44);
    CU_ASSERT_EQUAL(frames[3].total, 48);
    CU_ASSERT_EQUAL(frames[4].total, 55);
    CU_ASSERT_EQUAL(frames[5].total, 55);
    CU_ASSERT_EQUAL(frames[6].total, 64);
    CU_ASSERT_EQUAL(frames[7].total, 73);
    CU_ASSERT_EQUAL(frames[8].total, 81);
}

void test_double_strike_then_open(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 2;
    calc_score(frames, 0);
    frames[0].second = 3; // 5
    calc_score(frames, 0);
    frames[1].first = 10; // strike
    calc_score(frames, 1);
    frames[2].first = 10; // strike
    calc_score(frames, 2);
    frames[3].first = 4;
    calc_score(frames, 3);
    frames[3].second = 2; // 6
    calc_score(frames, 3);
    frames[4].first = 5;
    calc_score(frames, 4);
    frames[4].second = 0; // 5
    calc_score(frames, 4);
    frames[5].first = 3;
    calc_score(frames, 5);
    frames[5].second = 3; // 6
    calc_score(frames, 5);
    frames[6].first = 0;
    calc_score(frames, 6);
    frames[6].second = 1; // 1
    calc_score(frames, 6);
    frames[7].first = 8;
    calc_score(frames, 7);
    frames[7].second = 1; // 9
    calc_score(frames, 7);
    frames[8].first = 6;
    calc_score(frames, 8);
    frames[8].second = 2; // 8
    calc_score(frames, 8);

    CU_ASSERT_EQUAL(frames[0].total, 5);
    CU_ASSERT_EQUAL(frames[1].total, 29); // 10 + 10 + 4
    CU_ASSERT_EQUAL(frames[2].total, 45); // 10 + 4 + 2
    CU_ASSERT_EQUAL(frames[3].total, 51);
    CU_ASSERT_EQUAL(frames[4].total, 56);
    CU_ASSERT_EQUAL(frames[5].total, 62);
    CU_ASSERT_EQUAL(frames[6].total, 63);
    CU_ASSERT_EQUAL(frames[7].total, 72);
    CU_ASSERT_EQUAL(frames[8].total, 80);
}

void test_two_spares_row_mid(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 1;
    frames[0].second = 2; // 3
    frames[1].first = 4;
    frames[1].second = 4; // 8
    frames[2].first = 6;
    frames[2].second = 4; // spare
    frames[3].first = 5;
    frames[3].second = 5; // spare
    frames[4].first = 2;
    frames[4].second = 3; // 5
    frames[5].first = 0;
    frames[5].second = 5; // 5
    frames[6].first = 7;
    frames[6].second = 1; // 8
    frames[7].first = 9;
    frames[7].second = 0; // 9
    frames[8].first = 3;
    frames[8].second = 6; // 9

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 3);
    CU_ASSERT_EQUAL(frames[1].total, 11);
    CU_ASSERT_EQUAL(frames[2].total, 26); // 10 + next first (5)
    CU_ASSERT_EQUAL(frames[3].total, 38); // 10 + next first (2)
    CU_ASSERT_EQUAL(frames[4].total, 43);
    CU_ASSERT_EQUAL(frames[5].total, 48);
    CU_ASSERT_EQUAL(frames[6].total, 56);
    CU_ASSERT_EQUAL(frames[7].total, 65);
    CU_ASSERT_EQUAL(frames[8].total, 74);
}

void test_alternating_open_spare(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 3;
    frames[0].second = 5; // 8
    frames[1].first = 9;
    frames[1].second = 1; // spare
    frames[2].first = 2;
    frames[2].second = 3; // 5
    frames[3].first = 7;
    frames[3].second = 3; // spare
    frames[4].first = 1;
    frames[4].second = 1; // 2
    frames[5].first = 8;
    frames[5].second = 2; // spare
    frames[6].first = 0;
    frames[6].second = 0; // 0
    frames[7].first = 5;
    frames[7].second = 4; // 9
    frames[8].first = 6;
    frames[8].second = 3; // 9

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 8);
    CU_ASSERT_EQUAL(frames[1].total, 20); // 10 + next first (2)
    CU_ASSERT_EQUAL(frames[2].total, 25);
    CU_ASSERT_EQUAL(frames[3].total, 36); // 10 + next first (1)
    CU_ASSERT_EQUAL(frames[4].total, 38);
    CU_ASSERT_EQUAL(frames[5].total, 48); // 10 + next first (0)
    CU_ASSERT_EQUAL(frames[6].total, 48);
    CU_ASSERT_EQUAL(frames[7].total, 57);
    CU_ASSERT_EQUAL(frames[8].total, 66);
}

void test_alternating_strike_open(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    frames[1].first = 3;
    frames[1].second = 2; // 5
    frames[2].first = 10; // strike
    frames[3].first = 4;
    frames[3].second = 1; // 5
    frames[4].first = 10; // strike
    frames[5].first = 2;
    frames[5].second = 2; // 4
    frames[6].first = 6;
    frames[6].second = 0; // 6
    frames[7].first = 1;
    frames[7].second = 8; // 9
    frames[8].first = 5;
    frames[8].second = 3; // 8

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 15); // 10 + 3 + 2
    CU_ASSERT_EQUAL(frames[1].total, 20);
    CU_ASSERT_EQUAL(frames[2].total, 35); // 10 + 4 + 1
    CU_ASSERT_EQUAL(frames[3].total, 40);
    CU_ASSERT_EQUAL(frames[4].total, 54); // 10 + 2 + 2
    CU_ASSERT_EQUAL(frames[5].total, 58);
    CU_ASSERT_EQUAL(frames[6].total, 64);
    CU_ASSERT_EQUAL(frames[7].total, 73);
    CU_ASSERT_EQUAL(frames[8].total, 81);
}

void test_strike_spare_strike(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    frames[1].first = 6;
    frames[1].second = 4; // spare
    frames[2].first = 10; // strike
    frames[3].first = 3;
    frames[3].second = 5; // 8
    frames[4].first = 2;
    frames[4].second = 2; // 4
    frames[5].first = 0;
    frames[5].second = 6; // 6
    frames[6].first = 7;
    frames[6].second = 1; // 8
    frames[7].first = 8;
    frames[7].second = 0; // 8
    frames[8].first = 1;
    frames[8].second = 7; // 8

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 20); // 10 + 6 + 4
    CU_ASSERT_EQUAL(frames[1].total, 40); // 10 + next first (10)
    CU_ASSERT_EQUAL(frames[2].total, 58); // 10 + 3 + 5
    CU_ASSERT_EQUAL(frames[3].total, 66);
    CU_ASSERT_EQUAL(frames[4].total, 70);
    CU_ASSERT_EQUAL(frames[5].total, 76);
    CU_ASSERT_EQUAL(frames[6].total, 84);
    CU_ASSERT_EQUAL(frames[7].total, 92);
    CU_ASSERT_EQUAL(frames[8].total, 100);
}

void test_zeros_sprinkled(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 0;
    frames[0].second = 7; // 7
    frames[1].first = 0;
    frames[1].second = 3; // 3
    frames[2].first = 2;
    frames[2].second = 0; // 2
    frames[3].first = 0;
    frames[3].second = 0; // 0
    frames[4].first = 5;
    frames[4].second = 1; // 6
    frames[5].first = 4;
    frames[5].second = 0; // 4
    frames[6].first = 0;
    frames[6].second = 9; // 9
    frames[7].first = 3;
    frames[7].second = 0; // 3
    frames[8].first = 0;
    frames[8].second = 8; // 8

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 7);
    CU_ASSERT_EQUAL(frames[1].total, 10);
    CU_ASSERT_EQUAL(frames[2].total, 12);
    CU_ASSERT_EQUAL(frames[3].total, 12);
    CU_ASSERT_EQUAL(frames[4].total, 18);
    CU_ASSERT_EQUAL(frames[5].total, 22);
    CU_ASSERT_EQUAL(frames[6].total, 31);
    CU_ASSERT_EQUAL(frames[7].total, 34);
    CU_ASSERT_EQUAL(frames[8].total, 42);
}

void test_spare_open_spare_open(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 5;
    frames[0].second = 5; // spare
    frames[1].first = 3;
    frames[1].second = 4; // 7
    frames[2].first = 7;
    frames[2].second = 3; // spare
    frames[3].first = 2;
    frames[3].second = 1; // 3
    frames[4].first = 6;
    frames[4].second = 2; // 8
    frames[5].first = 0;
    frames[5].second = 5; // 5
    frames[6].first = 4;
    frames[6].second = 4; // 8
    frames[7].first = 1;
    frames[7].second = 8; // 9
    frames[8].first = 3;
    frames[8].second = 6; // 9

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 13); // 10 + next first (3)
    CU_ASSERT_EQUAL(frames[1].total, 20);
    CU_ASSERT_EQUAL(frames[2].total, 32); // 10 + next first (2)
    CU_ASSERT_EQUAL(frames[3].total, 35);
    CU_ASSERT_EQUAL(frames[4].total, 43);
    CU_ASSERT_EQUAL(frames[5].total, 48);
    CU_ASSERT_EQUAL(frames[6].total, 56);
    CU_ASSERT_EQUAL(frames[7].total, 65);
    CU_ASSERT_EQUAL(frames[8].total, 74);
}

void test_triple_open_then_strike(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 2;
    frames[0].second = 2; // 4
    frames[1].first = 1;
    frames[1].second = 1; // 2
    frames[2].first = 3;
    frames[2].second = 0; // 3
    frames[3].first = 10; // strike
    frames[4].first = 4;
    frames[4].second = 4; // 8
    frames[5].first = 2;
    frames[5].second = 2; // 4
    frames[6].first = 5;
    frames[6].second = 1; // 6
    frames[7].first = 0;
    frames[7].second = 3; // 3
    frames[8].first = 6;
    frames[8].second = 2; // 8

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 4);
    CU_ASSERT_EQUAL(frames[1].total, 6);
    CU_ASSERT_EQUAL(frames[2].total, 9);
    CU_ASSERT_EQUAL(frames[3].total, 27); // 10 + 4 + 4
    CU_ASSERT_EQUAL(frames[4].total, 35);
    CU_ASSERT_EQUAL(frames[5].total, 39);
    CU_ASSERT_EQUAL(frames[6].total, 45);
    CU_ASSERT_EQUAL(frames[7].total, 48);
    CU_ASSERT_EQUAL(frames[8].total, 56);
}

void test_back_to_back_spares_late(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 3;
    frames[0].second = 6; // 9
    frames[1].first = 2;
    frames[1].second = 2; // 4
    frames[2].first = 1;
    frames[2].second = 0; // 1
    frames[3].first = 4;
    frames[3].second = 3; // 7
    frames[4].first = 9;
    frames[4].second = 1; // spare
    frames[5].first = 6;
    frames[5].second = 4; // spare
    frames[6].first = 5;
    frames[6].second = 0; // 5
    frames[7].first = 2;
    frames[7].second = 2; // 4
    frames[8].first = 8;
    frames[8].second = 1; // 9

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 13);
    CU_ASSERT_EQUAL(frames[2].total, 14);
    CU_ASSERT_EQUAL(frames[3].total, 21);
    CU_ASSERT_EQUAL(frames[4].total, 37); // 10 + next first (6)
    CU_ASSERT_EQUAL(frames[5].total, 52); // 10 + next first (5)
    CU_ASSERT_EQUAL(frames[6].total, 57);
    CU_ASSERT_EQUAL(frames[7].total, 61);
    CU_ASSERT_EQUAL(frames[8].total, 70);
}

void test_zero_frame_before_strike(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 1;
    frames[0].second = 8; // 9
    frames[1].first = 0;
    frames[1].second = 0; // 0
    frames[2].first = 10; // strike
    frames[3].first = 2;
    frames[3].second = 6; // 8
    frames[4].first = 3;
    frames[4].second = 3; // 6
    frames[5].first = 4;
    frames[5].second = 1; // 5
    frames[6].first = 0;
    frames[6].second = 5; // 5
    frames[7].first = 7;
    frames[7].second = 2; // 9
    frames[8].first = 2;
    frames[8].second = 2; // 4

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 9);
    CU_ASSERT_EQUAL(frames[2].total, 27); // 10 + 2 + 6
    CU_ASSERT_EQUAL(frames[3].total, 35);
    CU_ASSERT_EQUAL(frames[4].total, 41);
    CU_ASSERT_EQUAL(frames[5].total, 46);
    CU_ASSERT_EQUAL(frames[6].total, 51);
    CU_ASSERT_EQUAL(frames[7].total, 60);
    CU_ASSERT_EQUAL(frames[8].total, 64);
}

void test_mixed_light(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 4;
    frames[0].second = 5; // 9
    frames[1].first = 7;
    frames[1].second = 3; // spare
    frames[2].first = 6;
    frames[2].second = 0; // 6
    frames[3].first = 10; // strike
    frames[4].first = 0;
    frames[4].second = 9; // 9
    frames[5].first = 5;
    frames[5].second = 4; // 9
    frames[6].first = 3;
    frames[6].second = 3; // 6
    frames[7].first = 2;
    frames[7].second = 7; // 9
    frames[8].first = 1;
    frames[8].second = 1; // 2

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    // Scores:
    // f0 = 9
    // f1 = 10 + next first (6) = 16 -> cum 25
    // f2 = 6 -> cum 31
    // f3 = 10 + next two (0,9) = 19 -> cum 50
    // f4 = 9 -> 59, f5 = 9 -> 68, f6 = 6 -> 74, f7 = 9 -> 83, f8 = 2 -> 85
    CU_ASSERT_EQUAL(frames[0].total, 9);
    CU_ASSERT_EQUAL(frames[1].total, 25);
    CU_ASSERT_EQUAL(frames[2].total, 31);
    CU_ASSERT_EQUAL(frames[3].total, 50);
    CU_ASSERT_EQUAL(frames[4].total, 59);
    CU_ASSERT_EQUAL(frames[5].total, 68);
    CU_ASSERT_EQUAL(frames[6].total, 74);
    CU_ASSERT_EQUAL(frames[7].total, 83);
    CU_ASSERT_EQUAL(frames[8].total, 85);
}

void test_mixed_heavy(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[0].first = 10; // strike
    frames[1].first = 9;
    frames[1].second = 1; // spare
    frames[2].first = 10; // strike
    frames[3].first = 6;
    frames[3].second = 2; // 8
    frames[4].first = 7;
    frames[4].second = 3; // spare
    frames[5].first = 0;
    frames[5].second = 0; // 0
    frames[6].first = 8;
    frames[6].second = 1; // 9
    frames[7].first = 5;
    frames[7].second = 4; // 9
    frames[8].first = 3;
    frames[8].second = 6; // 9

    for (int i = 0; i <= 8; ++i)
    {
        calc_score(frames, i);
        calc_score(frames, i);
    }

    // f0 = 10 + 9 + 1 = 20 -> cum 20
    // f1 = 10 + next first (10) = 20 -> 40
    // f2 = 10 + 6 + 2 = 18 -> 58
    // f3 = 8 -> 66
    // f4 = 10 + next first (0) = 10 -> 76
    // f5 = 0 -> 76
    // f6 = 9 -> 85
    // f7 = 9 -> 94
    // f8 = 9 -> 103
    CU_ASSERT_EQUAL(frames[0].total, 20);
    CU_ASSERT_EQUAL(frames[1].total, 40);
    CU_ASSERT_EQUAL(frames[2].total, 58);
    CU_ASSERT_EQUAL(frames[3].total, 66);
    CU_ASSERT_EQUAL(frames[4].total, 76);
    CU_ASSERT_EQUAL(frames[5].total, 76);
    CU_ASSERT_EQUAL(frames[6].total, 85);
    CU_ASSERT_EQUAL(frames[7].total, 94);
    CU_ASSERT_EQUAL(frames[8].total, 103);
}

/* --- 10th --- */
void test_tenth_frame_normal(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[9].first = 4;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 4);

    frames[9].second = 5;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 9); // 4 + 5

    // no third roll
}

void test_tenth_frame_spare(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[9].first = 7;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 7);

    frames[9].second = 3; // spare
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 10); // 7 + 3

    frames[9].third = 5;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 15); // 7 + 3 + 5
}

void test_tenth_frame_strike(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[9].first = 10; // strike
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 10);

    frames[9].second = 10;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 20); // 10 + 10

    frames[9].third = 10;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 30); // 10 + 10 + 10
}

void test_tenth_frame_strike_then_normal(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[9].first = 10; // strike
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 10);

    frames[9].second = 3;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 13); // 10 + 3

    frames[9].third = 6;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 19); // 10 + 3 + 6
}

void test_tenth_frame_spare_then_strike(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[9].first = 4;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 4);

    frames[9].second = 6; // spare
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 10); // 4 + 6

    frames[9].third = 10; // strike
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 20); // 4 + 6 + 10
}

void test_tenth_frame_strike_then_spare(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[9].first = 10; // strike
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 10);

    frames[9].second = 7;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 17); // 10 + 7

    frames[9].third = 3; // spare
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 20); // 10 + 7 + 3
}

/* --- 9 and 10th --- */

void test_ninth_and_tenth_open(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[8].first = 3;
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 3);
    frames[8].second = 5; // 8
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 8);

    frames[9].first = 4;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 12); // 8 + 4
    frames[9].second = 4;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 16); // 12 + 4
}

void test_ninth_and_tenth_spare(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[8].first = 6;
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 6);

    frames[8].second = 4; // spare
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 10);

    frames[9].first = 3;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 16); // 10 + 3 + 3

    frames[9].second = 7; // spare
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 23); // 16 + 7

    frames[9].third = 5;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[9].total, 28); // 23 + 5
}

void test_ninth_and_tenth_strike(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[8].first = 10; // strike
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 10);

    frames[9].first = 10; // strike
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 20);
    CU_ASSERT_EQUAL(frames[9].total, 30);

    frames[9].second = 10; // strike
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 30);
    CU_ASSERT_EQUAL(frames[9].total, 50);

    frames[9].third = 10; // strike
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 30);
    CU_ASSERT_EQUAL(frames[9].total, 60);
}

void test_ninth_strike_tenth_spare(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[8].first = 10; // strike
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 10);

    frames[9].first = 7;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 17); // 10 + 7
    CU_ASSERT_EQUAL(frames[9].total, 24); // 17 + 7

    frames[9].second = 3; // spare
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 20); // 17 + 3
    CU_ASSERT_EQUAL(frames[9].total, 30); // 20 + 7 + 3

    frames[9].third = 5;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 20);
    CU_ASSERT_EQUAL(frames[9].total, 35); // 30 + 5
}

void test_ninth_spare_tenth_strike(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[8].first = 6;
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 6);

    frames[8].second = 4; // spare
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 10);

    frames[9].first = 10; // strike
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 20);
    CU_ASSERT_EQUAL(frames[9].total, 30); // 20 + 10

    frames[9].second = 10; // strike
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 20);
    CU_ASSERT_EQUAL(frames[9].total, 40); // 30 + 10
}

void test_ninth_strike_tenth_normal(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[8].first = 10; // strike
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 10);

    frames[9].first = 3;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 13); // 10 + 3
    CU_ASSERT_EQUAL(frames[9].total, 16); // 13 + 3

    frames[9].second = 6; // normal
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 19); // 13 + 6
    CU_ASSERT_EQUAL(frames[9].total, 28); // 19 + 3 + 6
}

void test_ninth_spare_tenth_normal(void)
{
    frame_t frames[NFRAMES] = {0};

    frames[8].first = 6;
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 6);

    frames[8].second = 4; // spare
    calc_score(frames, 8);
    CU_ASSERT_EQUAL(frames[8].total, 10);

    frames[9].first = 3;
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 13); // 10 + 3
    CU_ASSERT_EQUAL(frames[9].total, 16); // 13 + 3

    frames[9].second = 6; // normal
    calc_score(frames, 9);
    CU_ASSERT_EQUAL(frames[8].total, 13); // unchanged
    CU_ASSERT_EQUAL(frames[9].total, 22); // 16 + 6
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
    CU_pSuite pSuite1, pSuite2, pSuite3, pSuite4, pSuite5, pSuite6;
    if (NULL == (pSuite1 = CU_add_suite("Normal frames i.e. less then spare and strike", 0, 0)) ||
        NULL == (pSuite2 = CU_add_suite("Spare bonus frames", 0, 0)) ||
        NULL == (pSuite3 = CU_add_suite("Strike bonus frames", 0, 0)) ||
        NULL == (pSuite4 = CU_add_suite("Mixed frames", 0, 0)) ||
        NULL == (pSuite5 = CU_add_suite("10th frame", 0, 0)) ||
        NULL == (pSuite6 = CU_add_suite("9 and 10th frames", 0, 0)))
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
        puts("CU_add_test to 'Strike bonus frames' suite");
        puts(CU_get_error_msg());
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add a tests to the suite */
    if (NULL == CU_add_test(pSuite4, "test_open_frames_all", test_open_frames_all) ||
        NULL == CU_add_test(pSuite4, "test_single_spare_at_3", test_single_spare_at_3) ||
        NULL == CU_add_test(pSuite4, "test_single_strike_at_2", test_single_strike_at_2) ||
        NULL == CU_add_test(pSuite4, "test_strike_then_spare", test_strike_then_spare) ||
        NULL == CU_add_test(pSuite4, "test_spare_then_strike", test_spare_then_strike) ||
        NULL == CU_add_test(pSuite4, "test_double_strike_then_open", test_double_strike_then_open) ||
        NULL == CU_add_test(pSuite4, "test_two_spares_row_mid", test_two_spares_row_mid) ||
        NULL == CU_add_test(pSuite4, "test_alternating_open_spare", test_alternating_open_spare) ||
        NULL == CU_add_test(pSuite4, "test_alternating_strike_open", test_alternating_strike_open) ||
        NULL == CU_add_test(pSuite4, "test_strike_spare_strike", test_strike_spare_strike) ||
        NULL == CU_add_test(pSuite4, "test_zeros_sprinkled", test_zeros_sprinkled) ||
        NULL == CU_add_test(pSuite4, "test_spare_open_spare_open", test_spare_open_spare_open) ||
        NULL == CU_add_test(pSuite4, "test_triple_open_then_strike", test_triple_open_then_strike) ||
        NULL == CU_add_test(pSuite4, "test_back_to_back_spares_late", test_back_to_back_spares_late) ||
        NULL == CU_add_test(pSuite4, "test_zero_frame_before_strike", test_zero_frame_before_strike) ||
        NULL == CU_add_test(pSuite4, "test_mixed_light", test_mixed_light) ||
        NULL == CU_add_test(pSuite4, "test_mixed_heavy", test_mixed_heavy))
    {
        puts("CU_add_test to 'Mixed frames");
        puts(CU_get_error_msg());
        CU_cleanup_registry();
        return CU_get_error();
    }
    /* add a tests to the suite */
    if (NULL == CU_add_test(pSuite5, "tenth frame normal", test_tenth_frame_normal) ||
        NULL == CU_add_test(pSuite5, "tenth frame spare", test_tenth_frame_spare) ||
        NULL == CU_add_test(pSuite5, "tenth frame strike", test_tenth_frame_strike) ||
        NULL == CU_add_test(pSuite5, "tenth frame strike then normal", test_tenth_frame_strike_then_normal) ||
        NULL == CU_add_test(pSuite5, "tenth frame spare then strike", test_tenth_frame_spare_then_strike) ||
        NULL == CU_add_test(pSuite5, "tenth frame strike then spare", test_tenth_frame_strike_then_spare))
    {
        puts("CU_add_test to '10th frame' suite");
        puts(CU_get_error_msg());
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add a tests to the suite */
    if (NULL == CU_add_test(pSuite6, "ninth and tenth open", test_ninth_and_tenth_open) ||
        NULL == CU_add_test(pSuite6, "ninth and tenth spare", test_ninth_and_tenth_spare) ||
        NULL == CU_add_test(pSuite6, "ninth and tenth strike", test_ninth_and_tenth_strike) ||
        NULL == CU_add_test(pSuite6, "ninth strike tenth spare", test_ninth_strike_tenth_spare) ||
        NULL == CU_add_test(pSuite6, "ninth spare tenth strike", test_ninth_spare_tenth_strike) ||
        NULL == CU_add_test(pSuite6, "ninth strike tenth normal", test_ninth_strike_tenth_normal) ||
        NULL == CU_add_test(pSuite6, "ninth spare tenth normal", test_ninth_spare_tenth_normal))
    {
        puts("CU_add_test to '9 and 10th frames' suite");
        puts(CU_get_error_msg());
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();
    return CU_get_error();
}
