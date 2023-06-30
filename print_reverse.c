#include "main.h"

/**
 * print_reverse - Prints a string in reverse
 * @list: List of arguments (unused)
 * @buffer: Buffer array to handle print
 * @flags: Active flags (unused)
 * @width: Width specification (unused)
 * @precision: Precision specification (unused)
 * @size: Size specifier (unused)
 * Return: Number of characters printed
 */
int print_reverse(va_list list, char buffer[], int flags, int width, int precision, int size)
{
	char *str = va_arg(list, char *);
	int len = 0;
	int i;

	if (str == NULL)
		str = "(null)";

	len = _strlen(str);

	for (i = len - 1; i >= 0; i--)
		buffer[_putchar(buffer, str[i])] = '\0';

	return len;
}

