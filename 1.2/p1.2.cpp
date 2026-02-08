#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int bookID;
    string title;
    string author;
    int copies;

    void addBook() {
        cout << "Enter Book ID: ";
        cin >> bookID;

        cout << "Enter Title : ";
        cin >> title;

        cout << "Enter Author Name (no spaces): ";
        cin >> author;

        cout << "Enter Number of Copies: ";
        cin >> copies;
    }

    void issueBook() {
        if (copies > 0) {
            copies--;
            cout << "Book issued successfully\n";
        } else {
            cout << "No copies available\n";
        }
    }

    void returnBook() {
        copies++;
        cout << "Book returned successfully\n";
    }

    void displayBook() {
        cout << bookID << " | " << title << " | "
             << author << " | Copies: " << copies << endl;
    }
};

int main() {
    Book books[10];
    int count = 0;
    int choice = 0;
    int id;

    while (choice != 5) {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            books[count].addBook();
            count++;
            break;

        case 2:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (books[i].bookID == id) {
                    books[i].issueBook();
                    break;
                }
            }
            break;

        case 3:
            cout << "Enter Book ID to return: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (books[i].bookID == id) {
                    books[i].returnBook();
                    break;
                }
            }
            break;

        case 4:
            cout << "\nLibrary Books:\n";
            for (int i = 0; i < count; i++) {
                books[i].displayBook();
            }
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
