#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @head: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where the value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
    skiplist_t *node = head;
    skiplist_t *express = NULL;

    if (head == NULL)
        return (NULL);

    /* Use the express lane to find the block where value could be */
    while (node->express != NULL)
    {
        express = node->express;
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        if (express->n >= value)
            break;
        node = express;
    }

    /* If express lane ends, check remaining elements in the list */
    if (node->express == NULL)
    {
        express = node;
        while (express->next != NULL)
            express = express->next;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", node->index, express->index);

    /* Perform linear search in the identified block */
    while (node != NULL && node->index <= express->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
        if (node->n == value)
            return (node);
        node = node->next;
    }

    return (NULL);
}
