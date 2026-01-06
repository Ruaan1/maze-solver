# Maze Solver (BFS)

A simple maze solver written in C++ using **Breadth-First Search (BFS)** to find the shortest path from `S` (start) to `G` (goal).

Walls are marked with `x`. Open cells can be any other character (e.g. `.`).

## Input Format
The program expects:
1. Number of rows
2. Number of columns
3. The maze grid (one line per row)

### Example (`input.txt`)
5

5


S....

.xx..

..x..

..xG.

.....

## How to Run
Compile:
```bash
g++ -std=c++17 "BFS maze.cpp" -O2 -o maze
```
## Run
./maze < input.txt
