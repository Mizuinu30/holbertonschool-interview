#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid1[3][3]);
void topple_sandpiles(int grid1[3][3]);
void print_grid1(int grid1[3][3]);

#endif /*SANDPILES_H*/
