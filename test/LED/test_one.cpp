#include <unity.h>
#include "LED.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_sets_button_to_up()
{
    estadoBotao(btDOWN);
    TEST_ASSERT_TRUE_MESSAGE((estadoBotaoAnt == btUP), "Deu muito ruim, barco decolou pra nárnia");
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_sets_button_to_up);
    UNITY_END();
}