/*
** EPITECH PROJECT, 2023
** Mini_printf
** File description:
** Write a function that print the string
** in parameter with some % options
*/
#include <stdarg.h>
#include <unistd.h>
#include "my.h"

static int add_value_and_return(int *i)
{
    *i += 1;
    return 0;
}

static int test_format(const char *format, int *i,
    int *count_letter, va_list args)
{
    if (format[*i + 1] == 'd' || format[*i + 1] == 'i') {
        *count_letter += my_put_nbr(va_arg(args, int));
        return add_value_and_return(i);
    }
    if (format[*i + 1] == 's') {
        *count_letter += my_putstr(va_arg(args, char *));
        return add_value_and_return(i);
    }
    if (format[*i + 1] == 'c') {
        my_putchar(va_arg(args, int));
        *count_letter += 1;
        return add_value_and_return(i);
    }
    if (format[*i + 1] == '%') {
        my_putchar('%');
        *count_letter += 1;
        return add_value_and_return(i);
    }
    return -1;
}

static int test_pourcent_and_pos(const char *format, int *i,
    int *count_letter, va_list args)
{
    if (format[*i] == '%') {
        if (*i < (my_strlen(format) - 1)) {
            return test_format(format, i, count_letter, args);
        }
    } else {
        write(1, &format[*i], 1);
        *count_letter += 1;
    }
    return 0;
}

static int errors_gestion(const char *format)
{
    if (format[my_strlen(format) - 1] == '%' &&
        format[my_strlen(format) - 2] != '%') {
        return -1;
    }
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count_letter = 0;

    va_start(args, format);
    if (errors_gestion(format) == -1) {
        return -1;
    }
    while (format[i] != '\0') {
        if (test_pourcent_and_pos(format, &i, &count_letter, args) == -1) {
            return -1;
        }
        i++;
    }
    va_end(args);
    return count_letter;
}
