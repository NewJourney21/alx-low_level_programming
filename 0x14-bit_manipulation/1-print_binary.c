#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The unsigned long int number to print in binary.
 *
 * Return: None.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	unsigned long int num_bits = sizeof(unsigned long int) * 8;
	int flag = 0;

	mask = mask << (num_bits - 1);

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mask != 0)
	{
		if ((n & mask) != 0)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag == 1)
			_putchar('0');

		mask = mask >> 1;
	}
}
