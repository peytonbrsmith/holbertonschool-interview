#include "menger.h"
#include <math.h>

/**
 * menger - print menger sponge of level levels
 *
 * @level: levels to print
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void menger(int level)
{
	int y = 0, x = 0, space = 1;
	int sponge_size = pow(3, level);
	char print = '#';

	if (level < 0)
		return;

	for (; y < sponge_size; y++)
	{
		for (x = 0; x < sponge_size; x++)
		{
			space = 1;
			print = '#';
			for (; space < sponge_size; space *= 3)
			{
				if ((y / space) % 3 == 1 && (x / space) % 3 == 1)
				{
					print = ' ';
					break;
				}
			}
			printf("%c", print);
		}
		printf("\n");
	}
}
