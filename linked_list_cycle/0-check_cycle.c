#include <stdio.h>
#include <stdlib.h>

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

int check_cycle(listint_t *list)
{     
    listint_t *slow;
    listint_t *fast;
    
    if (list == NULL || list->next == NULL)
        return 0;

    slow = list;
    fast = list->next;

    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
            return 1;

        slow = slow->next;
        fast = fast->next->next;
    }

    return 0;
}

/* Function to create a new node*/
listint_t *create_node(int value)
{
    listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));
    if (new_node == NULL)
    {
        printf("Error allocating memory\n");
        return NULL;
    }
    new_node->n = value;
    new_node->next = NULL;
    return new_node;
}

// Function to free the list
void free_list(listint_t *head)
{
    listint_t *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}