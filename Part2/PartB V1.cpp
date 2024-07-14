#include<stdio.h>
#include<math.h>
int Day_Temp(int *day_of_month, int *temperature, int i)
{
	printf("\n");
	printf("Please enter day of month\n");
	scanf_s("%d", &day_of_month[i]);
	printf("\n");
}
int SiteIDCollection(int Site_ID,int feedback)
{
	do
		{
			printf("\n");
			printf("----- <Site ID> -----\n");
			printf("Please type in the Site ID\n");
			scanf_s("%d", &Site_ID);
			if (Site_ID != 2001 && Site_ID != 3345 && Site_ID != 4818)
			{
				printf("The site ID is not valid. Please try again\n");
			}
			else
			{
				printf("You have typed site ID %d. Type 1 to confirm. Otherwise, key in another number.\n", Site_ID);
				scanf_s("%d", &feedback);
			}
		} while ((Site_ID != 2001 && Site_ID != 3345 && Site_ID != 4818) || feedback != 1);
		return(Site_ID);
}
int main()
{
	FILE* Meteo;
	int Site_ID=0, feedback=0, day_of_month[] = { 0 }, temperature[] = { 0 };
	int i=0;
	float wind_speed[] = { 0.0 }, humidity[] = { 0.0 };
	fopen_s(&Meteo, "MeteoData.txt", "a");
	if (Meteo == NULL)
	{
		printf("File could not be opened");
	}
	else
	{
		printf("----- <Program Start> -----\n");
		printf("This program is designed to help to analysis meteorological data\n");
		printf("This program requires you to input the Site ID, day of the month, wind speed, temperature and humidity\n");
		printf("\n");
		//printf("----- <Example> -----\n");
		//printf("Site ID\t\tDay\t  Wind Speed(km/h)\tTemperature(degree)\tHumidity\n");
		Site_ID = SiteIDCollection(Site_ID,feedback);
		printf("Site ID -> %d\n", Site_ID);
		printf("\n");
		do
		{
			printf("How many days of input would you like enter?\n");
			scanf_s("%d", &feedback);
			if (feedback <= 0)
			{
				printf("The input is invalid\n");
			}
			else
			{
				continue;
			}
		} while (feedback <= 0);

		day_of_month[feedback] = temperature[feedback] = { 0 };
		humidity[feedback] = wind_speed[feedback] = { 0.0 };
		for (i = 0; i < feedback; i++)
		{
			Day_Temp(day_of_month[i], temperature[i],i);
		}
		
		



	}
}