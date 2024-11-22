#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <format> [arguments...]\n", argv[0]);
        return 1;
    }

    char *format = argv[1];
    int i;
    int arg_index = 2;

    for (i = 0; format[i]; i++) {
        if (format[i] == '%' && format[i + 1]) {
            char specifier = format[i + 1];

            switch (specifier) {
                case 'd':
                case 'i': {
                    if (arg_index >= argc) {
                        fprintf(stderr, "Error: Missing integer argument for specifier %%%c\n", specifier);
                        return 1;
                    }
                    long long num = atoll(argv[arg_index++]);

                    if (num > INT_MAX) {
                        ft_printf("Overflow: %lld", num);
                    } else {
                        ft_printf("%d", (int)num);
                    }
                    break;
                }
                case 'u':
                case 'x':
                case 'X': {
                    if (arg_index >= argc) {
                        fprintf(stderr, "Error: Missing unsigned integer argument for specifier %%%c\n", specifier);
                        return 1;
                    }
                    unsigned long long unum = atoll(argv[arg_index++]);

                    if (specifier == 'u') {
                        ft_printf("%llu", unum);
                    } else if (specifier == 'x') {
                        ft_printf("%llx", unum);
                    } else {
                        ft_printf("%llX", unum);
                    }
                    break;
                }
                case 'c': {
                    if (arg_index >= argc) {
                        fprintf(stderr, "Error: Missing character argument for specifier %%c\n");
                        return 1;
                    }
                    char ch = argv[arg_index++][0];
                    ft_printf("%c", ch);
                    break;
                }
                case 's': {
                    if (arg_index >= argc) {
                        ft_printf("(null)");
                    } else {
                        char *str = argv[arg_index++];
                        if (str == NULL) {
                            ft_printf("(null)");
                        } else {
                            ft_printf("%s", str);
                        }
                    }
                    break;
                }
                case 'p': {
                    if (arg_index >= argc) {
                        fprintf(stderr, "Error: Missing pointer argument for specifier %%p\n");
                        return 1;
                    }
                    void *ptr = (void *)strtol(argv[arg_index++], NULL, 16);
                    ft_printf("%p", ptr);
                    break;
                }
                case '%': {
                    ft_printf("%%");
                    break;
                }
                default: {
                    fprintf(stderr, "Error: Unsupported format specifier %%%c\n", specifier);
                    return 1;
                }
            }

            i++;
        } else {
            ft_printf("%c", format[i]);
        }
    }

    return 0;
}
