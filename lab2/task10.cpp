#include <iostream>

using namespace std;

int main(){
    int numCategories;
    cout << "Enter number of categories: ";
    cin >> numCategories;

    string* categories = new string[numCategories];
    int* bookCounts = new int[numCategories];
    int** bookIDs = new int*[numCategories];

    for (int currentCategory = 0; currentCategory < numCategories; currentCategory++){
        cout << "Enter name of category " << currentCategory + 1 << ": ";
        cin >> categories[currentCategory];

        cout << "Enter number of books in " << categories[currentCategory] << ": ";
        cin >> bookCounts[currentCategory];

        bookIDs[currentCategory] = new int[bookCounts[currentCategory]];
        cout << "Enter book IDs for " << categories[currentCategory] << ":" << endl;
        for (int currentBook = 0; currentBook < bookCounts[currentCategory]; currentBook++){
            cin >> bookIDs[currentCategory][currentBook];
        }
    }

    int searchBookID;
    cout << "Enter book ID to search: ";
    cin >> searchBookID;

    string foundCategory = "";
    for (int categoryIndex = 0; categoryIndex < numCategories; categoryIndex++){
        for (int bookIndex = 0; bookIndex < bookCounts[categoryIndex]; bookIndex++){
            if (bookIDs[categoryIndex][bookIndex] == searchBookID){
                foundCategory = categories[categoryIndex];
            }
        }
    }

    if (foundCategory != "")
        cout << "Book found in category: " << foundCategory << endl;
    else
        cout << "Book not available" << endl;

    for (int categoryIndex = 0; categoryIndex < numCategories; categoryIndex++){
        delete[] bookIDs[categoryIndex];
    }
    
    delete[] bookIDs;
    delete[] bookCounts;
    delete[] categories;
    
}
