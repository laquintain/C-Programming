/*
Question and Answers: GCU Frequently Asked Questions
Malachi Gillespie
ITT-310
Grand Canyon University
Dr. Amr Elchouemi
*/
#pragma warning(disable : 4996) //Disables error message for error code 4996 older command for fopen_s/scanf_s/ctime_s/localtime_s statements

#include <stdio.h> //Must have always.
#include <stdlib.h>
#include "got.h" //Header File

int Menu()
{
	//List of frequently asked questions
	int i;
	printf("\n\nFrequently asked questions.\n\n");
	printf("1 - Technical Support\n");
	printf("2 - Halo Learn\n");
	printf("3 - The Library\n");
	printf("4 - Why GCU?\n");
	printf("5 - When in Doubt\n");
	printf("6 - Grade Average\n"); //Makes use of Arrays and Pointers
	printf("7 - Secret Message\n");
	printf("8 - Forget The Time and Date?\n");
	printf("\nPress ENTER after reading your selection to return to the main menu.\n"); //Advice on returning to the main menu.
	printf("\nMake your selection: ");
	scanf_s("%d", &i);
	printf("\n\n");
	return i;
}
int main()
{	//Allows specific item listings to be revealed
	int op;
	op = Menu();
	switch (op)
	{
	case 1: // Technical Support that is displayed from text file and returns the main menu.
		{	
			int tech();
			{
				FILE *tec = NULL;

				char ch;
				char tre = 0;

				tec = fopen("Tech.txt", "r"); //Assigns the text file and reads the file.
				printf("What the IT team can do: \n");

				do { //Gets the text file
					ch = fgetc(tec); //Gets the open assignment
					printf("%c", ch); //Prints .txt file
					} while (ch != EOF); //End of File

					while (1) // Allows ENTER to return to the main menu.
					{
						char d = getchar();//Assigns the ENTER key to return to the main menu. Does not like the 13 key assignment command.
						if (d == '\n' && tre == d)
						{
							break;
						}
						tre = d;
					}
				fclose(tec); //Closes the text file after it has been read and printed.
			}
			return main(); //Required to keep from overflowing into other menus
		}
	case 2: // Halo Learn that is displayed from text file and returns the main menu.
		{int halo();
			{
				FILE *hlo = NULL;
				char hl;
				char hre = 0;

				hlo = fopen("halo.txt", "r"); //Opens the text file and reads the file.
				printf("What is Halo Learn? \n"); 
				//Do while loop
				do {
					hl = fgetc(hlo);
					printf("%c", hl);
					} while (hl != EOF); //End of File

					while (1) //Return to the main menu by pressing ENTER
					{
						char c = getchar();
						if (c == '\n' && hre == c)
						{
							break;
						}
						hre = c;
					}

				fclose(hlo); //Closes the text file after it has been read
			}
			return main(); //Required to keep from overflowing into other menus
		}
	case 3: // Library information that is displayed from text file and returns the main menu.
		{int library();
			{
				FILE *lib = NULL;
				char lb;
				char lre = 0;

				//testing lib
				lib = fopen("library.txt", "r"); //Opens the text file and reads the file.
				printf("Need a book?\n");

				//Do while loop
				do {
					lb = fgetc(lib);
					printf("%c", lb);
					} while (lb != EOF); //End of File

					while (1) // Allows ENTER to return to the main menu
					{
						char c = getchar();
						if (c == '\n' && lre == c)
						{
							break;
						}
						lre = c;
					}
				fclose(lib); //Closes the text file after it has been read
			}
			return main(); //Required to keep from overflowing into other menus
		}
	case 4: // Main page information from GCU's website
		{int man();
			{
				FILE *mane = NULL;
				char ma;
				char prev = 0;

				mane = fopen("main.txt", "r"); //Opens the text file and reads the file.
				printf("Why GCU?\n");
				//Do while loop
				do {
					ma = fgetc(mane);
					printf("%c", ma);
					} while (ma != EOF); //End of File
					while (1) // Allows ENTER to return to the main menu
					{
						char c = getchar();
						if (c == '\n' && prev == c)
						{
							break;
						}
						prev = c;
					}
				fclose(mane); //Closes the text file after it has been read
			}
			return main(); //Required to keep from overflowing into other menus
		}
	case 5: //Doubt
		{	
			char dre = 0;
			printf("When in doubt, return to the main page or contact a counselor.\n"); // Display (print statement)
			printf("After logging into the student portal, locate the counselor section on the left side.\n");

			while (1) // Allows ENTER to return to the main menu
			{
				char c = getchar();
				if (c == '\n' && dre == c)
				{
					break;
				}
				dre = c;
			}
			return main();
		}
	case 6: //Grade Average and makes use of arrays/pointers
		{
		char ale = 0;

		int i, x[6], sum = 0; //Limit is six grades that can be entered. Sum is left as false. 
		printf("Enter 6 grades: "); //Holds 6 grades

		for (i = 0; i < 6; ++i) {//Connects to the grades x[6] limit, i is less than the limit for entry, and then includes local variable
			scanf_s("%d", x + i); //Looks for input
			sum += *(x + i); //Adds the total
		}
		printf("\nAverage is: %d", sum / 6); //End of Average. Takes the sum of 6 numbers and then devides by 6; The numbers stacked.

		while (1) // Allows ENTER to return to the main menu
		{
			char c = getchar();
			if (c == '\n' && ale == c)
			{
				break;
			}
			ale = c;
		}
		return main(); //Required to keep from overflowing into other menus
		}
	case 7: //Secret Message
		{
			extern int testMain(); //Modular example that pulls from test2.c
		}
	case 8:
		{
			extern int atrMain(); //Modular, see Test2
		}
	default: // Displays an error message if the client tries to go over the listed numbers.
		{
			//Updated to disallow letter keys
			int i;
			char myFile = NULL;
			errno_t err = 0;
			char file_name[256];
			char* cs = 0;

			err = fopen_s(&myFile, "no.txt", "r");
			if ((err != 0) || (myFile)) {
				printf_s("Cannot process letter key entries!\n");
				exit(-1);
			}
			//printf("\n\nERROR: Invalid.\n\n"); //If above 8 cases, return to the main menu
			//return main(); //Needed to immediately return to the main menu upon error
		}
	}
}

/*
References
Grand Canyon University (2022). Grand Canyon University. Retrieved from https://www.gcu.edu/ 
*/