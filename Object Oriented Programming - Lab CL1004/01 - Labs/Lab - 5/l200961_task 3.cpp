#include <iostream>
#include <ctime>
using namespace std;

class MyDate{
    int Day;
    int Month;
    int Year;
public:
    MyDate(){
        Day=Month=Year=0;
    }
    void Input() {
        int dd, mm, yyyy;
        cout << "dd mm yyyy";
        cin >> dd >> mm >> yyyy;
        SetDay(dd), SetMonth(mm), SetYear(yyyy);
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

void age(int currentDay, int currentMonth, int currentYear, int dob_Day, int dob_Month, int dob_Year)
{
    int d, m, y;
    int daysinMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    y = currentYear - dob_Year;
    if (currentMonth < dob_Month)
    {
        y--;
        m = 12 - (dob_Month - currentMonth);
    }
    else
    {m = currentMonth - dob_Month;}
    if (currentDay < dob_Day)
    {
        m--;
        d = daysinMonth[currentMonth - 1] - (dob_Day - currentDay);
    }
    else
    {d = currentDay - dob_Day;}
    cout << "your age is : \n";
    cout << y << " years " << m << " months " << d << " days. ";
}

int main()
{
    MyDate d;
    cout<<"ENTER DOB ";
    d.Input();

    // the required logic for current date
    time_t t = time(NULL);
    tm* TIME = localtime(&t);
    int currentDay=(TIME->tm_mday);
    int currentMonth =(TIME->tm_mon) + 1;
    int currentYear=(TIME->tm_year) + 1900;
    cout << " Current Date: " << currentDay << "/" << currentMonth << "/" << currentYear << endl;

    age(currentDay,currentMonth,currentYear,d.GetDay(),d.GetMonth(),d.GetYear());

    return 0;
}

