#include "lists.h"
/**
 * insert_node: insert a node into a sorted linked list
 * @head: the head of the list
 * @number: the number to insert
 * Return: address of new node
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current = *head;

    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->n = number;

    if (*head == NULL) {
        *head = new_node;
        return new_node;
    }
    
    while (current->n < new_node->n && current->next != NULL) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return new_node;
}
