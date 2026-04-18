// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Date_.h"
using namespace std;

// The purpose of this code is to create a program using objects that
// allows a user to put in a date. The program uses the object code to
// validate the date based on different criteria.  This code in particular 
// has a criteria for the year that requires the year to be between 1900 and 2026.
// Anything outside of those two dates will be considered invalid.


// PrintDate is a funtion that prints the dates in all three formats
void PrintDate(const Date d);

// Print_Getters is a function that prints the individual month, day,
// and year of a selected date uisng the getter functions
void Print_Getters(const Date d);

int main()
{
	//******FUNCTIONALITY CHECKLIST******//

	cout << "FUNCTIONALITY CHECKLIST" << endl << endl;


	//******DEFAULT CONSTRUCTOR TEST******//
	// In this portion of the code I test the functionality the constructor
	// to confirm that the defalt date is printed out
	cout << "DEFAULT CONSTRUCTOR TEST" << endl;

	//Create new object
	Date d1;

	PrintDate(d1);

	cout << endl;


	//******MULTIPLE OUTPUT TEST******//
	// Purpose of this portion of the code is to show that the objects
	// can store the dates that are added to them.

	cout << "MULTIPLE DATE OUTPUT TEST" << endl;

	Date d2(12, 25, 2021);
	PrintDate(d2);

	Date d3(1, 1, 1900);
	PrintDate(d3);

	Date d4(2, 14, 2022);
	PrintDate(d4);
	cout << endl;

	//****** INVALID DATE TESTS ******//
	// Purpose of this portion of the code is to show that the program
	// can identify invalid dates
	cout << "INVALID DATE TEST" << endl << endl;


	//****** INVALID MONTHS ******//
	// Tests month values that are invalid, those being '0' and '13'
	cout << "INVALID MONTHS" << endl;

	// Month value is 0
	Date d5(0, 6, 2006);
	PrintDate(d5);

	// Month value is 13
	Date d6(13, 6, 2006);
	PrintDate(d6);

	cout << endl;

	//****** INVALID DAYS ******//
	// Tests the different day values that would make the dates invalid

	cout << "INVALID DAYS" << endl;

	// 32nd day in October, when the last day should be 31
	Date d7(10, 32, 2006);
	PrintDate(d7);

	// 0 Day in October, when the value should not be lower than 1
	Date d8(10, 0, 2006);
	PrintDate(d8);

	cout << endl;

	//****** INVALID YEARS ******//	
	// In this code the years that are invalid are those before
	// 1900 and after 2026
	cout << "INVALID YEARS" << endl;

	// Instance of a year before 1900
	Date d9(2, 5, 1899);
	PrintDate(d9);

	// Instance of a year after 2027
	Date d10(2, 5, 2027);
	PrintDate(d10);

	cout << endl;

	//****** USING THE SET DATE MUTATOR ******//
	// This portion of code shows that the setDate() mutator function
	// works as intended.
	cout << "USING THE SET DATE MUTATOR" << endl;


	// Inital date set in object d11
	Date d11(5, 15, 2010);
	PrintDate(d11);

	// Use the getters to confirm that the date that is being printed
	// is the same date that is being stored in this object
	Print_Getters(d11);

	// Second date that is set in obect d11
	d11.setDate(6, 16, 2011);
	PrintDate(d11);

	// Show the new stored values
	Print_Getters(d11);

	cout << endl;


	//****** OVERLOADING MONTHS ******//

	cout << "OVERLOAD 30 DAY MONTH" << endl;

	// April only has 30 days, setting the day to 31 should
	// set the date to its default value
	Date d12(4, 31, 2006);

	PrintDate(d12);

	cout << "OVERLOAD FEBUARY" << endl;

	// Febuary in general
	Date d13(2, 30, 2001);
	PrintDate(d13);

	cout << endl;


	//****** LEAP YEAR TESTS ******//

	cout << "LEAP YEAR TEST" << endl;

	Date d14(1, 2, 2000);
	cout << d14.isLeapYear(2000) << endl;

	Date d15(1, 2, 1900);
	cout << d15.isLeapYear(1900) << endl;

	Date d16(1, 2, 1904);
	cout << d16.isLeapYear(1904) << endl;

	Date d17(1, 2, 1901);
	cout << d17.isLeapYear(1901) << endl;



	//****** DATE SUBTRACTION TEST******//
	// Testing the algorithm to covert a date to a number
	// and subtracting two dates from eachother
	// This also tests the << stream operator

	cout << "Date Subtration Test" << endl;

	Date dst1(4, 18, 2014);
	Date dst2(4, 10, 2014);

	cout << "The days between " << dst1 << " and " << dst2 << " are " << dst1 - dst2 << endl;

	dst1.setDate(2, 2, 2006);
	dst2.setDate(11, 10, 2003);

	cout << "The days between " << dst1 << " and " << dst2 << " are " << dst1 - dst2 << endl;

	//****** INCREMENT/DECREMENT TESTS: PREFIX ******//
	//------ LEAP YEAR ------//
	// Testing the code to see if the pre-increment or
	// pre-decrement operator overload was successful

	Date d_id_pre(2, 29, 2008);

	cout << d_id_pre << endl;
	
	++d_id_pre;

	cout << "Pre-increment " << d_id_pre << endl;

	--d_id_pre;

	cout << "Pre-decrement " << d_id_pre << endl;

	//------ END OF YEAR ------//

	d_id_pre.setDate(12, 31, 2024);

	cout << d_id_pre << endl;

	++d_id_pre;

	cout << "Pre-increment " << d_id_pre << endl;

	--d_id_pre;

	cout << "Pre-decrement " << d_id_pre << endl;


	//****** INCREMENT/DECREMENT TESTS: POSTFIX ******//
//------ LEAP YEAR ------//
// Testing the code to see if the Post-increment or
// pre-decrement operator overload was successful
	Date d_id_post(2, 29, 2008);

	cout << d_id_post << endl;

	d_id_post++;

	cout << "Post-increment " << d_id_post << endl;

	d_id_post--;

	cout << "Post-decrement " << d_id_post << endl;

	//------ END OF YEAR ------//

	d_id_post.setDate(12, 31, 2024);

	cout << d_id_post << endl;

	d_id_post++;

	cout << "Post-increment " << d_id_post << endl;

	d_id_post--;

	cout << "Post-decrement " << d_id_post << endl;


}


void PrintDate(const Date d)
{
	cout << std::setw(22) << left << "Numeric: " << setw(20) << d.NumericalDate() << endl;

	cout << std::setw(22) << left << "Long Format: " << setw(20) << d.Month_D_Y() << endl;

	cout << std::setw(22) << left << "International Style: " << setw(20) << d.Day_M_Y() << endl << endl;

}

void Print_Getters(const Date d)
{
	cout << std::setw(8) << left << "Month:" << d.getMonth() << endl;
	cout << std::setw(8) << left << "Day:" << d.getDay() << endl;
	cout << std::setw(8) << left << "Year:" << d.getYear() << endl;
}

