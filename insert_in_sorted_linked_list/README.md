# Sorted Singly Linked List Insertion

This project provides a C implementation for inserting a number into a sorted singly linked list. The `insert_node` function takes a pointer to the head of the list and the number to be inserted, and it returns the address of the new node or `NULL` if it fails.

## Structure Definition

The linked list node is defined as follows:

```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

#Function Prototype
listint_t *insert_node(listint_t **head, int number);

Parameters

    head: A double pointer to the head of the list.
    number: The number to be inserted into the list.

Return Value

    Returns the address of the new node, or NULL if memory allocation fails.

Usage
Compilation

To compile the code, use the following command:

sh

gcc -o insert_node main.c

Example

Here is an example of how to use the insert_node function:

c

#include <stdio.h>
#include <stdlib.h>

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *insert_node(listint_t **head, int number);
void print_list(listint_t *head);

int main(void)
{
    listint_t *head = NULL;

    insert_node(&head, 10);
    insert_node(&head, 5);
    insert_node(&head, 20);
    insert_node(&head, 15);
    insert_node(&head, 7);

    print_list(head);

    return (0);
}

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current, *prev;

    new_node = malloc(sizeof(listint_t));
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

Output

When you run the compiled program, the output will be:

rust

5 -> 7 -> 10 -> 15 -> 20 -> NULL

This demonstrates that the numbers have been correctly inserted into the sorted singly linked list.