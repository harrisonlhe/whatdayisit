//This program allows users to input a date and returns what day
//that date was on. It uses the standard Gregorian calendar.
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <sstream>
#include <map>

using namespace std;

typedef map<int, int> BasePairMap;
typedef map<int, string> CalendarMap;
map <int, int>::iterator it;
map <int, string>::iterator it2;

//REQUIRES: day is a valid day: 1 <= day <= 31
//          month is a valid month: 1 <= month <= 12
//where 1 is march, 11 is jan, and 12 is feb
//          century is a valid century: century >= 0
//(+1, such that 1987 is "19th century")
//          year is a valid year: year >= 0 
//(years start in march, so year = 0 for jan of year 1)
//MODIFIES: nothing is pass-by-reference
//EFFECTS: returns codified int for a specific day of the week, where
//1 = sunday, 2 = monday, 3 = tuesday, 4 = wednesday, 5 = thursday
//6 = friday, 7 = saturday
int whatdayisit(int day, int month, int century, int year) {
    int dotw;
    dotw = ((int)day + (int)floor(2.6 * month - 0.2) - (int)(2 * century) + (int)year +
           (int)floor(year / 4) + (int)floor(century / 4)) % 7;
    return dotw;
}

int main() {
    int month;
    int day;
    int yr;
    int century;
    int endyr;
    int dotwnum;
    bool isdaygood = true;
    bool isleapyear = false;
    cout << "Input a valid year" << endl;
    cin >> yr;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You didn't enter a valid year\nno years over 10000" << endl;
        cin >> yr;
    }
    while (yr < 0 || yr >= 10000) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You didn't enter a valid year\nno years over 10000" << endl;
        cin >> yr;
    }
    if (yr == 0) {
        century = 0;
        endyr = 0;
    }
    else if (yr > 0 && yr < 100) {
        century = 0;
        endyr = yr;
    }
    else {
        century = yr / 100;
        endyr = yr % 100;
    }
    cout << "Input a valid month (1-12)" << endl;
    cin >> month;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You didn't enter a valid month" << endl;
        cin >> month;
    }
    while (month < 1 || month > 12) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You didn't enter a valid month" << endl;
        cin >> month;
    }
    cout << "Input a valid day (1-31 for most months, 1-30 or 1-28 for others)" << endl;
    cin >> day;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You didn't enter a valid day" << endl;
        cin >> day;
    }
    while (day < 1 || day > 31) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You didn't enter a valid day" << endl;
        cin >> day;
    }
    if (yr % 4 == 0 && yr % 100 == 0 && yr % 400 != 0) {
        isleapyear = false;
    }
    else if (yr % 4 == 0) {
        isleapyear = true;
    }
    else {
        isleapyear = false;
    }
    if (month == 2) {
        if (day == 30 || day == 31) {
            isdaygood = false;
        }
        if (!isleapyear && day == 29) {
            isdaygood = false;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day == 31) {
            isdaygood = false;
        }
    }
    while (!isdaygood) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You didn't enter a valid day" << endl;
        cin >> day;
    }
    BasePairMap m;
    m[1] = 11; m[2] = 12; m[3] = 1;
    m[4] = 2; m[5] = 3; m[6] = 4;
    m[7] = 5; m[8] = 6; m[9] = 7;
    m[10] = 8; m[11] = 9; m[12] = 10;

    for (it = m.begin(); it != m.end(); ++it) {
        if (it->first == month) {
            month = it->second;
            break;
        }
    }
    m.erase(it);
    CalendarMap c;
    c[0] = "Sunday"; c[1] = "Monday"; c[2] = "Tuesday";
    c[3] = "Wednesday"; c[4] = "Thursday"; c[5] = "Friday";
    c[6] = "Saturday";
    dotwnum = whatdayisit(day, month, century, endyr);
    for (it2 = c.begin(); it2 != c.end(); ++it2) {
        if (it2->first == dotwnum) {
            cout << it2->second << endl;
            break;
        }
    }
    c.erase(it2);
}