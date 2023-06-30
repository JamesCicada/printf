#include "main.h"

/**
 * print_binary - Prints an unsigned int in binary format
 * @list: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags (unused)
 * @width: Width specification (unused)
 * @precision: Precision specification (unused)
 * @size: Size specifier (unused)
 * Return: Number of characters printed
 */
int print_binary(va_list list, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int num = va_arg(list, unsigned int);
	int len = 0;
	unsigned int temp = num;

	if (num == 0)
	{
		buffer[_putchar(buffer, '0')] = '\0';
		return 1;
	}

	while (temp != 0)
	{
		temp >>= 1;
		len++;
	}

	for (; len > 0; len--)
	{
		buffer[_putchar(buffer, ((num >> (len - 1)) & 1) + '0')] = '\0';
	}

	return num;
}

