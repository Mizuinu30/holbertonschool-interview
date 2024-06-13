#include <stdio.h>
#include <stdlib.h>

typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
int is_palindrome(listint_t **head);
listint_t *reverse_list(listint_t *head);
int compare_lists(listint_t *head1, listint_t *head2);
void print_list(listint_t *head);

/* Function to check if a singly linked list is a palindrome */
int is_palindrome(listint_t **head)
{
    if (head == NULL || *head == NULL)
        return 1;

    listint_t *slow = *head, *fast = *head;
    listint_t *first_half, *second_half, *second_half_reversed;

    /* Find the middle of the list */
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse the second half of the list */
    second_half = slow;
    second_half_reversed = reverse_list(second_half);

    /* Compare the first half with the reversed second half */
    first_half = *head;
    int result = compare_lists(first_half, second_half_reversed);

    /* Restore the list (optional) */
    reverse_list(second_half_reversed);

    return result;
}
