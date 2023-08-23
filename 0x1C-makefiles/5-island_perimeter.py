#!/usr/bin/python3
def island_perimeter(grid):
num = 0
for row in range(len(grid)):
for column in range(len(grid[row])):
if (grid[row][column] == 1):
if (column == len(grid[row]) - 1 or grid[row][column + 1] == 0):
num = num + 1
if (row == len(grid) - 1 or grid[row + 1][column] == 0):
num = num + 1
if (column == 0 or grid[row][column - 1] == 0):
num = num + 1
if (row == 0 or grid[row - 1][column] == 0):
num = num + 1
return (num)
