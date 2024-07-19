#include "slide_line.h"

static void merge_left(int *line, size_t size);
static void merge_right(int *line, size_t size);
static void slide_left(int *line, size_t size);
static void slide_right(int *line, size_t size);

int slide_line(int *line, size_t size, int direction) {
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT) {
        return 0; // Invalid direction
    }

    if (direction == SLIDE_LEFT) {
        slide_left(line, size);
        merge_left(line, size);
        slide_left(line, size); // Slide again to remove gaps after merge
    } else if (direction == SLIDE_RIGHT) {
        slide_right(line, size);
        merge_right(line, size);
        slide_right(line, size); // Slide again to remove gaps after merge
    }

    return 1;
}

static void slide_left(int *line, size_t size) {
    size_t i, pos = 0;
    for (i = 0; i < size; i++) {
        if (line[i] != 0) {
            if (i != pos) {
                line[pos] = line[i];
                line[i] = 0;
            }
            pos++;
        }
    }
}

static void merge_left(int *line, size_t size) {
    size_t i;
    for (i = 0; i < size - 1; i++) {
        if (line[i] == line[i + 1] && line[i] != 0) {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }
}

static void slide_right(int *line, size_t size) {
    if (size == 0) return; // Handle edge case where size is 0

    size_t i, pos = size - 1;
    for (i = size - 1; ; i--) {
        if (line[i] != 0) {
            if (i != pos) {
                line[pos] = line[i];
                line[i] = 0;
            }
            pos--;
        }
        if (i == 0) break; // Break the loop when i reaches 0 to avoid underflow
    }
}

static void merge_right(int *line, size_t size) {
    size_t i;
    for (i = size - 1; i > 0; i--) {
        if (line[i] == line[i - 1] && line[i] != 0) {
            line[i] *= 2;
            line[i - 1] = 0;
        }
    }
}
