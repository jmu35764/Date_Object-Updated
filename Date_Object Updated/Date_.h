//Specification file for the rectangle class
#ifndef DATE__H
#define DATE__H 

#include <string>
#include <iostream>
using namespace std;
// Date class declaration.

class Date
{
private:
	int month;
	int day;
	int year;

	bool ValidDate(int m, int d, int y);
	void CheckDate(int m, int d, int y);
	static long Conv_Value(int m, int d, int y) noexcept;  //Algorithm for converting Dates to number values

public:
	// Constructor
	Date(int m = 1, int d = 1, int y = 1900);

	// Setter
	void setDate(int m, int d, int y);


	// Getters
	int getMonth() const
	{
		return month;
	}

	int getDay() const
	{
		return day;
	}

	int getYear() const
	{
		return year;
	}

	// Validation Functions
	bool isLeapYear() const;

	bool isLeapYear(int year) const;

	int lastDay() const;

	int lastDay(int month, int year) const;

	// Date output Functions

	std::string NumericalDate() const;

	std::string Month_D_Y() const;

	std::string Day_M_Y() const;

	// Overloaded Operator Functions
	
	// Subtraction
	int operator-(const Date& rhs);

	// Prefix ++
	Date& operator++();


	// Prefix --
	Date& operator--();


	// Postfix ++
	Date operator++(int);


	// Postfix --
	Date operator--(int);


	friend ostream& operator<<(ostream& out, const Date& date);


	friend istream& operator>>(istream& in, Date& date);

};

#endif
