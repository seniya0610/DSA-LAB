#include <iostream>
using namespace std;

const int N = 4;

void display(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y, int visited[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && 
            maze[x][y] == 1 && visited[x][y] == 0);
}

bool solveMaze(int maze[N][N], int visited[N][N], int x, int y)
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        visited[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, visited))
    {
        visited[x][y] = 1;

        if (solveMaze(maze, visited, x + 1, y)) return true; // down
        if (solveMaze(maze, visited, x, y + 1)) return true; // right
        if (solveMaze(maze, visited, x - 1, y)) return true; // up
        if (solveMaze(maze, visited, x, y - 1)) return true; // left

        visited[x][y] = 0; // backtracking
    }
    return false;
}

int main()
{
    int maze[N][N] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1}};

    cout << "Maze:\n";
    display(maze);

    int visited[N][N] = {0};

    if (solveMaze(maze, visited, 0, 0))
    {
        cout << "\nPath found:\n";
        display(visited);
    }
    else
    {
        cout << "No path found" << endl;
    }
}
