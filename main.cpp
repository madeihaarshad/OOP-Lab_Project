#include <iostream>
#include <string>
using namespace std;

// Forward declaration of addbook()
void addbook();

// Global variables
string book_ID[20], book_name[20], book_author[20];
int book_pr[20];
int total = 0;

// Function for displaying book data
void showdata() {
    if (total == 0) {
        char choice;
        cout << "No books to show.\n";
        cout << "Do you want to add a book? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            addbook(); // Call addbook() to add a new book
        } else {
            return;
        }
    }

    cout << "No. of books: " << total << endl;
    for (int i = 0; i < total; i++) {
        cout << "\t\tThe detail of book\t" << i + 1 << "\n\n";
        cout << "\tBook ID:\t";
        cout << book_ID[i] << endl;
        cout << "\tBook Author:\t";
        cout << book_author[i] << endl;
        cout << "\tBook Price:\t";
        cout << book_pr[i] << endl;
        cout << "\tBook Name:\t";
        cout << book_name[i] << endl;
        cout << "\n\n";
    }
}

// Function for adding books
void addbook() {
    int ch = 0;
    cout << "Enter number of books you want to add: ";
    cin >> ch;
    for (int i = total; i < total + ch; i++) {
        cout << "\t\tEnter the detail of book\n\n";
        cout << "\tBook Name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, book_name[i]);
        cout << "\tBook ID: ";
        cin >> book_ID[i];
        cout << endl; // Ensure book ID and author are displayed on separate lines
        cout << "\tEnter book author: ";
        cin.ignore(); // Clear input buffer
        getline(cin, book_author[i]); // Allowing spaces in author name
        cout << endl; // Clearing input buffer
        cout << "\tEnter book price: ";
        cin >> book_pr[i];
        cout << endl; // Clearing input buffer
    }
    total += ch;
}

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

// Function for deleting data by book ID
void deletedata() {
    string bookno;
    cout << "Enter book ID to delete data: ";
    cin >> bookno;
    bool found = false;
    for (int i = 0; i < total; i++) {
        if (bookno == book_ID[i]) {
            found = true;
            // Shift all elements after the found index to the left to remove the book record
            for (int j = i; j < total - 1; j++) {
                book_ID[j] = book_ID[j + 1];
                book_name[j] = book_name[j + 1];
                book_author[j] = book_author[j + 1];
                book_pr[j] = book_pr[j + 1];
            }
            total--;
            cout << "Book data deleted successfully" << endl;
            break;
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
        cout << "\t1. Show data\n";
        cout << "\t2. Add book\n";
        cout << "\t3. Search data\n";
        cout << "\t4. Delete data\n";
        cout << "\t5. Update record\n";
        cout << "\t6. Exit\n";
        cin >> value;
        switch (value) {
            case 1:
                showdata();
                break;
            case 2:
                addbook();
                break;
            case 3:
                searchdata();
                break;
            case 4:
                deletedata();
                break;
            case 5:
                updaterecord();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
    return 0;
}
