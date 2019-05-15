/***********************
Name: The Enums Practicer
Author: Zach Thompson
Version: 1.0 5/8/2019
Purpose: To practice using enums
************************/

#include <iostream>
#include <cmath>
#include <exception>

using namespace std;

//This sets up my enums
enum weekday {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
enum yearmonth {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

// Here is my overloaded operators
weekday operator+(weekday day, int days) {
	return weekday((int(day) + days) % 7);
}

ostream& operator<< (ostream &strm, weekday day) {
	switch(int(day)) {
	case SUNDAY:    strm << "Sunday"; break;
	case MONDAY:    strm << "Monday"; break;
	case TUESDAY:   strm << "Tuesday"; break;
	case WEDNESDAY: strm << "Wednesday"; break;
	case THURSDAY:  strm << "Thursday"; break;
	case FRIDAY:    strm << "Friday"; break;
	case SATURDAY:  strm << "Saturday"; break;
	default:        strm << "Somewhere inside the depths of time..."; break;
	}
	return strm;
}

yearmonth operator+(yearmonth month, int months) {
	return yearmonth((int(month) + months) % 7);
}

ostream& operator<< (ostream &strm, yearmonth month) {
	switch(int(month)) {
	case JANUARY:   strm << "January"; break;
    case FEBRUARY:  strm << "February"; break;
    case MARCH:     strm << "March"; break;
    case APRIL:     strm << "April"; break;
    case MAY:       strm << "May"; break;
    case JUNE:      strm << "June"; break;
    case JULY:      strm << "July"; break;
    case AUGUST:    strm << "August"; break;
    case SEPTEMBER: strm << "September"; break;
    case OCTOBER:   strm << "October"; break;
    case NOVEMBER:  strm << "November"; break;
    case DECEMBER:  strm << "December"; break;
	default:        strm << "Somewhere inside the depths of time..."; break;
	}
	return strm;
}

// This function I copied from an earlier assignment
bool leapYear(int numberOfYear) {
    //Variable 'leapYear' is to store the result
    bool leapYear = false;

    //A series of control statements to be able figure out whether the year is leap or common
    //I use the modulus to be able to figure out if it divides evenly or not
    if ((numberOfYear % 4) == 0) {
        if ((numberOfYear % 400) == 0) {
            leapYear = true;
        }
        else if ((numberOfYear % 100) != 0) {
            leapYear = true;
        }
        else {
            leapYear = false;
        }
    }
    else {
        leapYear = false;
    }
    return leapYear;
}

// This is my calendar class
class Calendar {
    public:
        Calendar(int numberOfDay, int numberOfMonth, int numberOfYear);
        void print(weekday day, yearmonth month);
    private:
        int numberOfDay = 0;
        int numberOfMonth = 0;
        int numberOfYear = 0;
};

// The class constructor
Calendar::Calendar(int numberOfDay, int numberOfMonth, int numberOfYear) {
    this->numberOfDay = numberOfDay;
    this->numberOfMonth = numberOfMonth;
    if (numberOfYear < 1970) {
        throw string("[!] It must be a year 1970 or later!");
    }
    this->numberOfYear = numberOfYear;
}

// The class print method
void Calendar::print(weekday day, yearmonth month) {
    // Setting some variables so that I do not change the main ones
    int localMonth = this->numberOfMonth;
    int localYear = this->numberOfYear - 2;
    int numberOfYearsSince1970 = this->numberOfYear - 1970;
    int numberOfDaysSinceEpoch = 0;
    int leapYearCounter = 0;
    // This is to figure out the day of the week
    // I used the code from an earlier assignment for this
    if (localMonth <= 0) {
        localMonth += 12;
        localYear -= 1;
    }
    localMonth *= 83;
    localMonth /= 32;
    localMonth += this->numberOfDay - 1;
    localMonth += localYear;
    localMonth += round(localYear / 4);
    localMonth -= round(localYear / 100);
    localMonth += round(localYear / 400);
    int dayOfWeek = localMonth % 7 - 1;
    day = day + dayOfWeek;
    localMonth = this->numberOfMonth - 1;
    month = month + localMonth;
    // This to figure out the number of leap years there have been
    for (int i = 0; i < numberOfYearsSince1970; i++) {
        if (leapYear(i + 1970)) {
            leapYearCounter++;
        }
    }
    // This sets the number of days in February for this last year
    int daysInFebruary = 28;
    if (leapYear(this->numberOfYear)) {
        daysInFebruary++;
    }
    // This sets the number of days in the final year
    switch (this->numberOfMonth) {
        case 1: numberOfDaysSinceEpoch = this->numberOfDay - 1; break;
        case 2: numberOfDaysSinceEpoch = 31 + this->numberOfDay - 1; break;
        case 3: numberOfDaysSinceEpoch = 31 + daysInFebruary + this->numberOfDay - 1; break;
        case 4: numberOfDaysSinceEpoch = 31 + daysInFebruary + 31 + this->numberOfDay - 1; break;
        case 5: numberOfDaysSinceEpoch = 31 + daysInFebruary + 31 + 30 + this->numberOfDay - 1; break;
        case 6: numberOfDaysSinceEpoch = 31 + daysInFebruary + 31 + 30 + 31 + this->numberOfDay - 1; break;
        case 7: numberOfDaysSinceEpoch = 31 + daysInFebruary + 31 + 30 + 31 + 30 + this->numberOfDay - 1; break;
        case 8: numberOfDaysSinceEpoch = 31 + daysInFebruary + 31 + 30 + 31 + 30 + 31 + this->numberOfDay - 1; break;
        case 9: numberOfDaysSinceEpoch = 31 + daysInFebruary + 31 + 30 + 31 + 30 + 31 + 31 + this->numberOfDay - 1; break;
        case 10: numberOfDaysSinceEpoch = 31 + daysInFebruary + 31 + 30 + 31 + 30 + 31 + 31 + 30 + this->numberOfDay - 1; break;
        case 11: numberOfDaysSinceEpoch = 31 + daysInFebruary + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + this->numberOfDay - 1; break;
        case 12: numberOfDaysSinceEpoch = 31 + daysInFebruary + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + this->numberOfDay - 1; break;
    }
    // This sets the number of days in previous years
    if (this->numberOfYear > 1970) {
        numberOfDaysSinceEpoch += 365 * numberOfYearsSince1970 + leapYearCounter;
    }
    // This prints it out
    cout << this->numberOfDay << " " << month << " " << this->numberOfYear << " - " << day << " - " << numberOfDaysSinceEpoch << " since 1st January 1970!" << endl;
}

int main(void) {
	weekday day = SUNDAY;
	yearmonth month = JANUARY;
	int numberOfDay, numberOfMonth, numberOfYear;
	cout << "Please enter the number of a day of the month: ";
	cin >> numberOfDay;
	cout << "Please enter the number of a month: ";
	cin >> numberOfMonth;
	cout << "Please enter the number of a year: ";
	cin >> numberOfYear;
	try {
        Calendar calendar(numberOfDay, numberOfMonth, numberOfYear);
        calendar.print(day, month);
	}
	catch (string phrase) {
        cout << phrase << endl;
	}
	return 0;
}
