#include "unity.h"

void assert_one_plus_one_equal_two()
{
  int a = 1; int b = 1;

  int r = a + b;

  TEST_ASSERT_EQUAL_CHAR(2, r);
}

int main( int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(assert_one_plus_one_equal_two);
    UNITY_END();
}