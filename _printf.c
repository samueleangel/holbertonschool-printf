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
    int ret_val = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                break;

            switch (format[i])
            {
                case 'c':
                    ret_val = print_char(args);
                    break;
                case 's':
                    ret_val = print_string(args);
                    break;
                case '%':
                    ret_val = print_percent(args);
                    break;
                default:
                    ret_val = write(1, &format[i - 1], 1);
                    ret_val += write(1, &format[i], 1);
                    break;
            }

            if (ret_val == -1)
                return (-1);
            
            count += ret_val;
        }
        else
        {
            ret_val = write(1, &format[i], 1);
            if (ret_val == -1)
                return (-1);
            count += ret_val;
        }
        i++;
    }

    va_end(args);
    return (count);	
}
