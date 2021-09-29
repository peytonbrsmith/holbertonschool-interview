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
    {
        return 0;
    }
    while (current)
    {
        current = current->next;
        length++;
    }

    temp = (int *)malloc(sizeof(int) * length);
    if (temp == NULL) {
        printf("Memory not allocated.\n");
        return 0;
    }
    current = *head;
    for (i = 0; current != NULL; i++)
    {
        *(temp + i) = current->n;
        current = current->next;
    }

    for (i = 0, j = length - 1; i < length; ++i, --j) {
        if (*(temp + i) != *(temp + j)) {
            free(temp);
            return 0;
        }
    }

    free(temp);

    return (1);
}
