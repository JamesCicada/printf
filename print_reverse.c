#include "main.h"
#include <stdarg.h>

int print_reverse(va_list list, char buffer[], int flags, int width, int precision, int size)
{
	char *str = va_arg(list, char *);
	int count = 0;

	if (!str)
	{
		return write(1, "(null)", 6);
	}

	int str_len = string_length(str);

	count += print_padding(buffer, width, str_len, flags & FLAG_ZERO);

	if (count == -1)
	{
		return -1;
	}

	int i;
	for (i = str_len - 1; i >= 0; i--)
	{
		count += write(1, &str[i], 1);
	}

	return count;
}

