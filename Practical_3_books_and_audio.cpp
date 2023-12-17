#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter the title: ";
        getline(cin, title);
        cout<<endl;
        cout << "Enter the price: ";
        cin >> price;
        cin.ignore(); // 
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Book : public Publication {
private:
    long int pageCount;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter the page count: ";
        cin >> pageCount;
    }

    void putdata() const {
        Publication::putdata();
        cout << "Page Count: " << pageCount << " pages" << endl;
    }
};


class Tape : public Publication {
private:
    float playingTime;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter the Playing Time:  ";
        cin >> playingTime;
    }

    void putdata() const {
        Publication::putdata();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};


int main() {
    Book book;
    Tape tape;

    cout << "Enter data for the book:" << endl;
    book.getdata();

    cout << "\nEnter data for the tape:" << endl;
    tape.getdata();

    cout << "\nBook information:" << endl;
    book.putdata();

    cout << "\nTape information:" << endl;
    tape.putdata();

    return 0;
}
