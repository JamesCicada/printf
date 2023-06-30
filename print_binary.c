#include "main.h"
#include <stdarg.h>

int print_binary(va_list list, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int num = va_arg(list, unsigned int);
	int count = 0;
	int bin_len = get_num_length(num, 2);
	char *binary = convert_to_base(num, 2);

	if (!binary)
	{
		return -1;
	}

	if (flags & FLAG_HASH)
	{
		count += write(1, "0b", 2);
	}

	count += print_padding(buffer, width, bin_len, flags & FLAG_ZERO);

	if (count == -1)
	{
		free(binary);
		return -1;
	}

	count += write(1, binary, bin_len);
	free(binary);
	return count;
}

