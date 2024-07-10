#include<stdio.h>
#include<math.h>

float DataCollection(int day_of_month[], int temperature[], float wind_speed[], float humidity[])
{
	int SiteNum, feedback=0, Numofdays,feedback2;
	do
	{
		printf("\n");
		printf("----- <Data Collection> -----\n");
		printf("You can only select one site at a time to key in the data.\n");
		printf("Instructions:\n");
		printf("1.Please select the site you would like to access \n2.Please key in the day of the month \n3.Then, key in the respective meteorological data\n");

		/*To enter data by site number*/
		do
		{
			printf("\n");
			printf("----- <Site ID> -----\n");
			printf("Please type in the Site ID\n");
			scanf_s("%d", &SiteNum);
			if (SiteNum != 2001 && SiteNum != 3345 && SiteNum != 4818)
			{
				printf("The site ID is not valid. Please try again\n");
			}
			else
			{
				printf("You have typed site ID %d. Type 1 to confirm. Otherwise, key in another number.\n", SiteNum);
				scanf_s("%d", &feedback);
			}
		} while ((SiteNum != 2001 && SiteNum != 3345 && SiteNum != 4818) || feedback != 1);

		/*Remeber do if statement based on site number*/
		do
		{
			printf("\n");
			printf("----- <Number of Days> -----\n");
			printf("How many days of data would you like to input?\n");
			scanf_s("%d", &Numofdays);
			if (Numofdays <= 0)
			{
				printf("Invalid number, please try again\n");
			}
			else if (Numofdays == 1)
			{
				printf("Please enter the day of the month\n");
				scanf_s("%d", &day_of_month[0]);

				printf("Please enter the wind speed in km/h format\n");
				scanf_s("%f", &wind_speed[0]);

				printf("Please enter the temperature in degree\n");
				scanf_s("%d", &temperature[0]);

				printf("Please enter the humidity\n");
				scanf_s("%f", &humidity[0]);
			}
			else if (Numofdays > 1)
			{
				for (feedback = 0; feedback < Numofdays; feedback++)
				{
					printf("Please enter date %d\n", feedback + 1);
					scanf_s("%d", &day_of_month[feedback]);

					printf("Please enter wind speed %d in km/h format\n", feedback + 1);
					scanf_s("%f", &wind_speed[feedback]);

					printf("Please enter the temperature %d in degree\n", feedback + 1);
					scanf_s("%d", &temperature[feedback]);

					printf("Please enter the humidity %d\n", feedback + 1);
					scanf_s("%f", &humidity[feedback]);
				}
			}
		} while (Numofdays <= 0);

		printf("\n");
		printf("----- <Data Collected> -----\n");
		printf("Site ID\tDay\t\tWind Speed(km/h) Temperature(degree)\tHumidity\n");
		for (feedback = 0; feedback < Numofdays; feedback++)
		{
			printf("%d\t%d/6/2024\t%0.2f\t\t %d\t\t\t%0.2f\n", SiteNum, day_of_month[feedback], wind_speed[feedback], temperature[feedback], humidity[feedback]);
		}

		  printf("Please confirm the values printed above by typing 1. Otherwise, type another number\n");
		  scanf_s("%d", &feedback2);
		
	} while (feedback2 != 1);
    return (SiteNum, feedback, *day_of_month, *wind_speed, *temperature, *humidity);
	
}
int main()
{
	FILE* Meteo;
	int Site_ID[3] = {2001,3345,4818}, day_of_month[] = { 0 }, temperature[] = { 0 };
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
		DataCollection(day_of_month, temperature, wind_speed, humidity);
		
	}
}

