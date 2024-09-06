#include "sort.h"
#include <stddef.h>  // Include this header for size_t

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void swap(int *a, int *b, int *array, size_t n);

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    heapify(array, size);

    for (size_t end = size - 1; end > 0; end--)
    {
        swap(&array[end], &array[0], array, size);
        sift_down(array, 0, end - 1, size);
    }
}

/**
 * heapify - Builds a max heap from an array
 * @array: Array of integers
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
    for (ssize_t start = (size - 2) / 2; start >= 0; start--)
    {
        sift_down(array, start, size - 1, size);
    }
}

/**
 * sift_down - Repairs the heap whose root element is at index 'start'
 * @array: Array of integers
 * @start: Start index
 * @end: End index
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;

    while ((root * 2 + 1) <= end)
    {
        size_t child = root * 2 + 1;
        size_t swap_idx = root;

        if (array[swap_idx] < array[child])
            swap_idx = child;

        if (child + 1 <= end && array[swap_idx] < array[child + 1])
            swap_idx = child + 1;

        if (swap_idx == root)
            return;
        else
        {
            swap(&array[root], &array[swap_idx], array, size);
            root = swap_idx;
        }
    }
}

/**
 * swap - Swaps two elements in an array and prints the array
 * @a: First element to swap
 * @b: Second element to swap
 * @array: Array of numbers
 * @n: Size of array
 */
void swap(int *a, int *b, int *array, size_t n)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    print_array(array, n);
}
