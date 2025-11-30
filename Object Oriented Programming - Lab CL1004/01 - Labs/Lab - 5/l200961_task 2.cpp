#include<iostream>
using namespace std;

class Book{
    // Bookid, Pages, Price
    int Bookid;
    int Pages;
    int Price;
public:
    Book(){
        Bookid=Pages=Price=0;
    }
    Book(int id,int pg, int pr){
        Bookid=id;
        Pages=pg;
        Price=pr;
    }
    void SetBookid(int in){
        Bookid=in;
    }
    void SetPages(int in){
        Pages=in;
    }
    void SetPrice(int in){
        Price=in;
    }
    int GetBookid(){
        return Bookid;
    }
    int GetPages(){
        return Pages;
    }
    int GetPrice(){
        return Price;
    }

    void printDetails(){
        cout<<"Bookid"<<GetBookid()<<"Pages"<<GetPages()<<"Price"<<GetPrice()<<"\n";
    }
};

int main() {
    int id, pages, price;
    Book b1;
    cout << "Enter book details id, pages, price ";
    cin >> id >> pages >> price;
    b1.SetBookid(id), b1.SetPages(pages), b1.SetPrice(price);
	
	

    Book b2(9999, 400, 999);

    Book b3;
    b3.SetBookid(9999), b3.SetPages(9999), b3.SetPrice(100);

    int n1 = b1.GetPrice(), n2 = b2.GetPrice(), n3 = b3.GetPrice();

    if (n1 >= n2 && n1 >= n3)
        cout << "Largest : " << n1;

    if (n2 >= n1 && n2 >= n3)
        cout << "Largest : " << n2;

    if (n3 >= n1 && n3 >= n2)
        cout << "Largest : " << n3;

    return 0;
}