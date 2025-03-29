#include "main.h"

/**
 * _printf - produces output according to a format.
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
            if (!format[i]) /* Handle single % at end */
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
