#!/usr/bin/python3
"""
function that returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    returns calculation perimeter of an island in grid
    """
    count = 0

    for a in range(len(grid)):
        for b in range(len(grid[a])):
            if grid[a][b]:
                count += 4

            if a > 0 and grid[a - 1][b] == 1:
                count  -= 2
            if b > 0 and grid[a][b - 1] == 1:
                count -= 2

    return (count)
