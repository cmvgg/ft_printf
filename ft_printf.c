/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvarela- <cvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:47:06 by cvarela-          #+#    #+#             */
/*   Updated: 2023/10/21 02:06:27 by cvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct t_OutputBuffer
{
    char *output;
    size_t size;
    size_t length;
} t_OutputBuffer;

void initialize_output_buffer(t_OutputBuffer *buffer, size_t initial_size)
{
    buffer->size = initial_size;
    buffer->output = (char *)malloc(buffer->size);
    buffer->output[0] = '\0';
    buffer->length = 0;
}

void free_output_buffer(t_OutputBuffer *buffer)
{
    free(buffer->output);
    buffer->output = NULL;
}

void append_to_output_buffer(t_OutputBuffer *buffer, const char *str)
{
    size_t str_len = strlen(str);
    size_t curr_len = buffer->length;

    if (curr_len + str_len + 1 > buffer->size)
    {
        buffer->size *= 2;
        buffer->output = (char *)realloc(buffer->output, buffer->size);
    }

    strncat(buffer->output, str, str_len);
    buffer->length += str_len;
}

void print_char(t_OutputBuffer *output, char c)
{
    char str[2] = {c, '\0'};
    append_to_output_buffer(output, str);
}

void print_str(t_OutputBuffer *output, const char *str)
{
    if (str == NULL)
        append_to_output_buffer(output, "(null)");
    else
        append_to_output_buffer(output, str);
}

void print_int(t_OutputBuffer *output, int num)
{
    char num_str[20];
    int i = 0;

    if (num < 0)
    {
        num_str[i++] = '-';
        num = -num;
    }

    while (num)
    {
        num_str[i++] = (num % 10) + '0';
        num /= 10;
    }

    append_to_output_buffer(output, num_str);
}

void print_hex(t_OutputBuffer *output, unsigned long long num, int uppercase)
{
    char num_str[20];
    int i = 0;

    if (num < 0)
    {
        num_str[i++] = '-';
        num = -num;
    }

    while (num)
    {
        if (num % 16 < 10)
            num_str[i++] = (num % 16) + '0';
        else
        {
            if (uppercase)
                num_str[i++] = (num % 16) + 'A' - 10;
            else
                num_str[i++] = (num % 16) + 'a' - 10;
        }
        num /= 16;
    }

    append_to_output_buffer(output, num_str);
}

void print_output(t_OutputBuffer *output)
{
    write(1, output->output, output->length);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    t_OutputBuffer output;
    const char *ptr;
    char specifier;
    char *str;
    int num;

    char c;
    unsigned long long ull_num;

    va_start(args, format);
    initialize_output_buffer(&output, 10);
    ptr = format;

    // Verificar si la cadena de formato está vacía
    if (format[0] == '\0')
    {
        va_end(args);
        free_output_buffer(&output); // Liberar la memoria antes de salir
        return 0; // No hay nada que imprimir
    }

    while (*ptr != '\0')
    {
        if (*ptr == '%')
        {
            ptr++;
            specifier = *ptr;

            if (specifier == 'c')
            {
                c = (char)va_arg(args, int);
                print_char(&output, c);
            }
            else if (specifier == 's')
            {
                str = va_arg(args, char *);
                print_str(&output, str);
            }
            else if (specifier == 'd' || specifier == 'i')
            {
                num = va_arg(args, int);
                print_int(&output, num);
            }
            else if (specifier == 'x' || specifier == 'X')
            {
                ull_num = va_arg(args, unsigned long long);
                print_hex(&output, ull_num, specifier == 'X');
            }
            else
            {
                print_char(&output, '%');
                print_char(&output, specifier);
            }
        }
        else
        {
            print_char(&output, *ptr);
        }

        ptr++;
    }

    va_end(args);

    print_output(&output);
    free_output_buffer(&output); // Liberar la memoria antes de salir

    return output.length;
}


/*
int main(void)
{
    ft_printf("\r");
    printf("\nft\n");
    printf("\r");
    return 0;
}*/

