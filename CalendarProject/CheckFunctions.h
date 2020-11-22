#pragma once
#include <iostream>

using namespace std;

#define UNKNOWN_YEAR_VALUE "������. ��������� ��� �� ����� ���� ������ 1919 � ������ 2029"
#define UNKNOWN_MONTH_VALUE "������. ��������� ����� �� ����� ���� ������ 1 � ������ 12"

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

