#include <windows.system.h> 
#include <iostream>

#include "MainFunctions.h"
#include "CheckFunctions.h"

using namespace std;

int main()
{
	MainFunctions CalFunctions;
	CheckFunctions cFunctions;

	setlocale(LC_ALL, "Russian");

	int inputedYear, inputedMonth;

	cout << "Введите месяц: " << endl;
	cin >> inputedMonth;

	while (cFunctions.isMonthUnknown(inputedMonth))
		cin >> inputedMonth;

	cout << "Введите год: " << endl;
	cin >> inputedYear;

	while (cFunctions.isYearUnknown(inputedYear))
		cin >> inputedYear;

	CalFunctions.getCalendar(inputedYear, inputedMonth);
	return 0;
}