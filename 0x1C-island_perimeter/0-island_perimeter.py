#!/usr/bin/python3
"""
Create a function def island_pm(grid):
that returns the pm of the island described in grid:
"""


def island_perimeter(grid):
    """
    returns the pm of the island described in grid
    grid is a list of list of integers:
        0 represents a water zone
        1 represents a land zone
        One cell is a square with side length 1
        Grid cells are connected horizontally/vertically
        (not diagonally).
        Grid is rectangular, width and height don’t exceed 100
    Grid is completely surrounded by water, and there is one island
    (or nothing).
    The island doesn’t have “lakes” (water inside that isn’t connected
    to the water around the island).
    """
    pm = 0
    for row in range(len(grid)):
        for column in range(len(grid[row])):
            if grid[row][column] == 1:
                if column == 0:
                    pm += 1
                elif grid[row][column - 1] == 0:
                    pm += 1
                if column == (len(grid[row]) - 1):
                    pm += 1
                elif grid[row][column + 1] == 0:
                    pm += 1
                if row == 0:
                    pm += 1
                elif grid[row - 1][column] == 0:
                    pm += 1
                if row == (len(grid) - 1):
                    pm += 1
                elif grid[row + 1][column] == 0:
                    pm += 1
    return pm
