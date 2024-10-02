#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Rotates an n x n 2D matrix 90 degrees clockwise.
    The matrix is modified in-place.

    Args:
        matrix (list of list of int): The 2D matrix to rotate.
    """
    n = len(matrix)
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            # Store the value of the current cell
            temp = matrix[i][j]
            # Move values from left to top
            matrix[i][j] = matrix[n - j - 1][i]
            # Move values from bottom to left
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
            # Move values from right to bottom
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
            # Assign temp to right
            matrix[j][n - i - 1] = temp
