#include "main.h"


/**
 * handle_specifier - Handles format specifiers
 * @specifier: The format specifier
 * @args: Argument list
 * Return: Number of characters printed
 */
int handle_specifier(char specifier, va_list args)
{
    switch (specifier)
    {
        case 'c':
            return print_char(va_arg(args, int));
        case 's':
            return print_string(va_arg(args, char *));
        case 'd':
        case 'i':
            return print_number(va_arg(args, int));
        case '%':
            return print_char('%');
        default:
            return (print_char('%') + print_char(specifier));
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
 * print_string - Prints a string
 * @str: String to print
 * Return: Number of characters printed
 */
int print_string(char *str)
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

/**
 * print_number - Prints an integer
 * @n: The integer to print
 * Return: Number of characters printed
 */
int print_number(int n)
{
 int count = 0;
    unsigned int num;
    
    /* Special case for INT_MIN */
    if (n == INT_MIN)
    {
        count += print_char('-');
        count += print_char('2');
        num = 147483648;
    }
    else if (n < 0)
    {
        count += print_char('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        count += print_number(num / 10);

    count += print_char((num % 10) + '0');
    
    return (count);
}

