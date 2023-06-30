#include "main.h"
#include <stdarg.h>

int format_parser(const char *fmt, int *ind, va_list list, char buffer[], int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', printf}, {'s', printf}, {'%', printf},
		{'i', printf}, {'d', printf}, {'b', print_binary},
		{'u', printf}, {'o', printf}, {'x', printf},
		{'X', printf}, {'p', printf}, {'S', printf},
		{'r', print_reverse}, {'R', printf}, {'\0', printf}
	};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
		{
			return fmt_types[i].fn(list, buffer, flags, width, precision, size);
		}
	}

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
		{
			return -1;
		}

		unknown_len += write(1, "%%", 1);

		if (fmt[*ind - 1] == ' ')
		{
			unknown_len += write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
			{
				--(*ind);
			}
			if (fmt[*ind] == ' ')
			{
				--(*ind);
			}
			return 1;
		}

		unknown_len += write(1, &fmt[*ind], 1);
		return unknown_len;
	}

	return printed_chars;
}

