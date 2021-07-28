#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_node: insert a node into a sorted linked list
 * @head: the head of the list
 * @number: the number to insert
 * Return: address of new node
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *current = *head;
    listint_t *temp = NULL;

    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->n = number;

    if (*head == NULL) {
        *head = new_node;
        return new_node;
    }

    if (number < (*head)->n) {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }
    
    while (current->n < new_node->n && current->next != NULL) {
        temp = current;
        current = current->next;
    }
    if (new_node->n > current->n && current->next == NULL) {
        new_node->next = NULL;
        current->next = new_node;
        return new_node;
    }
    new_node->next = current;
    temp->next = new_node;
    return new_node;
}
