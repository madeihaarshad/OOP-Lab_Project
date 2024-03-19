#include <iostream>
#include <string>
using namespace std;

// Forward declaration of addbook()


// Function for searching data by book ID
void searchdata() {
    string bookno;
    cout << "Enter book ID to search data: ";
    cin >> bookno;
    bool found = false;
    for (int i = 0; i < total; i++) {
        if (bookno == book_ID[i]) {
            found = true;
            cout << "\t\t\tThe book number is \n\n"
                << i + 1 << endl;
            cout << "\tBook ID: " << book_ID[i] << endl;
            cout << "\tBook Author: " << book_author[i] << endl;
            cout << "\tBook Price: " << book_pr[i] << endl;
            cout << "\tBook Name: " << book_name[i] << endl;
        }
    }
    if (!found) {
        cout << "Book not found" << endl;
    }
}



// Function for updating record by book ID
void updaterecord() {
    string bookno;
    cout << "Enter book ID to update record: ";
    cin >> bookno;
    bool found = false;
    for (int i = 0; i < total; i++) {
        if (bookno == book_ID[i]) {
            found = true;
            cout << "Enter new details for the book:\n";
            cout << "\tBook Name: ";
            cin.ignore(); // Clear input buffer
            getline(cin, book_name[i]);
            cout << "\tBook Author: ";
            getline(cin, book_author[i]);
            cout << "\tBook Price: ";
            cin >> book_pr[i];
            cout << "Record updated successfully" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Book not found" << endl;
    }
}

// Main function
int main() {
    int value;
    while (true) {
        cout << "\n~~~~"
            << "~~~~"
            << "WELCOME~~~"
            << "~~~~"
            << "~\n\n";
        cout << "Enter your choice\n";
       
        cout << "\t1. Search data\n";
   
        cout << "\t2. Update record\n";
        cout << "\t3. Exit\n";
        cin >> value;
        switch (value) {
        case 1:
            searchdata();
            break;
       
        case 2:
            updaterecord();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
    return 0;
}