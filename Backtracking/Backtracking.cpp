//Backtracking

//Author: Abhishek Kumar Suman
//Roll number:181210002
//Branch: CSE 2nd year

/*Rat in a Maze
A Maze is given as N*N binary matrix of blocks where source block is the upper left most
block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A
rat starts from source and has to reach the destination. The rat can move only in two
directions: forward and down. In the maze matrix, 0 means the block is a dead end and 1 means 
the block can be used in the path from source to destination.*/

/*Input : {1, 0, 0, 0}
          {1, 1, 0, 1}
          {0, 1, 0, 0}
          {1, 1, 1, 1}

  Ouptput:{1, 0, 0, 0}
          {1, 1, 0, 0}
          {0, 1, 0, 0}
          {0, 1, 1, 1} */
//All enteries in solution path are marked as 1.

//C++ Program to find path for rat in a maze using Backtracking.
#include <bits/stdc++.h>
using namespace std;
// Maze size
#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

/* Function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

/* Function to check if x, y (x, y is our goal)is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x, y outside maze) return false
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}

/* This function solves the Maze problem using Backtracking. It mainly 
uses solveMazeUtil() to solve the problem. It returns false if no 
path is possible, otherwise return true and prints the path in the 
form of 1s.*/
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    if (solveMazeUtil(maze, 0, 0, sol) == false)
    {
        cout << "Solution doesn't exist" << endl;
        return false;
    }

    printSolution(sol);
    return true;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x, y is goal) return true
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }

    // maze[x][y] is valid or not
    if (isSafe(maze, x, y) == true)
    {
        sol[x][y] = 1;

        // Move forward in x direction
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;

        // If moving in x direction doesn't give solution then
        // Move down in y direction
        if (solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;

        // If none of the above movements work then BACKTRACK:
        //	unmark x, y as part of solution path
        sol[x][y] = 0;
        return false;
    }

    return false;
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};

    solveMaze(maze);

    return 0;
}
