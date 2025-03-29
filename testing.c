#include "main.h"
#include <stdio.h>


/**
 * _printf - produces output according to a format
 * @format: format string containing the directives
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                break;

            switch (format[i])
            {
                case 'c':
                    count += print_char(args);
                    break;
                case 's':
                    count += print_string(args);
                    break;
                case '%':
                    count += print_percent(args);
                    break;
                default:
                    write(1, &format[i - 1], 1);
                    write(1, &format[i], 1);
                    count += 2;
                    break;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}


/**
 * print_char - prints a character
 * @args: va_list containing the character to print
 *
 * Return: number of characters printed (always 1)
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    return (1);
}

/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        write(1, str, 1);
        str++;
        count++;
    }

    return (count);
}

/**
 * print_percent - prints a percent sign
 * @args: va_list (unused)
 *
 * Return: number of characters printed (always 1)
 */
int print_percent(va_list args)
{
    (void)args;
    write(1, "%", 1);
    return (1);
}

int main(void)
{
    int len, len2;

    len = _printf("Let's print a char: %c\n", 'A');
    len2 = printf("Let's print a char: %c\n", 'A');
    _printf("Length: [%d, %d]\n", len, len2);

    len = _printf("String:[%s]\n", "Hello, World!");
    len2 = printf("String:[%s]\n", "Hello, World!");
    _printf("Length: [%d, %d]\n", len, len2);

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Length: [%d, %d]\n", len, len2);

    return (0);
}
