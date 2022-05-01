#include <stdio.h>

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
	printf("\nPress ENTER after reading your selection to return to the main menu.\n"); //Advice on returning to the main menu.
	printf("\nMake your selection: ");
	scanf_s("%d", &i);
	printf("\n\n");
	return i;
}
int main()
{
	int op;
	op = Menu();
	switch (op)
	{
	case 1: // Technical Support that is displayed from text file and returns the main menu.
	{
		int tech();
		{
			FILE *tec = NULL; // Added null

			errno_t err = 0; //Errno added
			char ch;
			char tre = 0;
			ch = "Tech.txt"[0];

			tec = fopen_s(&tec, "Tech.txt", "r"); //Assigns the text file and reads the file.
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
	default: // Displays an error message if the client tries to go over the listed numbers.
	{
		printf("\n\nERROR: Invalid.\n\n"); //If above 5 cases, reutrn to the main menu
		return Menu(main()); //Needed to immediately return to the main menu upon error
	}
	}
}