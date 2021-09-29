#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

void slide_left(int *line, size_t size)
{
	int i, j;

	for (i = 0, j = 1; i < (int)size; i++, j++)
	{
		if (*(line + i) == 0)
		{
			while (*(line + i) == 0 && i < (int)size)
				i++;
			j = i + 1;
			while (*(line + j) == 0)
				j++;
		}

		if (*(line + i) == *(line + j))
		{
			*(line + i) += *(line + j);
			*(line + j) = 0;
		}
	}
	for (i = 0, j = 1; i < (int)size; i++)
	{
		if (*(line + j) != 0)
		{
			while (*(line + j) != 0)
				j++;
		}
		if (*(line + i) == 0)
		{
			while (*(line + i) == 0)
				i++;
			*(line + j) = *(line + i);
			*(line + i) = 0;
		}
	}
}

void slide_right(int *line, size_t size)
{
	int i, j;

	for (i = (size - 1), j = (size - 2); i > 0; i--)
	{
		if (*(line + j) != 0)
		{
			while (*(line + j) != 0 && i > 0)
				j--;
		}
		if (*(line + i) == 0)
		{
			while (*(line + i) == 0)
				i--;
			*(line + j) = *(line + i);
			*(line + i) = 0;
		}
	}

	for (i = (size - 1), j = (size - 2); i > 0; i--, j--)
	{
		if (*(line + i) == 0)
		{
			while (*(line + i) == 0)
				i--;
			j = i - 1;
			while (*(line + j) == 0)
				j--;
		}

		if (*(line + i) == *(line + j))
		{
			*(line + i) += *(line + j);
			*(line + j) = 0;
		}
	}
}

int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
	{
		return (0);
	}
	else if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
	}

	return (1);
}
