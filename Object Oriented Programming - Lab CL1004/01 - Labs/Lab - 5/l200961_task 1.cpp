#include<iostream>
using namespace std;

class Date {
private:
    int Day;
    int Month;
    int Year;
public:
    // Exercise 2 "Default constructor called" printed
    Date() {
        Day = 1;
        Month = 1;
        Year = 1926;
        cout << "Default constructor called\n";
    }

    void Print(){
        cout<<Day<<"/"<<Month<<"/"<<Year<<"\n";
    }

    // Exercise 4
    Date(int dd, int mm, int yyyy) {
        Day = dd;
        Month = mm;
        Year = yyyy;
        cout<<"Overloaded Function Called\n";
    }

    void Input() {
        int dd, mm, yyyy;
        cout << "dd ";
        cin >> dd;
        cout << "mm ";
        cin >> mm;
        cout << "yyyy ";
        cin >> yyyy;
        Day = dd;
        Month = mm;
        Year = yyyy;
    }

    void SetDay(int in){
        Day=in;
    }
    void SetMonth(int in){
        Month=in;
    }
    void SetYear(int in){
        Year=in;
    }

    int GetDay(){
        return Day;
    }
    int GetMonth(){
        return Month;
    }
    int GetYear(){
        return Year;
    }
};

int main()
{
    // Exercise 1
    Date date1;

    // Exercise 3 it prints "1/1/1926" we can initialise by using the parameterized constructor
    date1.Print();

    Date independanceDay(14,8,2020);
    independanceDay.Print();

    // using date1 to populate with current date i.e. "30 3 2020"
    date1.Input();
    date1.Print();

    Date xmasDay;
    xmasDay.Print();
    xmasDay.SetDay(25);xmasDay.SetMonth(12);xmasDay.SetYear(2020);
    cout<<"xmasDay\n";
    cout<<xmasDay.GetDay()<<"/"<<xmasDay.GetMonth()<<"/"<<xmasDay.GetYear()<<"\n";


    return 0;
}