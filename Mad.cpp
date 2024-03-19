#include <iostream>
#include <string>
using namespace std;


void addbook();


string book_ID[20], book_name[20], book_author[20];
int book_pr[20];
int total = 0;


void showdata()

{
	if (total == 0)

	{
		char choice;
		cout << "No books to show.\n";
		cout << "Do you want to add a book? (y/n): ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')

		{
			addbook(); 
		}

		else

		{
			return;
		}

	}

	cout << "No. of books: " << total << endl;


	for (int i = 0; i < total; i++)

	{
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


void addbook()

{
	int ch = 0;
	cout << "Enter number of books you want to add: ";
	cin >> ch;
	for (int i = total; i < total + ch; i++)

	{
		cout << "\t\tEnter the detail of book\n\n";
		cout << "\tBook Name: ";
		cin.ignore(); 
		getline(cin, book_name[i]);
		cout << "\tBook ID: ";
		cin >> book_ID[i];
		cout << endl; 
		cout << "\tEnter book author: ";
		cin.ignore(); 
		getline(cin, book_author[i]); 
		cout << endl;
		cout << "\tEnter book price: ";
		cin >> book_pr[i];
		cout << endl; 
	}
	total += ch;

}

void deletedata()

{
	string bookno;
	cout << "Enter book ID to delete data: ";
	cin >> bookno;
	bool found = false;

	for (int i = 0; i < total; i++)

	{
		if (bookno == book_ID[i])

		{
			found = true;
			
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


	if (!found)

	{
		cout << "Book not found" << endl;
	}
}

int main()

{
	int value;
	while (true)

	{
		cout << "\n~~~~"
		     << "~~~~"
		     << "WELCOME~~~"
		     << "~~~~"
		     << "~\n\n";
		cout << "Enter your choice\n";
		cout << "\t1. Show data\n";
		cout << "\t2. Add book\n";
		cout << "\t4. Delete data\n";
		cin >> value;
		switch (value)

		{
			case 1:
				showdata();
				break;
			case 2:
				addbook();
				break;
			case 4:
				deletedata();
				break;
			default:
				cout << "Invalid input" << endl;
				break;
		}

	}

	return 0;

}
