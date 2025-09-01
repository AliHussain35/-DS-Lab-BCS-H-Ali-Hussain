#include <iostream>
using namespace std;
int main() {
    int r, c;
    cout<<"Enter rows = ";
    cin>>r;
    cout<<"Enter cols = ";
    cin>>c;

    int** arr = new int*[r];
    for (int x = 0; x < r; x++) {
        arr[x] = new int[c];
    }

    cout<<"---Input matrix elements---"<<endl;
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            cin >> arr[x][y];
        }
    }

    cout<<"---Normal Matrix---"<<endl;
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }

    cout<<"---Compressed Matrix---"<<endl;
    for (int i=0; i<r; i++) {
        for (int y = 0; y < c; y++){
            if (arr[i][y] != 0){
                cout<<"("<<i<<","<<y<<","<<arr[i][y]<<")"<<endl;
            }
        }
    }
    for(int i = 0; i<r; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

