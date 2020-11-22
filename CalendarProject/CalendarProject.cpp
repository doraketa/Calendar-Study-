#include <windows.system.h> 
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

#include "MainFunctions.h"
#include "CheckFunctions.h"
#include "CalendarProject.h"

using namespace std;

int main(void)
{
	MainFunctions CalFunctions;
	CheckFunctions cFunctions;

	setlocale(LC_ALL, "Russian");

	int inputedYear, inputedMonth;

	cout << "Введите месяц и год по форме M YYYY:" << endl;
	scanf_s("%d %d", &inputedMonth, &inputedYear);

	while (cFunctions.isMonthUnknown(inputedMonth) || cFunctions.isYearUnknown(inputedYear))
		scanf_s("%d %d", &inputedMonth, &inputedYear);

	CalFunctions.getCalendar(inputedYear, inputedMonth);
	return 0;
}