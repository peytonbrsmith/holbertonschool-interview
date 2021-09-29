#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - check linked list for cycle
 * @list: pointer to linked list
 *
 * Return: 1 if cycle, 0 if not
 */
int check_cycle(listint_t *list)
{
	listint_t *first_ptr = list;
	listint_t *second_ptr = list;

	/* find if loop exists */
	while (first_ptr && second_ptr && second_ptr->next)
	{
		first_ptr = first_ptr->next;
		second_ptr = second_ptr->next->next;

		/* loop is found */
		if (first_ptr == second_ptr)
			return (1);
	}
	return (0);
}
