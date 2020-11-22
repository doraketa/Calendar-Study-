#pragma once
#include <iostream>

using namespace std;

#define UNKNOWN_YEAR_VALUE "ќшибка. ¬веденный год не может быть меньше 1919 и больше 2029"
#define UNKNOWN_MONTH_VALUE "ќшибка. ¬веденный мес€ц не может быть меньше 1 и больше 12"

class CheckFunctions
{
public:
	bool isYearUnknown(int gettedValue)
	{
		if ((gettedValue < 1919) || (gettedValue > 2029))
		{
			cout << UNKNOWN_YEAR_VALUE << endl;
			return true;
		}
		else
			return false;
	}

	bool isMonthUnknown(int gettedValue)
	{
		if ((gettedValue < 1) || (gettedValue > 12))
		{
			cout << UNKNOWN_MONTH_VALUE << endl;
			return true;
		}
		else
			return false;
	}
};

