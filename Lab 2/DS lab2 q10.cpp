#include<iostream>
#include<string>
using namespace std;
int main(){
	int categories;
    cout<<"Enter number of categories in the library = ";
    cin>>categories;
    cin.ignore();
    string* categoryNames = new string[categories];
    for(int i=0; i<categories; i++){
    	string name;
    	cout<<"Enter category name "<<i+1<<" = ";
    	cin>>name;
    	categoryNames[i] = name;
	}
	int numberOfBooks[categories];
    int** books = new int*[categories];
    for(int i=0; i<categories; i++){
    	int numBooks;
    	cout<<"Enter number of books in category: "<<categoryNames[i]<<" = ";
    	cin>>numBooks;
    	numberOfBooks[i]= numBooks;
    	books[i] = new int[numBooks];
	}
	for(int i=0; i<categories; i++){
		int count = numberOfBooks[i];
		cout<<"--->For category: "<<categoryNames[i]<<endl;
		for(int j=0; j<count; j++){
			int bookID;
			cout<<"Enter Book ID for book number "<<j+1<<" = ";
			cin>>bookID;
			books[i][j] = bookID;
		}
	}
	
	int searchID;
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < numberOfBooks[i]; j++) {
            if (books[i][j] == searchID) {
                cout << "Book ID " << searchID << " is available in category: " << categoryNames[i] << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (!found) {
        cout << "Book ID " << searchID << " not found in library." << endl;
    }

    // Free memory
    for (int i = 0; i < categories; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] categoryNames;
    delete[] numberOfBooks;

    return 0;

    
}

