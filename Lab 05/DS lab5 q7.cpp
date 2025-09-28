#include <iostream>
using namespace std;

int chessboard[20][20];

bool isSafe(int r, int c, int n){
    for(int i=0; i<r; i++) {
        if(chessboard[i][c]){
            return false;
        }
    }
    for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--){
        if(chessboard[i][j]){
            return false;
        }
    }
    for(int i = r-1, j = c+1; i>=0 && j < n; i--, j++){
        if (chessboard[i][j]){
            return false;
        }
    }
    return true;
}

void solve(int r, int num){
    if(r==num){
        for(int i = 0; i < num; i++) {
            for(int j = 0; j < num; j++) {
                cout<<(chessboard[i][j] ? "Q ":". ");
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for (int c = 0; c < num; c++){
        if (isSafe(r, c, num)){
            chessboard[r][c] = 1;
            solve(r+ 1, num);
            chessboard[r][c] = 0;
        }
    }
}
int main() {
    int num;
    cout<<"Enter size = ";
    cin>>num;
    solve(0, num);
    return 0;
}
