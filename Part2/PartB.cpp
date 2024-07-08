#include<stdio.h>

int main()
{
	int Site_ID[],day_of_month[],temperature[];
	float humidity[], wind_speed[];
	FILE* fileMeteo;
	fopen_s(&fileMeteo, "MeteoData.txt", "a");
	if (fileMeteo = NULL)
	{
		printf("The file could not be opened\n");
	}
	else
	{
		printf("File was opened or created.\n");
		printf("----- <Data Collection> -----\n");
		printf("This is a program that can help you to analysis meteorological data.\n");
		DataCollection(Site_ID[], day_of_month[], temperature[], humidity[], wind_speed[]);
	}
}

void DataCollection(int Site_ID[], int day_of_month[], int temperature[], float humidity[],float wind_speed[])
{
	int lognumber;
	do
	{
		printf("How many days do you want to log in?\n");
		scanf_s("%d", &lognumber);
		if (lognumber <= 0)
		{
			printf("The value is not valid, please try again.\n");
		}
		else
		{
			continue;
		}
	} while (lognumber <= 0);

	do
	{
		printf("What is the SiteID number?\n");
		scanf_s("%d", &Site_ID[]);
		if (lognumber <= 0)
		{
			printf("The value is not valid, please try again.\n");
		}
		else
		{
			continue;
		}
	} while (lognumber <= 0);
}