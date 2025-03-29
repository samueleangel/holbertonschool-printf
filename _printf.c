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
    
    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                break;
            count += handle_specifier(format[i], args);
        }
        else
        {
            count += print_char(format[i]);
        }
        i++;
    }

    va_end(args);
    return (count);
}
