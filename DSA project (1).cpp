#include <iostream>
#include <string>
using namespace std;

struct book {
    int id;
    string title;
    string author;
    string type;
    int year;
    book* next;
    book* prev;
};

// head pointer
book* head = NULL;

// create new node
book* createbook(int id, string title, string author, string type, int year) {
    book* newbook = new book;
    newbook->id = id;
    newbook->title = title;
    newbook->author = author;   // FIXED (autor → author)
    newbook->type = type;
    newbook->year = year;
    newbook->next = NULL;       // FIXED
    newbook->prev = NULL;
    return newbook;
}

// insert at end
void insertEnd(int id, string title, string author, string type, int year) {
    book* newbook = createbook(id, title, author, type, year);

    if (head == NULL) {
        head = newbook;
        cout << "\nBook added as the first record!\n";
        return;
    }

    book* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newbook;
    newbook->prev = temp;

    cout << "\nBook added at the end!\n";
}

// insert at beginning
void insertBeginning(int id, string title, string author, string type, int year) {
    book* newbook = createbook(id, title, author, type, year);

    if (head == NULL) {
        head = newbook;
        cout << "\nBook added as the first record!\n";
        return;
    }

    newbook->next = head;
    head->prev = newbook;
    head = newbook;

    cout << "\nBook inserted at beginning!\n";
}

// insert at middle
void insertMiddle(int pos, int id, string title, string author, string type, int year) {
    if (pos == 1) {
        insertBeginning(id, title, author, type, year);
        return;
    }

    book* newbook = createbook(id, title, author, type, year);
    book* temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "\nInvalid position!\n";
        return;
    }

    newbook->next = temp->next;
    newbook->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newbook;

    temp->next = newbook;

    cout << "\nBook inserted at position " << pos << "!\n";
}

// display books
void display() {
    if (head == NULL) {
        cout << "\nNo books available!\n";
        return;
    }

    book* temp = head;
    cout << "\n--- All Library Books ---\n";
    while (temp != NULL) {
        cout << "\nID: " << temp->id;
        cout << "\nTitle: " << temp->title;
        cout << "\nAuthor: " << temp->author;
        cout << "\nType: " << temp->type;
        cout << "\nYear: " << temp->year;
        cout << "\n------------------------";
        temp = temp->next;
    }
    cout << endl;
}

// search by ID
void searchByID(int id) {
    book* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "\nBook Found!";
            cout << "\nTitle: " << temp->title;
            cout << "\nAuthor: " << temp->author;
            cout << "\nType: " << temp->type;
            cout << "\nYear: " << temp->year << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "\nBook with ID " << id << " not found!\n";
}

// delete book
void deleteBook(int id) {
    if (head == NULL) {
        cout << "\nList is empty!\n";
        return;
    }

    book* temp = head;

    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL) {
        cout << "\nBook not found!\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "\nBook deleted successfully!\n";
}

// update book
void updateBook(int id) {
    book* temp = head;

    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL) {
        cout << "\nBook not found!\n";
        return;
    }

    cin.ignore();
    cout << "\nEnter new title: ";
    getline(cin, temp->title);

    cout << "Enter new author: ";
    getline(cin, temp->author);

    cout << "Enter new type: ";
    getline(cin, temp->type);

    cout << "Enter new year: ";
    cin >> temp->year;

    cout << "\nBook updated successfully!\n";
}

// count books
void countBooks() {
    int count = 0;
    book* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "\nTotal Books: " << count << endl;
}

// sort books by ID
void sortBooks() {
    if (head == NULL || head->next == NULL)
        return;

    for (book* i = head; i->next != NULL; i = i->next) {
        for (book* j = i->next; j != NULL; j = j->next) {
            if (i->id > j->id) {
                swap(i->id, j->id);
                swap(i->title, j->title);
                swap(i->author, j->author);
                swap(i->type, j->type);
                swap(i->year, j->year);
            }
        }
    }

    cout << "\nBooks sorted by ID!\n";
}

// main
int main() {
    int choice, id, year, pos;
    string title, author, type;

    while (true) {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book at End";
        cout << "\n2. Insert at Beginning";
        cout << "\n3. Insert at Middle";
        cout << "\n4. Display All Books";
        cout << "\n5. Search Book by ID";
        cout << "\n6. Delete Book";
        cout << "\n7. Update Book";
        cout << "\n8. Count Books";
        cout << "\n9. Sort Books";
        cout << "\n10. Exit";
        cout << "\n--------------------------------------";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Type: ";
            getline(cin, type);
            cout << "Enter Year: ";
            cin >> year;
            insertEnd(id, title, author, type, year);
            break;

        case 2:
            cout << "\nEnter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Type: ";
            getline(cin, type);
            cout << "Enter Year: ";
            cin >> year;
            insertBeginning(id, title, author, type, year);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Type: ";
            getline(cin, type);
            cout << "Enter Year: ";
            cin >> year;
            insertMiddle(pos, id, title, author, type, year);
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "\nEnter Book ID to search: ";
            cin >> id;
            searchByID(id);
            break;

        case 6:
            cout << "\nEnter Book ID to delete: ";
            cin >> id;
            deleteBook(id);
            break;

        case 7:
            cout << "\nEnter Book ID to update: ";
            cin >> id;
            updateBook(id);
            break;

        case 8:
            countBooks();
            break;

        case 9:
            sortBooks();
            break;

        case 10:
            cout << "\nExiting... Goodbye!\n";
            return 0;

        default:
            cout << "\nInvalid choice!\n";
        }
    }
}