#include <iostream>
#include <cstring>
using namespace std;

// Forward declaration for necessary action
class Author;
class Book;

class Author {
	string name;
	string email;
	char gender;   

public:
	Author(const string& name, const string& email, char gender);
	string getName() const;
	string getEmail() const;
	void setEmail(const string& email);
    void setName(const string& name);
    char getGender() const;
	void print() const;
};

class Book {
    string name;
    Author author;
    double price;
    int qtyInStock = 0;

public:
    Book(string name, Author& author, double price, int qtyInStock=0);
    string getName();
    Author getAuthor();
    void setPrice(double price);
    double getPrice() const;
    int getQtyInStock() const;
    void setQtyInStock(int qtyInStock);
    void print();
    string getAuthorName();
};


int main()
{
	// Declare and construct an instance of Author
	Author peter("Peter Jones", "peter@somewhere.com", 'm');
	peter.print(); // Peter Jones (m) at peter@somewhere.com
	// Declare and construct an instance of Book
	Book book("C++ for Dummies", peter, 19.99);
	book.print();
	// 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com
	peter.setEmail("peter@xyz.com");
	peter.print(); // Peter Jones (m) at peter@xyz.com
	book.print();
	// 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com
	book.getAuthor().setEmail("peter@abc.com");
	book.print();
	// 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com

	return 0;
}

Book::Book(string name, Author& author, double price, int qtyInStock) : name(name), author(author) {
    author.setName(name);
    setPrice(price);
    setQtyInStock(qtyInStock);
}

string Book::getName()  {
    return name;
}

Author Book::getAuthor()  {
    return author;
}

void Book::setPrice(double price) {
    this->price = price;

}

double Book::getPrice() const {
    return price;
}

int Book::getQtyInStock() const  {
    return qtyInStock;
}

void Book::setQtyInStock(int qtyInStock) {
    this->qtyInStock = qtyInStock;
}

void Book::print()  {
    cout << "'" << getName() << "' by ";
    author.print();
}

string Book::getAuthorName()  {
    return author.getName();
}


Author::Author(const string &name, const string &email, char gender) {
    setName(name);
    setEmail(email);
    if (gender == 'm' || gender == 'f') {
        this->gender = gender;
    }
    else {
        cout << "Invalid gender! Set to 'u' (unknown).\n";
        this->gender = 'u';
    }
}


string Author::getName()  const {
    return name;
}

string Author::getEmail()  const {
    return email;
}

void Author::setEmail(const string &email) {
    // for this method, we need to find a valid at-the-rate-of character '@'
    // i am using a method i found online
    auto char_to_find = '@';
    if (email.find(char_to_find) != string::npos) {
        this->email = email;
    }
    else {
        cout << "Invalid email! Set to empty string." << endl;
        this->email = "";
    }
}

void Author::setName(const string &name) {
    this->name = name;
}

char Author::getGender() const {
    return gender;
}

void Author::print() const {
    cout << getName() << " (" << getGender() << ") at " << getEmail() << "\n";
}