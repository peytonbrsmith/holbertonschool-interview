#!/usr/bin/python3
"""N queens interview project"""
import sys

def nqueen(board, col):
    """nqueen algo"""
    safe = False
    queens = []
    if (col == len(board)):
        for row in range(len(board)):
            for column in range(len(board[row])):
                if board[row][column] == 1:
                    queens.append([row, column])
        print(queens)
        return True
    for x in range(len(board)):
        if (check_pos(board, col, x)):
            board[x][col] = 1
            safe = nqueen(board, col + 1) or safe
            board[x][col] = 0
    return safe

def check_pos(board, col, row):
    """checks board position"""
    for x in range(col):
        if (board[row][x]):
            return False
    x = row; y = col
    while x >= 0 and y >= 0:
        if(board[x][y]):
            return False
        x -= 1; y -= 1
    x = row; y = col
    while y >= 0 and x < len(board):
        if(board[x][y]):
            return False
        x += 1; y -= 1
    return True

if __name__ == "__main__":
    """0-queens"""
    if len(sys.argv) < 2:
        print("Usage: nqueens N"); exit()
    size = sys.argv[1]
    if size.isdigit() is not True:
        print("N must be a number"); exit()
    size = int(size)
    if size < 4:
        print("N must be at least 4"); exit()
    board = []; row = [0] * size
    for col in range(size):
        board.append(row.copy())
    nqueen(board, 0)
