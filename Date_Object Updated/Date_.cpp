#include "Date_.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Checks if all three parts of the date meet the requirements
// to be considered valid

bool Date::ValidDate(int m, int d, int y)
{
    // If the months are less or equal to zero or greater
    // than 12, the date is not valid

    if (m <= 0 || m > 12) return false;

    // If the days are less than or equal to zero or greater
    // than the final day of that month, the date is not valid

    if (d <= 0 || d > lastDay(m, y)) return false;

    // If the year is less than 1900 or greater than 2027,
    // the date is not valid

    if (y < 1900 || y > 2026) return false;

}

//Updates the month, day and year if needed
void Date::CheckDate(int m, int d, int y)
{
    if (day > lastDay(m, y))
    {
        month = month + 1;
        day = 1;
        if (month > 12)
        {
            month = 1;
            year = year + 1;
        }

    }

    else if (day < 0)
    {
        month = month - 1;

        if (month < 0)
        {
            month = 12;
            year = year - 1;

        }

        day = lastDay(month, year);


    }
}

long Date::Conv_Value(int m, int d, int y) noexcept
{
    // Shift months so March is month 1 (to simplify leap-year handling)
    int a = (14 - m) / 12;
    int y2 = y + 4800 - a;
    int m2 = m + 12 * a - 3;
    long jd = d + (153 * m2 + 2) / 5 + 365L * y2 + y2 / 4 - y2 / 100 + y2 / 400 - 32045;
    // jd is Julian Day Number; convert to a serial by subtracting a constant
    return jd;
}


// Date Constructor
Date::Date(int m, int d, int y)
{
    // If the date entered is not valid, the date is set to
    // the default values
    if (ValidDate(m, d, y) == false)
    {
        month = 1;
        day = 1;
        year = 1900;
    }


    // If the date is valid, the values of the dates are set
    // to be equal to the values that were put in 
    else
    {
        month = m;
        day = d;
        year = y;
    }

}

// Allows the user to change the value of an already set date.
void Date::setDate(int m, int d, int y)
{
    // If the values for the new date are invalid, set the date
    // to the default values
    if (ValidDate(m, d, y) == false)
    {
        month = 1;
        day = 1;
        year = 1900;
    }

    // If the values of the date are valid, the new date inputs
    // are the vlaues for the new date
    else
    {
        month = m;
        day = d;
        year = y;
    }

}

bool Date::isLeapYear() const
{
    return isLeapYear(year);
}

//Leap year validation
bool Date::isLeapYear(int y) const
{
    // If the year value is not divisible by four,
    // it is not a leap year
    if (y % 4 != 0)
    {
        return false;
    }

    // If the year value is divisible by 400, it is
    // a leap year
    if (y % 400 == 0)
    {
        cout << "Valid Leap Year" << endl;
        return true;

    }

    // If the year value is divisible by both 4 and 100,
    // but not divisible by 400, it is not a leap year
    if (y % 4 == 0 && y % 100 == 0 && y % 400 != 0)
    {
        return false;
    }

    // If the year value is divisible by 4 but not by 100,
    // it is a leap year.
    if (y % 4 == 0 && y % 100 != 0)
    {
        cout << "Valid Leap Year" << endl;
        return true;

    }

    else
        return false;
}

int Date::lastDay() const
{
    return lastDay(month, year);
}



int Date::lastDay(int m, int y) const
{
    // If the month is April, June, September, or November,
    // it has 30 days
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        return 30;
    }

    // If the month is Febuary, it either has 28 days, or
    // 29 days if it is a leap year
    else if (m == 2)
    {
        if (isLeapYear(y) == 1)
        {
            return 29;
        }

        else return 28;
    }


    // All other cases, the month has 31 days
    else return 31;

}

// Dispays the numberical date
std::string Date::NumericalDate() const
{
    std::stringstream ss;

    ss << month << "/" << day << "/" << year;

    return ss.str();

}

//Displays the date is long format
std::string Date::Month_D_Y() const
{
    std::string C_months[12] =
    { "January", "Febuary", "March", "April", "May",
        "June", "July", "August", "September", "October", "November", "December" };

    std::stringstream ss;

    ss << C_months[month - 1] << " " << day << " " << year;

    return ss.str();

}

//Displays the date in International Format
std::string Date::Day_M_Y() const
{
    std::string C_months[12] =
    { "January", "Febuary", "March", "April", "May",
        "June", "July", "August", "September", "October", "November", "December" };

    std::stringstream ss;

    ss << day << " " << C_months[month - 1] << " " << year;

    return ss.str();

}
int Date::operator- (const Date& rhs)
{
    long s1 = Conv_Value(month, day, year);
    long s2 = Conv_Value(rhs.month, rhs.day, rhs.year);

    return s1 - s2;
}

Date& Date::operator++()
{
    if (day == lastDay())
    {
        day = 1;
        
        if (month == 12)
        {
            cout << "month was december" << endl;
            month = 1;
            ++year;
        }

        else
        {
            ++month;
        }


    }

    else
    {
        ++day;
    }

    return *this;
}

Date& Date::operator--()
{
    if (day == 1)
    {
        if (month == 1)
        {
            month = 12;
            --year;
        }

        else
        {
            --month;
        }

        day = lastDay();
    }
    
    else
    {
        --day;
    }

    return *this;
}

Date Date::operator++(int)
{
    Date temp = *this;

    if (day == lastDay())
    {
        day = 1;

        if (month == 12)
        {
            cout << "month was december" << endl;
            month = 1;
            year++;
        }

        else
        {
            month++;
        }


    }

    else
    {
        day++;
    }
    return temp;
}

Date Date::operator--(int)
{
    Date temp = *this;
    if (day == 1)
    {
        if (month == 1)
        {
            month = 12;
            year--;
        }

        else
        {
            month--;
        }

        day = lastDay();
    }

    else
    {
        day--;
    }
    return temp;
}

ostream& operator<<(ostream& out, const Date& date)
{
    out << date.month << " " << date.day << " " << date.year;

    return out;
}

istream& operator>>(istream& in, Date& date)
{
    cout << "\nEnter Day";
    in >> date.day;
    cout << "\nEnter Month";
    in >> date.month;
    cout << "\nEnter Year";
    in >> date.year;

    return in;
}