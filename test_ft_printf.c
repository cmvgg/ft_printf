#include "ft_printf.h"
#include "unity.h"
#include <stdio.h>

void setUp(void) {
}

void tearDown(void) {
}

void test_ft_putchar(void) {
    int result;

    result = ft_putchar('A');
    TEST_ASSERT_EQUAL_INT(1, result);
}

void test_ft_putnbr(void) {
    int result;

    result = ft_putnbr(1234);
    TEST_ASSERT_EQUAL_INT(4, result);

    result = ft_putnbr(-5678);
    TEST_ASSERT_EQUAL_INT(5, result);

    result = ft_putnbr(-2147483648);
    TEST_ASSERT_EQUAL_INT(11, result);
}

void test_ft_putstr(void) {
    int result;

    result = ft_putstr("Hello");
    TEST_ASSERT_EQUAL_INT(5, result);

    result = ft_putstr(NULL);
    TEST_ASSERT_EQUAL_INT(6, result);
}

void test_ft_hexa(void) {
    int result;

    result = ft_hexa(255, 1);
    TEST_ASSERT_EQUAL_INT(2, result);

    result = ft_hexa(255, 2);
    TEST_ASSERT_EQUAL_INT(2, result);

    result = ft_hexa(0, 1);
    TEST_ASSERT_EQUAL_INT(1, result);
}

void test_ft_hexa_pointer(void) {
    int result;

    result = ft_hexa_pointer(12345678);
    TEST_ASSERT_EQUAL_INT(8, result);
}

void test_ft_percent(void) {
    int result;

    result = ft_percent('%', NULL);
    TEST_ASSERT_EQUAL_INT(1, result);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ft_putchar);
    RUN_TEST(test_ft_putnbr);
    RUN_TEST(test_ft_putstr);
    RUN_TEST(test_ft_hexa);
    RUN_TEST(test_ft_hexa_pointer);
    RUN_TEST(test_ft_percent);


    RUN_TEST(test_ft_printf_basic_formats);
    RUN_TEST(test_ft_printf_with_null);
    RUN_TEST(test_ft_printf_multiple_formats);
    RUN_TEST(test_ft_printf_edge_cases);


    RUN_TEST(test_large_string);
    RUN_TEST(test_large_number);
    RUN_TEST(test_multiple_calls);
    RUN_TEST(test_large_hexadecimal);
	RUN_TEST(test_empty_string);
	RUN_TEST(test_performance);
	return UNITY_END();
}