/**
 * @file test_public_api.c
 * @brief Example Unity test for the public API.
 * @date 2025-11-09
 * @version 1.0
 */

#include "unity.h"
#include "main.h"

void setUp(void) {}
void tearDown(void) {}

void test_internal_process(void) {
    int result = internal_process(3);
    TEST_ASSERT_EQUAL_INT(3, result);
}

void test_system_aggregate(void) {
    /* internal_process(3) = 3
       Each module returns input + offset (1..8)
       Sum = internal + sum(modules) = 9*input + 36
       For input 3 => 63
    */
    int result = system_aggregate(3);
    TEST_ASSERT_EQUAL_INT(63, result);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_internal_process);
    RUN_TEST(test_system_aggregate);

    return UNITY_END();
}
