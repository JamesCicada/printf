#include <stdio.h>
#include <stdarg.h>
#include "main.h"

void print_number(int n);
int get_num_length(int n);

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *str;
	int num;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str != '\0')
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					print_number(num);
					count += get_num_length(num);
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);

	return count;
}
/**
 * print_number - Prints an integer number
 * @n: The number to print
 */
void print_number(int n)
{
        if (n < 0)
        {
                putchar('-');
                n = -n;
        }

        if (n / 10 != 0)
                print_number(n / 10);

        putchar((n % 10) + '0');
}


/**
 * get_num_length - Computes the length of an integer number
 * @n: The number
 *
 * Return: The length of the number
 */
int get_num_length(int n)
{
        int length = 0;

        if (n < 0)
        {
                length++;
                n = -n;
        }

        while (n != 0)
        {
                length++;
                n /= 10;
        }

        return length;
}
