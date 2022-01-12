#include "lists.h"

/**
 * find_listint_loop - find the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: pointer to the node where the loop starts
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p1 = head, *p2 = head;

	if (head == NULL)
		return (NULL);

	while (p2->next != NULL && p2->next->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
		{
			for (p1 = head; p1 != p2; p1 = p1->next, p2 = p2->next)
				;
			return (p2);
		}
	}
	return (NULL);
}
