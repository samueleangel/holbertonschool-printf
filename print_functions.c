#include "main.h"

/**
 * print_char - Prints a character
 * @args: va_list containing character to print
 * Return: Number of characters printed or -1 on error
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return write(1, &c, 1);
}

/**
 * print_string - Prints a string
 * @args: va_list containing string to print
 * Return: Number of characters printed or -1 on error
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";
	
	while (*str)
    	{
        if (write(1, str++, 1) == -1)
            return (-1);
        count++;
    }
    return (count);
}

/**
 * print_percent - Prints a percent sign
 * @args: va_list (unused)
 * Return: Number of characters printed or -1 on error
 */
int print_percent(va_list args)
{
    return write(1, "%", 1);
}
