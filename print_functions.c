#include "main.h"

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
 * print_percent - prints a percernt sign
 * @args: va_list (unused)
 *
 * Return: number of characters printed( always 1)
 */
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}
