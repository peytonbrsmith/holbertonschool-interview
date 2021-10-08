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
    int x, y, space;
    int sponge_size = pow(3, level);
    char prc;

	if (level < 0)
		return;

	for (space = 1, prc = '#'; y < sponge_size; y++)
	{
		for (x = 0; x < sponge_size; x++)
		{
            prc = '#';
			space = 1;

            for (; space < sponge_size; space *= 3)
            {
				if ((y / space) % 3 == 1 && (x / space) % 3 == 1)
				{
					prc = ' ';
					break;
				}
			}
			printf("%c", prc);
		}
		printf("\n");
	}
}
