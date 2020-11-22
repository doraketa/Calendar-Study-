#pragma once

#include <time.h>
#include <iostream>

#pragma warning(disable:4996)

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class MainFunction {

	public:
		void getMonthByInput(int inputedYear, int inputedMonth)
		{
			time_t now;
			struct tm * timeinfo;
			int m, i, j;
			const char* month[] = {
				"January",
				"February",
				"March",
				"April",
				"May",
				"June",
				"July",
				"August",
				"September",
				"October",
				"November",
				"December"
			};

			time(&now);
			timeinfo = localtime(&now);
			timeinfo -> tm_year = inputedYear - 1900;
			timeinfo -> tm_mon = 0;

			inputedMonth = -1;

			for (i = 1; i < 33; i++)
			{
				timeinfo->tm_mday = i;
				mktime(timeinfo);

				if (timeinfo->tm_mon > inputedMonth)
				{
					printf("\n%s\n", month[timeinfo->tm_mon]);
					printf("\n  Su  Mo  Tu  We  Th  Fr  Sa\n");
					for (j = 0; j < (timeinfo->tm_wday); j++)
						printf("    ");
					m++;
					break;
				}

				if (m == 11 && timeinfo->tm_mon == 0)
				{
					m++;
					break;
				}

				printf("%4d", timeinfo->tm_mday);

				if (timeinfo->tm_wday == 6)
					printf("\n");
			}
		}
};