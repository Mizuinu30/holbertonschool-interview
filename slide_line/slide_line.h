#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h> // Include stddef.h for size_t

#define SLIDE_LEFT  0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
// Your code will be compiled with this header file