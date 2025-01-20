#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;
    Book(int bookID, string bookTitle, string bookAuthor) {
        id = bookID;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;  
    }
};

int bookCount = 0;
Book* books[MAX_BOOKS]; 

int main() {
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl;

    while (true) {
        int choice;
        cout << "\n1. Add Book  2. Issue Book  3. Return Book  4. Search Book  5. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1 && bookCount < MAX_BOOKS) {  
            int id;
            string title, author;
            cout << "Book ID: ";
            cin >> id;
            cin.ignore(); 
            cout << "Title: ";
            getline(cin, title);
            cout << "Author: ";
            getline(cin, author);
            books[bookCount++] = new Book(id, title, author); 
            cout << "Book added successfully" << endl;
        }
        else if (choice == 2) {  
            int id, found = 0;
            cout << "Book ID to issue: ";
            cin >> id;
            for (int i = 0; i < bookCount; i++) {
                if (books[i]->id == id) {
                    found = 1;
                    if (books[i]->isIssued) 
                        cout << "Already issued.\n";
                    else {
                        cout << "Issued successfully.\n";
                        books[i]->isIssued = true; 
                    }
                }
            }
            if (!found) 
                cout << "Book not found.\n";
        }
        else if (choice == 3) { 
            int id, found = 0;
            cout << "Book ID to return: ";
            cin >> id;
            for (int i = 0; i < bookCount; i++) {
                if (books[i]->id == id) {
                    found = 1;
                    if (!books[i]->isIssued) 
                        cout << "Not issued.\n";
                    else {
                        cout << "Returned successfully.\n";
                        books[i]->isIssued = false; 
                    }
                }
            }
            if (!found) 
                cout << "Book not found.\n";
        }
        else if (choice == 4) {  
            cin.ignore();  
            string query;
            cout << "Search title/author: ";
            getline(cin, query);
            for (int i = 0; i < bookCount; i++) {
                if (books[i]->title.find(query) != string::npos || books[i]->author.find(query) != string::npos) {
                    cout << "ID: " << books[i]->id << ", Title: " << books[i]->title << ", Author: " 
                         << books[i]->author << ", Issued: " << (books[i]->isIssued ? "Yes" : "No") << '\n';
                }
            }
        }
        else if (choice == 5) break; 
        else cout << "Invalid choice.\n";
    }
    
    for (int i = 0; i < bookCount; i++) {
        delete books[i]; 
    }

    return 0;
}
