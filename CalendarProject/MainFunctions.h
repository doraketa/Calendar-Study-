#pragma once

#include <iostream>

using namespace std;

class MainFunctions
{
private:

	// Constant for searching for a leap year
	const int fixedYear = 2008;

	// Constant for fixing @Empty strings
	const int fixedEmpty[12]
	{
		1, 4, 5, 1,
		3, 6, 1, 4,
		0, 2, 5, 0
	};

	// Prepared the names of the months
	char monthName[12][9]
	{
		"Январь", "Февраль", "Март", "Апрель",
		"Май", "Июнь", "Июль", "Август",
		"Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
	};

	// Number of days in each month
	int daysInMonth[12]
	{
		31, 28, 31, 30,
		31, 30, 31, 31,
		30, 31, 30, 31
	};

protected:

	// The structure of calendar
	struct sOfCalendar {
		int numberOfDaysInMonth = 0;
		int difShifting = 0;
		int getEmptyStr = 0;
	};

public:

	//Function for getting the difference in years
	int getDifferenceinYear(int inputedYear)
	{
		return inputedYear - fixedYear;
	}

	// Checking for the difference in years
	bool isYearDifference(int inputedDifference)
	{
		if (inputedDifference > 0)
			return true;
		else
			return false;
	}

	// Getting Month Name by ID + fix
	char* getMonthNameByID(int gettedID)
	{
		return monthName[gettedID - 1];
	}

	// Beauty calendar output
	void drawCalendar(int gettedMonth, int gettedEmptyStr, int gettedNumberOfDaysInMonth, int gettedYear)
	{
		system("CLS");

		printf("\n %s %d \n", getMonthNameByID(gettedMonth), gettedYear);
		printf("\n ПН\tВТ\tСР\tЧТ\tПТ\tСБ\tВС \n");

		for (int e = 0; e < gettedEmptyStr; e++)
			printf ("\t");

		for (int d = 1; d <= gettedNumberOfDaysInMonth; d++)
			cout << d << ((gettedEmptyStr + d) % 7 == 0 ? "\n " : "\t");
	}

	void getCalendar(int gettedYear, int gettedMonth)
	{
		// Structure of Calendar
		sOfCalendar CalendarStructure;

		// Getting Year Difference
		int yearDiff = getDifferenceinYear(gettedYear);

		// Getting number of days in month
		CalendarStructure.numberOfDaysInMonth = (gettedMonth == 2 && gettedYear % 4 == 0) ? 29 : daysInMonth[gettedMonth - 1];

		// Making a check for the difference in years (to check the leap year)
		if (isYearDifference(yearDiff))
		{
			CalendarStructure.difShifting = yearDiff + yearDiff / 4;
			if (gettedMonth <= 2 && gettedYear % 4 != 0)
				CalendarStructure.difShifting++;
		}
		else {
			CalendarStructure.difShifting = yearDiff - yearDiff / 4;
			if (gettedMonth > 2 && gettedYear % 4 != 0)
				CalendarStructure.difShifting--;
		}

		// Getting empty strings 
		CalendarStructure.getEmptyStr = fixedEmpty[gettedMonth - 1] + CalendarStructure.difShifting;

		// Getting FIXED empty strings
		CalendarStructure.getEmptyStr = CalendarStructure.getEmptyStr % 7;

		// Checking for the beginning of the week
		if (CalendarStructure.getEmptyStr < 0)
			CalendarStructure.getEmptyStr += 7;

		// Detail description of parameters
		int getEmptyStr = CalendarStructure.getEmptyStr;
		int numberOfDays = CalendarStructure.numberOfDaysInMonth;

		drawCalendar(gettedMonth, getEmptyStr, numberOfDays, gettedYear);
	}
};

