#include <windows.system.h> 
#include <iostream>
#include "MainFunctions.h"

using namespace std;

int main()
{
	MainFunctions CalFunctions;

	setlocale(LC_ALL, "Russian");

	int inputedYear, inputedMonth;

	cout << "Введите месяц: " << endl;
	cin >> inputedMonth;

	while (inputedMonth < 1 || inputedMonth > 12)
	{
		cout << "Ошибка. Месяц не может быть меньше 1 и больше 12" << endl;
		cin >> inputedMonth;
	}

	cout << "Введите год: " << endl;
	cin >> inputedYear;

	while (inputedYear < 1919 || inputedYear > 2029)
	{
		cout << "Ошибка. Год не может быть меньше 1919 и больше 2029" << endl;
		cin >> inputedYear;
	}

	CalFunctions.getCalendar(inputedYear, inputedMonth);
	return 0;
}