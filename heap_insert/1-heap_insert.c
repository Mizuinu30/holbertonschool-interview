#include "binary_trees.h"

/**
 * insertLeaf - insert new Leaf
 * @r: root of max heap tree
 * @value: value of new leaf
 * Return: pointer to leaf
 */
heap_t *insertLeaf(heap_t *r, int value)
{
heap_t *q[1025] = {NULL}, *leaf = NULL;
int i = 0, tailIndex = 0;

q[0] = r;
while (q[i] != NULL)
{
if (q[i]->left == NULL)
{
leaf = binary_tree_node(q[i], value);
q[i]->left = leaf;
break;
}
else
q[++tailIndex] = q[i]->left;

if (q[i]->right == NULL)
{
leaf = binary_tree_node(q[i], value);
q[i]->right = leaf;
break;
}
else
q[++tailIndex] = q[i]->right;
i++;
}
return (leaf);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to put in the new node
 * Return: pointer to the inserted node or NULL if failed
 */
heap_t *heap_insert(heap_t **root, int value)
{
binary_tree_t *leaf = NULL, *tmp = NULL;
int temp = 0;

if ((root == NULL) || (*root == NULL))
{
leaf = binary_tree_node(*root, value);
*root = leaf;
return (leaf);
}

leaf = insertLeaf(*root, value);
tmp = leaf;
while ((leaf != NULL) && (leaf->parent != NULL))
{
if (leaf->parent->n < leaf->n)
{
temp = leaf->parent->n;
leaf->parent->n = leaf->n;
leaf->n = temp;
tmp = tmp->parent;
}
leaf = leaf->parent;
}
return (tmp);
}
