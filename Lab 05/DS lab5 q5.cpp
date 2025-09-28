#include <iostream>
using namespace std;
void printingGrid(int grid[9][9]){
    for(int i = 0;i < 9;i++) {
        for(int j = 0;j < 9;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int grid[9][9], int row, int col, int num){
    for (int i = 0;i < 9;i++) {
        if (grid[row][i] == num || grid[i][col] == num){
            return false;
        }
    }
    int Row = row - (row % 3);
    int Col = col - (col % 3);

    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            if (grid[i + Row][j + Col] == num){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int grid[9][9]) {
    int row = -1;
    int col = -1;

    bool Found = false;
    for (int i = 0; i < 9 && !Found; i++) {
        for (int j = 0; j < 9 && !Found; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                Found = true;
            }
        }
    }
    if (!Found)
        return true;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (sudokuSolver(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    if (sudokuSolver(grid))
        printingGrid(grid);
    else
        cout<<"No solution"<<endl;
    return 0;
}
