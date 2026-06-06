#include <iostream>
#include <string>

using namespace std;

class LibraryUser {
public:
    virtual void registerAccount() = 0;
    virtual void requestBook() = 0;
    virtual ~LibraryUser() {}
};

class KidUser : public LibraryUser {
public:
    int age;
    string bookType;

    KidUser(int age, string bookType) {
        this->age = age;
        this->bookType = bookType;
    }

    void registerAccount() override {
        if (age < 12) {
            cout << "You have successfully registered under a Kids Account" << endl;
        } else {
            cout << "Sorry, Age must be less than 12 to register as a kid" << endl;
        }
    }

    void requestBook() override {
        if (bookType == "Kids") {
            cout << "Book Issued successfully, please return the book within 10 days" << endl;
        } else {
            cout << "Oops, you are allowed to take only kids books" << endl;
        }
    }
};

class AdultUser : public LibraryUser {
public:
    int age;
    string bookType;

    AdultUser(int age, string bookType) {
        this->age = age;
        this->bookType = bookType;
    }

    void registerAccount() override {
        if (age > 12) {
            cout << "You have successfully registered under an Adult Account" << endl;
        } else {
            cout << "Sorry, Age must be greater than 12 to register as an adult" << endl;
        }
    }

    void requestBook() override {
        if (bookType == "Fiction") {
            cout << "Book Issued successfully, please return the book within 7 days" << endl;
        } else {
            cout << "Oops, you are allowed to take only adult Fiction books" << endl;
        }
    }
};

int main() {
    KidUser kid1(10, "Kids");
    kid1.registerAccount();
    kid1.requestBook();

    KidUser kid2(18, "Fiction");
    kid2.registerAccount();
    kid2.requestBook();

    AdultUser adult1(5, "Kids");
    adult1.registerAccount();
    adult1.requestBook();

    AdultUser adult2(23, "Fiction");
    adult2.registerAccount();
    adult2.requestBook();

    return 0;
}