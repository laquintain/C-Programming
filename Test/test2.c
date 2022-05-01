#include <stdio.h> //Must Have
#include "got.h" //Header File
#include <stdlib.h> //Library
#include <time.h> //Calls the Define Time clearance

#pragma warning(disable : 4996)

int testMain() //Modular Code Benchmark
{
	
		char sre = 0;
		printf(SECRET_MSG); //Pulls the secret message from got.h
		while (1) // Allows ENTER to return to the main menu
		{
			char c = getchar();
			if (c == '\n' && sre == c)
			{
				break;
			}
			sre = c;
		}
		return main();
}
int atrMain() //Structure benchmark
{
	int hours, minutes, seconds, day, month, year; //Defining time

	char stru = 0;
	printf("You now know where and when you are!\n\n"); //You are here
	{
		time_t now; //Value pointed by time
		time(&now);

		printf("Today is %s", ctime(&now)); //Returns a string: Hand in hand with localtime
		struct tm* local = localtime(&now); //Breaks down time into components using local timezone
		/*  Combines data items of different kinds 
			tm hour links to tm and calls local time
			from the local device. Tm calls items from time_t
			and performs the buffering process. 
		*/
		hours = local->tm_hour; //Cannot use local.tm_hour here, the IDE asks for -> and must be used throughout
		minutes = local->tm_min;
		seconds = local->tm_sec;

		day = local->tm_mday;
		month = local->tm_mon + 1;
		year = local->tm_year + 1900;
		if (hours < 12) {
			printf("Time is %02d:%02d:%02d\n", hours - 12, minutes, seconds); //Minus 12 should allow for non-military time
		}
		printf("Date is %02d-%02d-%02d", month, day, year);
	}
	while (1) // Allows ENTER to return to the main menu
	{
		char c = getchar();
		if (c == '\n' && stru == c)
		{
			break;
		}
		stru = c;
	}
	return main();
}
//In chapter 14 of handbook