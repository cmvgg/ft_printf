#include "ft_printf.h"

void test_large_string() {
    char str[100000];
    memset(str, 'A', sizeof(str) - 1);
    str[sizeof(str) - 1] = '\0';

    int saved_stdout = redirect_stdout_to_file("exits/test_large_string.txt");
    if (saved_stdout == -1) {
        perror("Error al redirigir la salida");
        return;
    }

    ft_printf("Testing with a large string: %s\n", str);

    restore_stdout(saved_stdout);
    log_result("test_large_string", "Output saved to test_large_string.txt");
}

void test_large_number() {
    int large_num = 2147483647;
    int small_num = -2147483648;

	int saved_stdout = redirect_stdout_to_file("exits/test_large_number.txt");
    if (saved_stdout == -1) {
        perror("Error al redirigir la salida");
        return;
    }


    ft_printf("Testing with large numbers: %d, %d\n", large_num, small_num);

	restore_stdout(saved_stdout);
    log_result("test_large_number", "Output saved to test_large_number.txt");
}

void test_multiple_calls() {
	int saved_stdout = redirect_stdout_to_file("exits/test_multiple_calls.txt");
    if (saved_stdout == -1) {
        perror("Error al redirigir la salida");
        return;
    }

    for (int i = 0; i < 100000; i++) {
        ft_printf("Test %d: %s\n", i, "Test String");
    }

	restore_stdout(saved_stdout);
    log_result("test_multiple_calls", "Output saved to test_multiple_calls.txt");
}

void test_large_hexadecimal() {
	int saved_stdout = redirect_stdout_to_file("exits/test_large_hexadecimal.txt");
    if (saved_stdout == -1) {
        perror("Error al redirigir la salida");
        return;
    }

    unsigned long large_number = 0xFFFFFFFFFFFF;

    ft_printf("Testing with a large hexadecimal number: %p\n", large_number);
    ft_printf("Testing with a large hexadecimal number (uppercase): %X\n", large_number);

	restore_stdout(saved_stdout);
    log_result("test_large_hexadecimal", "Output saved to test_large_hexadecimal.txt");
}

void test_empty_string() {
	int saved_stdout = redirect_stdout_to_file("exits/test_empty_string.txt");
    if (saved_stdout == -1) {
        perror("Error al redirigir la salida");
        return;
    }

    char *empty_str = "";
    char *null_str = NULL;

    ft_printf("Testing with an empty string: %s\n", empty_str);
    ft_printf("Testing with a null pointer: %s\n", null_str);

	restore_stdout(saved_stdout);
    log_result("test_empty_string", "Output saved to test_empty_string.txt");
}

void test_performance() {
	int saved_stdout = redirect_stdout_to_file("exits/test_performance.txt");
    if (saved_stdout == -1) {
        perror("Error al redirigir la salida");
        return;
    }
    clock_t start_time, end_time;
    double time_taken;

    start_time = clock();
    test_large_string();
    end_time = clock();

    time_taken = ((double)end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken for performance test: %f seconds\n", time_taken);

	restore_stdout(saved_stdout);
    log_result("test_performance", "Output saved to test_performance.txt");
}