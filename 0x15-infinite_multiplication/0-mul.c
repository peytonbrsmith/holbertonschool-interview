#include "holberton.h"

/**
 * _perror - error message
 *
 * Return: void
 */

void _perror(void)
{
	write(1, "Error\n", 6);
	exit(98);
}

/**
 * are_digits - checks if input is a number
 * @num: the num to check
 * Return: >=0
 */
int are_digits(char *num)
{
	int i = 0, count = 0;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] < '0' || num[i] > '9')
			count++;
	}

	return (count);
}

/**
 * check - checks number for 0s
 * @num: num to check
 * Return: >=0
 */
int check(char *num)
{
	int i, count = 0;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] != '0')
			count++;
	}
	if (count != 0)
		return (0);
	return (1);
}

/**
* mul - multiplication function
* @a: first number
* @b: second number
* @a_len: length
* @b_len: length
*
* Return: the result
*/
char *mul(char *a, char *b, int a_len, int b_len)
{
	char *res = NULL;
	int i, j, n;

	res = malloc(sizeof(char) * (a_len + b_len));
	for (i = 0; i < (a_len + b_len); i++)
		res[i] = '0';
	for (i = a_len - 1; i >= 0; i--)
	{
		n = 0;
		for (j = b_len - 1; j >= 0; j--)
		{
			n += (a[i] - '0') * (b[j] - '0');
			n += res[i + j + 1] - '0';
			res[i + j + 1] = (n % 10) + '0';
			n /= 10;
		}
		if (n)
			res[i + j + 1] = (n % 10) + '0';
	}
	return (res);
}

/**
 * main - takes two numbers of infinite size and prints the result
 * @argc: arg count
 * @argv: arg array
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *a = argv[1], *b = argv[2], *res = NULL;
	int a_len = 0, b_len = 0, count = 0, i = 0;

	if (argc != 3 || are_digits(a) || are_digits(b))
		_perror();

	while (a[a_len])
		a_len++;
	while (b[b_len])
		b_len++;

	res = mul(a, b, a_len, b_len);
	i = check(res);
	if (i == 0)
	{
		i = 0;
		while (res[i] != '\0')
		{
			if (count == 0 && res[i] == '0')
				i++;
			else
			{
				count = 1;
				write(1, (res + i), 1);
				i++;
			}
		}
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
	free(res);
	return (0);
}
