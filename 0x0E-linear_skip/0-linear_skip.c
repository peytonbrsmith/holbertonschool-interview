#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

int found = 0;

/**
 * linear_skip - linear search for an element in a skip list
 * @list: skip list to search
 * @value: value to search for
 *
 * Return: the index of the element if found, otherwise null
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp;


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
				printf("Value checked at index [%ld] = [%d]\n",
				list->express->index, list->express->n);
				return (list->express);
			}
			else if (list->express->n > value)
			{
				if (list->express->next == NULL && list->express->n < value)
					printf("Value found between indexes [%ld] and [%ld]\n",
					list->index, list->express->index);
				printf("Value checked at index [%ld] = [%d]\n",
				list->express->index, list->express->n);
				printf("Value found between indexes [%ld] and [%ld]\n",
				list->index, list->express->index);
				printf("Value checked at index [%ld] = [%d]\n",
				list->index, list->n);
				return (linear_skip(list->next, value));
			}
			else
			{
				if (list->express->next == NULL && list->express->n < value)
					printf("Value found between indexes [%ld] and [%ld]\n",
					 list->index, list->express->index);
				return (linear_skip(list->express, value));
			}
		}
		else
		{
			printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
			temp = list;
			while (temp->next && found == 0)
			{
				temp = temp->next;
				if (temp->next == NULL)
				{
					printf("Value found between indexes [%ld] and [%ld]\n",
					list->index, temp->index);
					printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
					found = 1;
				}
				if (temp->n > value)
				{
					break;
				}
			}
			return (linear_skip(list->next, value));
		}
	}
	else if (value == list->n)
	{
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		return (list);
	}
	printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
		printf("Value found between indexes [%ld] and [%ld]\n",
		list->index, list->express->index);
	return (list);
}
