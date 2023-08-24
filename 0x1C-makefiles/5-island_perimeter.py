#!/usr/bin/python3
"""function that returns the perimeter of the island described in grid:"""

def island_perimeter(grid):
    num = 0
    
    for i in range(len(grid)):
        for x in range(len(grid[i])):
            if grid[i][x]:
                num += 4

                if i > 0 and grid[i - 1][x] == 1:
                    num -= 2

                if x > 0 and grid[i][x - 1] == 1:
                    num -= 2

    return (num)
