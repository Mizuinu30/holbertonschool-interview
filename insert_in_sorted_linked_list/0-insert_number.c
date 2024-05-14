#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: double pointer to the head of the list
 * @number: number to insert
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current, *prev;

    new_node = (listint_t *)malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    current = *head;
    while (current && current->n < number)
    {
        prev = current;
        current = current->next;
    }

    new_node->next = current;
    prev->next = new_node;

    return (new_node);
}

void print_list(listint_t *head)
{
    while (head)
    {
        printf("%d -> ", head->n);
        head = head->next;
    }
    printf("NULL\n");
}
