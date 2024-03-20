#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

// Define the Book class
class Book {
public:
    string title;
    string author;
    int year;

    Book(string title, string author, int year)
        : title(title), author(author), year(year) {}
};

// Define the Library class
class Library {
private:
    vector<Book> books;

public:
    // Function to add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Function to remove a book from the library
    void removeBook(const string& title) {
        books.erase(remove_if(books.begin(), books.end(), [&](const Book& b) {
            return b.title == title;
            }), books.end());
    }

    // Function to list all books in the library
    void listBooks() {
        cout << "Books in the library:" << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", Year: " << book.year << endl;
        }
    }
};

void userInterface(Library& lib) {
    string command;
    while (true) {
        cout << "Enter command (add, remove, list, quit): ";
        getline(cin, command);

        if (command == "add") {
            string title, author;
            int year;
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            cin.ignore(); // Ignore newline character
            lib.addBook(Book(title, author, year));
        }
        else if (command == "remove") {
            string title;
            cout << "Enter title of the book to remove: ";
            getline(cin, title);
            lib.removeBook(title);
        }
        else if (command == "list") {
            lib.listBooks();
        }
        else if (command == "quit") {
            break;
        }
        else {
            cout << "Invalid command. Please try again." << endl;
        }
    }
}

int main() {
    Library myLibrary;
    userInterface(myLibrary);
    return 0;
}
