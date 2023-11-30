using namespace std;
#include<iostream>

class Book {
public:
    string author, title, publisher;
    double price;
    int stockPos;
    Book(string authorParam = "", string titleParam = "", string publisherParam = "", double priceParam = 0) {
        author = authorParam;
        title = titleParam;
        publisher = publisherParam;
        price = priceParam;
    }
    void display();
};

void Book::display() {
    cout << "Author : " << author << endl;
    cout << "Title : " << title << endl;
    cout << "Publisher : " << publisher << endl;
    cout << "Price : " << price << endl;
}

struct Vector {
    int a;
    Book b;
};

class BookStore {
public:
    // BookStore();
    int i = 0;
    Book *books = new Book[10];
    void enter();
    Vector search(string, string);
    double totalPrice(int, Book);
    void removeBooks(Book, int);
};

void BookStore::enter() {
    cout << "Enter author name : ";
    // getline(cin, books[i].author);
    cin >> books[i].author;
    cout << "Enter title : ";
    // getline(cin, books[i].title);
    cin >> books[i].title;
    cout << "Enter publisher : ";
    // getline(cin, books[i].publisher);
    cin >> books[i].publisher;
    cout << "Enter price : ";
    cin >> books[i].price;
    i++;
}

double BookStore::totalPrice(int copies, Book b) {
    return b.price*copies;
}

Vector BookStore::search(string a, string b) {
    int cnt = 0;
    int j;
    Vector v;
    for (int i = 0; i < 10; i++) {
        if(a == books[i].author && b == books[i].title) {
            cnt++;
            j = i;
        }
    }
    // cout << cnt;
    v.a = cnt;
    v.b = books[j];
    return v;
}

void BookStore::removeBooks(Book b, int copiesToRemove) {
    int cnt = 0;
    for (int i = 0; i < 10 && cnt < copiesToRemove; i++) {
        if (b.author == books[i].author && b.title == books[i].title) {
            books[i].author = "";
            books[i].title = "";
            books[i].publisher = "";
            books[i].price = 0;
            cnt++;
        }
    }
}

int main() {
    int choice, copies, copiesAvailable;
    Book requiredBook;
    Vector v;
    string author, title;
    BookStore store;
    while (1) {
        cout << "\nMENU\nPress 1 to enter a book.\nPress 2 to search for a book.\nPress 3 to exit.\n";
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            store.enter();
            break;
        case 2:
            cout << "Enter author name : ";
            // getline(cin, author);
            cin >> author;
            cout << "Enter title : ";
            // getline(cin, title);
            cin >> title;
            v = store.search(author, title);
            copiesAvailable = v.a;
            requiredBook = v.b;
            if (copiesAvailable > 0) {
                cout << "Enter number of copies : ";
                cin >> copies;
                if (copies <= copiesAvailable) {
                    store.removeBooks(requiredBook, copies);
                    cout << "Total price : " << store.totalPrice(copies, requiredBook) << endl;
                } else {
                    cout << "Required copies not in stock." << endl;
                }
            } else {
                cout << "Sorry, not available." << endl;
            }
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}