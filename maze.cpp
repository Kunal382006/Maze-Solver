#include <iostream>
#include <vector>

using namespace std;

// Directions: Up, Down, Left, Right
int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

// Function to check if the move is valid
bool isValidMove(int x, int y, vector<vector<char>> &maze, vector<vector<bool>> &visited) {
    int rows = maze.size();
    int cols = maze[0].size();
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != '#' && !visited[x][y]);
}

// Depth-First Search for solving the maze
bool solveMaze(int x, int y, vector<vector<char>> &maze, vector<vector<bool>> &visited) {
    int rows = maze.size();
    int cols = maze[0].size();

    // If destination is reached
    if (maze[x][y] == 'E') {
        return true;
    }

    visited[x][y] = true;

    // Explore all possible directions
    for (int i = 0; i < 4; ++i) {
        int newX = x + dRow[i];
        int newY = y + dCol[i];

        if (isValidMove(newX, newY, maze, visited)) {
            if (solveMaze(newX, newY, maze, visited)) {
                maze[x][y] = '.'; // Mark the path
                return true;
            }
        }
    }

    return false;
}

int main() {
    // Define the maze
    vector<vector<char>> maze = {
        {'S', '.', '#', '#', '#'},
        {'.', '.', '#', '.', '.'},
        {'#', '.', '#', 'E', '#'},
        {'#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#'}
    };

    int rows = maze.size();
    int cols = maze[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Start solving from 'S'
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (maze[i][j] == 'S') {
                if (solveMaze(i, j, maze, visited)) {
                    maze[i][j] = 'S'; // Restore start position
                } else {
                    cout << "No solution found!" << endl;
                }
            }
        }
    }

    // Print the solution
    cout << "Maze solution: " << endl;
    for (const auto &row : maze) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }

    return 0;
}
