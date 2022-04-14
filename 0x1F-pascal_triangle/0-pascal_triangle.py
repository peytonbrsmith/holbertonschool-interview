#!/usr/bin/python3
"""Pascal's Triangle"""


def pascal_triangle(n):
    """return pascal triangle of size n"""
    if (n <= 0):
        return []
    triangle = [[1]]
    for n in range(1, n):
        row = [1]
        for k in range(1, n):
            row.append(triangle[n - 1][k - 1] + triangle[n - 1][k])
        row.append(1)
        triangle.append(row)
    return triangle
