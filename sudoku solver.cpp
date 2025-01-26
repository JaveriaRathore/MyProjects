#include <iostream>
#include <vector>

using namespace std;

const int GRID_SIZE = 9;
const int SUBGRID_SIZE = 3;

bool isValidRow(const vector<vector<int> >& grid, int row, int num) {
    for (int col = 0; col < GRID_SIZE; ++col) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isValidCol(const vector<vector<int> >& grid, int col, int num) {
    for (int row = 0; row < GRID_SIZE; ++row) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isValidSubgrid(const vector<vector<int> >& grid, int row, int col, int num) {
    int startRow = (row / SUBGRID_SIZE) * SUBGRID_SIZE;
    int startCol = (col / SUBGRID_SIZE) * SUBGRID_SIZE;
    for (int i = 0; i < SUBGRID_SIZE; ++i) {
        for (int j = 0; j < SUBGRID_SIZE; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isValidPlacement(const vector<vector<int> >& grid, int row, int col, int num) {
    return isValidRow(grid, row, num) && isValidCol(grid, col, num) && isValidSubgrid(grid, row, col, num);
}

bool solveSudoku(vector<vector<int> >& grid) {
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            if (grid[row][col] == 0) { 
                for (int num = 1; num <= GRID_SIZE; ++num) {
                    if (isValidPlacement(grid, row, col, num)) {
                        grid[row][col] = num; 

                        if (solveSudoku(grid)) {
                            return true;
                        }

                        grid[row][col] = 0; 
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}

void printGrid(const vector<vector<int> >& grid) {
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > grid(GRID_SIZE, vector<int>(GRID_SIZE, 0));

    int initialGrid[GRID_SIZE][GRID_SIZE] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j] = initialGrid[i][j];
        }
    }

    if (solveSudoku(grid)) {
        cout << "Sudoku Solved:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}

