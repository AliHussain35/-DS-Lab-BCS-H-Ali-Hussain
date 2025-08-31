#include<iostream>
using namespace std;
int main(){
	int rows, cols;
	cout<<"Enter number of rows and columns for both the matrices"<<endl;
	cout<<"Rows = ";
	cin>>rows;
	cout<<"Columns = ";
	cin>>cols;
	int** matrix1 = new int*[rows];
	int** matrix2 = new int*[rows];
	int** addedMatrix = new int*[rows];
	int** subtractedMatrix = new int*[rows];
	for(int i=0; i<rows; i++){
		matrix1[i] = new int[cols];
		matrix2[i] = new int[cols];
		addedMatrix[i] = new int[cols];
		subtractedMatrix[i]= new int[cols];
	}
	cout<<"---Enter values for matrix 1---"<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			int val;
			cout<<"Enter value for row "<<i+1<<" and column "<<j+1<<" = ";
			cin>>val;
			matrix1[i][j] = val;
		}
	}
	cout<<"---Enter values for matrix 2---"<<endl;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			int val;
			cout<<"Enter value for row "<<i+1<<" and column "<<j+1<<" = ";
			cin>>val;
			matrix2[i][j] = val;
		}
	}
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			addedMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			subtractedMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
	cout<<"---Displaying Matrix addition---"<<endl;
	for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << addedMatrix[i][j]<<" "; 
        }
        cout<<endl;
    }
    cout<<"---Displaying Matrix subtraction---"<<endl;
	for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << subtractedMatrix[i][j]<<" "; 
        }
        cout<<endl;
    }
    for (int i = 0; i < rows; i++){
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] addedMatrix[i];
        delete[] subtractedMatrix[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] addedMatrix;
    delete[] subtractedMatrix;
}
