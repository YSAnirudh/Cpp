#include <iostream>

using namespace std;

void pathPrintHelper(int** grid, int i, int j, int size) {

    cout << i << " " << j << endl;
    if (i + 1 < size && j < size && grid[i+1][j] >= grid[i][j+1]) {
        pathPrintHelper(grid, i+1, j,size);
    } else if (j + 1 < size && i < size && grid[i+1][j] < grid[i][j+1]) {
        pathPrintHelper(grid, i, j+1,size);
    }
}

void findPath(int** grid, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            grid[i][j] = max(grid[i][j-1], grid[i-1][j]) + grid[i][j];
        }
    }
    cout << endl << "Path: " << endl;
    pathPrintHelper(grid, 0,0, size);
}