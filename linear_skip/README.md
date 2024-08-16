# 0x0E-linear_skip
This interview algorithm project utilizes a skip list.  Skip lists optimize looking for a specific value, which typically requires visiting every element in a singly linked list, by including an "express lane" that moves through the list faster.

[Linear Search in a Skip List](/0x0E-linear_skip/0-linear_skip.c)
* Write a function in C `skiplist_t *linear_skip(skiplist_t *list, int value)` that searches for a value in a sorted skip list of integers:
  * `list` is a pointer to the head of the sorted skip list to search in
  * `list` is sorted in ascending order
  * prints the current element every time it is compared to `value`
  * returns a pointer to the first node where `value` is located or `NULL` if the value is not present or `head` is `NULL`
