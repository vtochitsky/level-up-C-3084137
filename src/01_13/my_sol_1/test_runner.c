#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "calc_frames.h"

void test_normal_frame(void)
{
    frame_t frames[NFRAMES] = {0};
    frames[0].first = 3;
    frames[0].second = 4;

    calc_frame_table(frames, NFRAMES, 0);

    CU_ASSERT_EQUAL(frames[0].total, 7);
}

void test_spare_bonus(void)
{
    frame_t frames[NFRAMES] = {0};
    frames[0].first = 5;
    frames[0].second = 5; // spare
    frames[1].first = 4;
    frames[1].second = 2;

    calc_frame_table(frames, NFRAMES, 0);
    calc_frame_table(frames, NFRAMES, 1);

    CU_ASSERT_EQUAL(frames[0].total, 14); // 10 + 4
    CU_ASSERT_EQUAL(frames[1].total, 20); // 4 + 2 + 14
}

void test_strike_bonus(void)
{
    frame_t frames[NFRAMES] = {0};
    frames[0].first = 10; // strike
    frames[1].first = 3;
    frames[1].second = 6;

    calc_frame_table(frames, NFRAMES, 0);
    calc_frame_table(frames, NFRAMES, 1);

    CU_ASSERT_EQUAL(frames[0].total, 19); // 10 + 3 + 6
    CU_ASSERT_EQUAL(frames[1].total, 28); // 3 + 6 + 19
}

void test_double_strike_bonus(void)
{
    frame_t frames[NFRAMES] = {0};
    frames[0].first = 10; // strike
    frames[1].first = 10; // strike
    frames[2].first = 4;
    frames[2].second = 3;

    calc_frame_table(frames, NFRAMES, 0);
    calc_frame_table(frames, NFRAMES, 1);
    calc_frame_table(frames, NFRAMES, 2);

    CU_ASSERT_EQUAL(frames[0].total, 24); // 10 + 10 + 4
    CU_ASSERT_EQUAL(frames[1].total, 41); // 10 + 4 + 3 + 24
    CU_ASSERT_EQUAL(frames[2].total, 48); // 4 + 3 + 41
}

void test_tenth_frame_spare(void)
{
    frame_t frames[NFRAMES] = {0};
    frames[9].first = 7;
    frames[9].second = 3; // spare
    frames[9].third = 5;

    calc_frame_table(frames, NFRAMES, 9);

    CU_ASSERT_EQUAL(frames[9].total, 15); // 7 + 3 + 5
}

void test_tenth_frame_strike(void)
{
    frame_t frames[NFRAMES] = {0};
    frames[9].first = 10; // strike
    frames[9].second = 10;
    frames[9].third = 10;

    calc_frame_table(frames, NFRAMES, 9);

    CU_ASSERT_EQUAL(frames[9].total, 30); // 10 + 10 + 10
}

/* Edge Case Tests */
void test_invalid_frame_index(void)
{
    frame_t frames[NFRAMES] = {0};
    frames[0].first = 4;
    frames[0].second = 5;

    // Negative index
    calc_frame_table(frames, NFRAMES, -1);
    // Index beyond NFRAMES
    calc_frame_table(frames, NFRAMES, NFRAMES + 1);

    // Should not crash or modify frames
    CU_ASSERT_EQUAL(frames[0].total, 0);
}

void test_null_frame_pointer(void)
{
    calc_frame_table(NULL, NFRAMES, 0);
    // Should not crash — no assertion possible, just safety
}

void test_maximum_pin_values(void)
{
    frame_t frames[NFRAMES] = {0};
    frames[0].first = 10;
    frames[1].first = 10;
    frames[2].first = 10;

    calc_frame_table(frames, NFRAMES, 0);
    calc_frame_table(frames, NFRAMES, 1);
    calc_frame_table(frames, NFRAMES, 2);

    CU_ASSERT_EQUAL(frames[0].total, 30);
    CU_ASSERT_EQUAL(frames[1].total, 50);
    CU_ASSERT_EQUAL(frames[2].total, 60);
}

/* Randomized Frame Sequence */
#include <stdlib.h>
#include <time.h>

void test_random_game_sequence(void)
{
    frame_t frames[NFRAMES] = {0};
    srand((unsigned int)time(NULL));

    for (int i = 0; i < NFRAMES - 1; ++i)
    {
        frames[i].first = rand() % 11;
        frames[i].second = (frames[i].first == 10) ? 0 : rand() % (11 - frames[i].first);
        calc_frame_table(frames, NFRAMES, i);
    }

    // 10th frame: allow third ball if strike or spare
    frames[9].first = rand() % 11;
    frames[9].second = (frames[9].first == 10) ? rand() % 11 : rand() % (11 - frames[9].first);
    frames[9].third = (frames[9].first + frames[9].second >= 10) ? rand() % 11 : 0;
    calc_frame_table(frames, NFRAMES, 9);

    // Just verify total is non-negative and increasing
    for (int i = 0; i < NFRAMES; ++i)
    {
        CU_ASSERT(frames[i].total >= 0);
        if (i > 0)
            CU_ASSERT(frames[i].total >= frames[i - 1].total);
    }
}

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("calc_frame_table_tests", 0, 0);

    CU_add_test(suite, "Normal frame", test_normal_frame);
    CU_add_test(suite, "Spare bonus", test_spare_bonus);
    CU_add_test(suite, "Strike bonus", test_strike_bonus);
    CU_add_test(suite, "Double strike bonus", test_double_strike_bonus);
    CU_add_test(suite, "10th frame spare", test_tenth_frame_spare);
    CU_add_test(suite, "10th frame strike", test_tenth_frame_strike);

    // CU_add_test(suite, "Edge Case Test: invalid frame index", test_invalid_frame_index);
    // CU_add_test(suite, "Edge Case Test: null frame pointer", test_null_frame_pointer);
    CU_add_test(suite, "Edge Case Test: maximum pin values", test_maximum_pin_values);

    CU_add_test(suite, "Randomized Frame Sequence", test_random_game_sequence);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
