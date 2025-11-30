#include <iostream> //for input and output
#include <exception> //for exception library to use try,catch,throw
#include <sstream> //convert string to int
using namespace std;
//Class Declaration and implementation
//Exception class for invalid Month
class invalidMonth:public exception {
    string month;
public:
    invalidMonth(string) { this->month = month; }

    string getMonth() { return month; }

    virtual const char *what() const throw() { return "Month out of range!"; }

    virtual ~invalidMonth() throw() {}
};
//Exception class for invalid Day
class invalidDay:public exception {
    string day;
public:
    invalidDay(string) { this->day = day; }
    string getDay() { return day; }
    virtual const char* what() const throw() { return "Day out of range!"; }
    virtual ~invalidDay() throw() {}
};
//Exception class for invalid Year
class invalidYear:public exception{
        string year;
public:
invalidYear (string){ this->year = year; }
string getYear(){ return year; }
virtual const char* what() const throw(){ return "Year out of range!"; }
virtual ~invalidYear() throw(){}
};

void validateMonth(string&); //function to validate the month
void validateDay(string&, string&, string&); //function to check the day
void validateYear(string&); //function to check the year

int main() {
//variable declaration
    string date;
    string day, month, year;
//promt user to input birth date
    cout << "Enter Birth Date(e.g. 8-27-1980): ";
    cin >> date;
    try {
//separate user input into day, month year
        year = date.substr(date.rfind("-") + 1, date.size() - 1);
        month = date.substr(0, date.find("-"));
        day = date.substr(date.find("-")+1 , date.size() - 7); //date.find0+1 is to eliminate the
//do validation on year, day, month
        validateYear(year);
        validateDay(day, month, year);
        validateMonth(month);
    }
//if exception occur, capture it and print out the issues
        catch (exception & e) {
            cout << "An exception occurred. Exception: " << e.what() << endl;
            return 0;
        }

    cout << "Date of Birth: " << month << " " << day << ", " << year << endl;
}
//function to check the Year
void validateYear(string& year) {
//create stringstream and convert string to int
        stringstream forYear(year);
        int iYear;
        forYear >> iYear;
//check if year smaller than 1583, throw exception
        if (iYear < 1583) {
            invalidYear yearRange(year);
            throw yearRange;
        }
    }
//function to check the Month
void validateMonth(string &month){
//check the month and translate from digit to english
//if the montht is out of range(1-12), throw exception
    if(month == "1"){
    month = "January";
    } else if(month =="2"){
    month = "February";
    } else if(month == "3"){
    month = "March";
    } else if(month =="4"){
    month = "April";
    } else if(month == "5"){
    month = "May";
    } else if (month == "6"){
    month = "June";
    } else if(month == "7"){
    month = "July";
    } else if(month == "8"){
    month = "August";
    } else if(month == "9"){
    month = "September";
    } else if(month == "10"){
    month = "October";
    } else if(month == "11"){
    month = "November";
    } else if(month =="12"){
    month = "December";
    } else {
        invalidMonth monthRange(month);
        throw monthRange;
    }
}
//function to check the Day
void validateDay(string &day, string &month, string &year){
    int iYear, iMonth, iDay;
    //create stringstream and convert string to int
    stringstream forYear(year);
    stringstream forMonth(month);
    stringstream forDay(day);
    forYear >> iYear;
    forMonth >> iMonth;
    forDay >> iDay;
    //check the day from which month and year, then decide the maxinum
    if(iMonth == 1 || iMonth == 3 || iMonth == 5 || iMonth == 7
        || iMonth == 8 || iMonth == 10 || iMonth == 12){
        if (iDay > 31) {
            invalidDay rangeDay(day);
            throw rangeDay;
        }
    } else if(iMonth ==2) {
        if(iYear % 4 == 0 || (iYear % 100 == 0 && iYear % 400 ==0)){
            if(iDay > 29){
            invalidDay rangeDay(day);
            throw rangeDay;
            }
        } else if(iDay > 28){
        invalidDay rangeDay(day);
        throw rangeDay;
         throw rangeDay;
        }
    } else {
    if(iDay > 30){
        invalidDay rangeDay(day);
        throw rangeDay;
            }
        }
}