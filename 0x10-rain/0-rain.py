#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    """rain function"""
    if (len(walls) <= 0):
        return (0)
    water = 0
    for x in range(1, len(walls) - 1):
        wall_1 = walls[x]
        wall_2 = walls[x]
        for y in range(x):
            wall_1 = max(wall_1, walls[y])
        for y in range(x + 1, len(walls)):
            wall_2 = max(wall_2, walls[y])
        water += min(wall_1, wall_2) - walls[x]
    return (water)
