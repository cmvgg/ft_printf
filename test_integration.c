#include "ft_printf.h"


void test_ft_printf_basic_formats(void) {
    int result;

    result = ft_printf("Hello");
    TEST_ASSERT_EQUAL_INT(5, result);

    result = ft_printf("%d", 1234);
    TEST_ASSERT_EQUAL_INT(4, result);

    result = ft_printf("%d", -5678);
    TEST_ASSERT_EQUAL_INT(5, result);

    result = ft_printf("%x", 255);
    TEST_ASSERT_EQUAL_INT(2, result);

    result = ft_printf("%p", (void *)12345678);
    TEST_ASSERT_EQUAL_INT(8, result);
}

void test_ft_printf_with_null(void) {
    int result;

    result = ft_printf("%s", NULL);
    TEST_ASSERT_EQUAL_INT(6, result);
}

void test_ft_printf_multiple_formats(void) {
    int result;

    result = ft_printf("Int: %d, Str: %s, Hex: %x, Ptr: %p", 1234, "Test", 255, (void *)12345678);
    TEST_ASSERT_EQUAL_INT(44, result);
}

void test_ft_printf_edge_cases(void) {
    int result;

    result = ft_printf("%%");
    TEST_ASSERT_EQUAL_INT(1, result);

    result = ft_printf("%d", 0);
    TEST_ASSERT_EQUAL_INT(1, result);

    result = ft_printf("%d", 2147483647);
    TEST_ASSERT_EQUAL_INT(10, result);
}
