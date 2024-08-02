#!/usr/bin/env python3
import sys

def print_solution(board):
    """Print the board configuration as a list of positions."""
    solution = []
    for i in range(len(board)):
        solution.append([i, board[i]])
    print(solution)

def is_safe(board, row, col):
    """Check if a queen can be placed on the board at (row, col)."""
    for i in range(row):
        if board[i] == col or board[i] - i == col - row or board[i] + i == col + row:
            return False
    return True

def solve_nqueens_util(board, row, n):
    """Use backtracking to find all solutions for placing queens."""
    if row == n:
        print_solution(board)
        return
    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens_util(board, row + 1, n)
            board[row] = -1

def solve_nqueens(n):
    """Initialize the board and solve the N Queens problem."""
    board = [-1] * n
    solve_nqueens_util(board, 0, n)

def main():
    """Main function to handle input and validate arguments."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(n)

if __name__ == "__main__":
    main()
