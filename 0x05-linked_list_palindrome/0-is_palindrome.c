#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if a linked list is a palindrome
 * @head: head of the linked list
 *
 * Return: 1 if the linked list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int *temp = NULL;
	int i = 0, j = 0, length = 0;

	if (head == NULL)
		return (1);
	temp = (int *)malloc(sizeof(int));
	if (temp == NULL)
		return (0);
	for (i = 0, current = *head; current != NULL; i++, current = current->next)
	{
		*(temp + i) = current->n;
		if (current->next != NULL)
		{
			temp = (int *)realloc(temp, sizeof(int) * (i + 2));
			if (temp == NULL)
				return (0);
		}
	}
	for (length = i, i = 0, j = length - 1; i < length; ++i, --j)
	{
		if (*(temp + i) != *(temp + j) || length % 2 != 0)
		{
			free(temp);
            return (0);
		}
	}
	free(temp);
	return (1);
}
