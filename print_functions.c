#include "main.h"

/**
 * handle_specifier - Handles format specifiers
 * @spec: Specifier character
 * @args: Argument list
 * Return: Number of chars printed
 */
int handle_specifier(const char spec, va_list args)
{
    switch (spec)
    {
        case 'c':
            return print_char(va_arg(args, int));
        case 's':
            return print_str(va_arg(args, char *));
        case '%':
            return print_char('%');
        default:
            return (print_char('%') + print_char(spec));
    }
}

/**
 * print_char - Prints a single character
 * @c: Character to print
 * Return: Always 1 (success)
 */
int print_char(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_str - Prints a string
 * @str: String to print
 * Return: Number of chars printed
 */
int print_str(char *str)
{
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str != '\0')
    {
        count += print_char(*str);
        str++;
    }

    return (count);
}
