#!/usr/bin/python3
"""
Rotates a matrix 90 degrees clockwise
"""

def rotate_2d_matrix(matrix):
    """Rotates a matrix 90 degrees clockwise"""
    size = len(matrix)
    for row in range(size // 2):
        k = size - 1 - row
        for col in range(row, size - row - 1):
            j = size - 1 - col
            temp = matrix[row][col]
            matrix[row][col] = matrix[j][row]
            matrix[j][row] = matrix[k][j]
            matrix[k][j] = matrix[col][k]
            matrix[col][k] = temp
