#include <stdlib.h>
void fill_numbase_buffer(unsigned int num, unsigned int base,
char *buff, int buff_size);

char *get_int(int num);
int get_numbase_len(unsigned int num, unsigned int base);
unsigned int _abs(int);


/**
 * get_int - gets a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int len = 0;
	long num_k = 0;
	char *ret_value;

	temp = _abs(num);
	len = get_numbase_len(temp, 10);

	if (num < 0 || num_k < 0)
		len++; /* negative sign */
	ret_value = malloc(len + 1); /* create new string */
	if (!ret_value)
		return (NULL);


	fill_numbase_buffer(temp, 10, ret_value, len);
	if (num < 0 || num_k < 0)
		ret_value[0] = '-';

	return (ret_value);
}

/**
 * _abs - gets the absolute value of an integer
 * @x: integer to get absolute value of
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int x)
{
	if (x < 0)
		return (-(unsigned int)x);
	return ((unsigned int)x);
}

/**
 * fill_numbase_buffer - fills buffer with correct numbers
 * up to base 36
 * @buff: buffer to fill with result of conversion
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void fill_numbase_buffer(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int remainder, b = buff_size - 1;

	buff[buff_size] = '\0';
	while (b >= 0)
	{
		remainder = num % base;
		if (remainder > 9) /* return lowercase ascii */
/* val representation */
			buff[b] = remainder + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[b] = remainder + '0';
		num /= base;
		b--;
	}
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
