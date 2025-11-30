#include <iostream>
using namespace std;

class Time {
	int hr;
	int min;
public:
	Time();
	Time(int, int);
	void setTime(int, int);
	void getTime(int&, int&);
	void printTime();
	void incrementHours();
	void incrementMinutes();
};

class Date {
	int month;
	int day;
	int year;
public:
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void getDate(int&, int&, int&);
	void printDate();
};

class Event {
	string eventName;
	Time eventTime;
	Date eventDay;
public:
	Event(int hours = 0, int minutes = 0, int m = 1,
		int d = 1, int y = 1900, string name = "Christmas");
	void setEventData(int hours, int minutes, int m, int d, int y, string
	name);
	void printEventData();
};

int main()
{
	//instantiate an object and set data for Christmas
	Event object;
	object.setEventData(6, 0, 12, 25, 2010, "Christmas");
	//print out the data for object
	object.printEventData();
	//instantiate the second object and set date for the fourth of July
	Event object2;
	object2.setEventData(1, 15, 7, 4, 2010, "Fourth of July");
	//print out the data for the second object
	object2.printEventData();

	return 0;
}

Time::Time() {
    hr=min=0;
}

Time::Time(int hours, int minutes) {
    hr=hours;
    min=minutes;
}

void Time::getTime( int& hours, int& minutes) {
    hours=this->hr;
    minutes=this->min;
}
void Time::setTime( int hours, int minutes) {
    this->hr=hours;
    this->min=minutes;
}

void Time::printTime() {
    int getHr, getMin;
    getTime (getHr, getMin);
    if (getHr < 10) cout << "0";
    cout << getHr << ":";
    if (getMin < 10) cout << "0";
    cout << getMin;
}

void Time::incrementHours() {
    hr++;
    if(hr==24)
        hr=0;
}

void Time::incrementMinutes() {
    min++;
    if(min==60) {
        incrementHours();
    }
}

Date::Date() {
    month=day=0;
    year=2000;
}

Date::Date(int m, int d, int y) {
    month=m;
    day=d;
    year=y;
}

void Date::setDate(int m, int d, int y) {
    month=m;
    day=d;
    year=y;
}

void Date::getDate(int &m, int &d, int &y) {
    m=month;
    d=day;
    y=year;
}

void Date::printDate() {
    int m, d, y;
    getDate(m, d, y);
    if (m < 10) cout << "0";
    cout << m << "/";
    if (d < 10) cout << "0";
    cout << d << "/";
    if (y < 100) cout << "20";
    cout << year;
}

Event::Event(int hours, int minutes, int m, int d, int y, string name)  {
    eventName = name;
    eventTime.setTime(hours,minutes);
    eventDay.setDate(m,d,y);
}

void Event::setEventData(int hours, int minutes, int m, int d, int y, string name) {
    eventName = name;
    eventTime.setTime(hours, minutes);
    eventDay.setDate(m, d, y);

}

void Event::printEventData() {
    cout << eventName << " occurs ";
    eventDay.printDate();
    cout << " at ";
    eventTime.printTime();
    cout << "\n";
}