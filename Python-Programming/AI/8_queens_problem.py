def is_safe(board, row, col):
    # Check column
    for i in range(row):
        if board[i][col] == 1:
            return False

    # Check upper-left diagonal
    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1

    # Check upper-right diagonal
    i, j = row, col
    while i >= 0 and j < len(board):
        if board[i][j] == 1:
            return False
        i -= 1
        j += 1

    return True


def solve_queens(board, row):
    n = len(board)

    if row >= n:
        return True

    for col in range(n):
        if is_safe(board, row, col):
            board[row][col] = 1

            if solve_queens(board, row + 1):
                return True

            # Backtrack
            board[row][col] = 0

    return False


def print_board(board):
    n = len(board)
    for i in range(n):
        for j in range(n):
            print(board[i][j], end=" ")
        print()


def solve_8_queens():
    n = 8
    board = [[0] * n for _ in range(n)]

    if solve_queens(board, 0):
        print("Solution found:")
        print_board(board)
    else:
        print("No solution exists.")


# Run the program
solve_8_queens()
