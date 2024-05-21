# Heap Insert Project

## Overview

This project involves creating functions to work with Max Binary Heaps in C. A Max Binary Heap is a complete binary tree where the value of each node is greater than or equal to the values of its children.

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra` and `-pedantic`
- All files should end with a new line
- A `README.md` file at the root of the project folder is mandatory
- Code should follow the Betty style, checked using `betty-style.pl` and `betty-doc.pl`
- No global variables allowed
- No more than 5 functions per file
- Standard library usage is allowed
- Header file `binary_trees.h` should include all prototypes and be include-guarded

## Data Structures

### Basic Binary Tree

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
Max Binary Heap

typedef struct binary_tree_s heap_t;

Tasks
0. New Node

Write a function that creates a binary tree node:

Prototype:

c

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

    parent is a pointer to the parent node of the node to create
    value is the value to put in the new node
    The new node does not have any children
    Returns a pointer to the new node, or NULL on failure

1. Heap - Insert

Write a function that inserts a value into a Max Binary Heap:

Prototype:

c

heap_t *heap_insert(heap_t **root, int value);

    root is a double pointer to the root node of the Heap
    value is the value to store in the node to be inserted
    Returns a pointer to the inserted node, or NULL on failure
    If the address stored in root is NULL, the created node becomes the root node
    The Max Heap ordering must be maintained

Usage

To compile and run the examples:

sh

gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
./0-node

gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-heap_insert.c 0-binary_tree_node.c -o 1-heap_insert
./1-heap_insert

Files

    binary_trees.h: Header file containing all function prototypes and data structures
    0-binary_tree_node.c: Implementation of the binary_tree_node function
    1-heap_insert.c: Implementation of the heap_insert function

Author

Juan Silva, Software Developer at Holberton School

css


This `README.md` provides an overview of the project, requirements, data structures, tasks, usage