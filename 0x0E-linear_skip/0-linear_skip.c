#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/**
 * linear_skip - linear search for an element in a skip list
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (!list)
		return (NULL);
	if (value > list->n)
	{
		if (list->express != NULL)
		{
			if (list->index > 0)
			{
				printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
			}
			if (list->express->n == value)
			{
				printf("Value checked at index [%ld] = [%d]\n", list->express->index, list->express->n);
				return list->express;
			}
			else if (list->express->n > value)
			{
				if (list->express->next == NULL && list->express->n < value)
					printf("Value found between indexes: [%ld] = [%ld]\n", list->index, list->express->index);
				printf("Value checked at index [%ld] = [%d]\n", list->express->index, list->express->n);
				printf("Value found between indexes: [%ld] = [%ld]\n", list->index, list->express->index);
				printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
				return linear_skip(list->next, value);
			}
			else
			{
				if (list->express->next == NULL && list->express->n < value)
					printf("Value found between indexes: [%ld] = [%ld]\n", list->index, list->express->index);
				return linear_skip(list->express, value);
			}
		}
		else
		{
			printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
			return linear_skip(list->next, value);
		}
	}
	else if (value == list->n)
	{
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		return list;
	}
	printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
	return (list);
}
