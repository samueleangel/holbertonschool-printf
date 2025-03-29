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
    int count = 0;
    int i = 0;
    int ret = 0;

    if (!format)
        return -1;

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    ret = print_char(args);
                    break;
                case 's':
                    ret = print_string(args);
                    break;
                case '%':
                    ret = print_percent(args);
                    break;
                default:
                    ret = write(1, &format[i - 1], 1);
                    ret += write(1, &format[i], 1);
                    break;
            }
            i++;
        }
        else
        {
            ret = write(1, &format[i], 1);
            i++;
        }

        if (ret == -1)
            return -1;
        count += ret;
    }

    va_end(args);
    return count;
}
