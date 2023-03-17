#include <conio.h>
#include <iostream>
#include "windows.h"
using namespace std;


HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 

void ShowText(string TEXT)  // Show beautiful text
{
	COORD cText;
	cText.X = 27;
	cText.Y = 12;

	SetConsoleCursorPosition(h, cText); 
	SetConsoleTextAttribute(h, 4); 

	for (int i = 0; i < TEXT.length(); i++)
	{
		Sleep(25);
		cout << TEXT[i];
	}

	Sleep(1000);
	SetConsoleCursorPosition(h, cText);
	SetConsoleTextAttribute(h, 0);

	for (int i = 0; i < TEXT.length() + 1; i++)
	{
		Sleep(25);
		cout << " ";
	}

}

void ShowInterface(int beginX, int beginY)
{

	MoveWindow(GetConsoleWindow(), 220, 80, 1500, 900, true);


	COORD Interface;
	Interface.X = beginX + 6;
	Interface.Y = beginY - 2;
	SetConsoleTextAttribute(h, 6);
	SetConsoleCursorPosition(h, Interface);
	cout << "MENU";


	for (int i = 0; i < 5; i++)
	{
		Interface.Y = beginY + i;
		Interface.X = beginX;
		SetConsoleTextAttribute(h, 8);
		SetConsoleCursorPosition(h, Interface);
		cout << (char)254; 

		Interface.X = beginX + 2;
		SetConsoleTextAttribute(h, 15);
		SetConsoleCursorPosition(h, Interface);

		if (i == 0)
		{
			cout << "Show Three";
		}

		else if (i == 1)
		{
			cout << "Add Team";
		}

		else if (i == 2)
		{
			cout << "Add Player";
		}

		else if (i == 3)
		{
			cout << "Show log file";
		}

		else if (i == 4)
		{
			SetConsoleTextAttribute(h, 12);
			cout << "Exit";
		}
		// -------------------------------------------


	}

}


void ControlMenu(int beginX, int beginY) 
{
	// Cursor invisible
	CONSOLE_CURSOR_INFO flash;
	flash.bVisible = false; 
	flash.dwSize = 1;
	SetConsoleCursorInfo(h, &flash);

	//coord
	COORD cursor;
	cursor.X = beginX;
	cursor.Y = beginY;

	SetConsoleCursorPosition(h, cursor); 
	SetConsoleTextAttribute(h, 4);
	cout << char(254);
	


	while (true)
	{
		if (_kbhit()) 
		{
			SetConsoleCursorPosition(h, cursor);
			SetConsoleTextAttribute(h, 8);
			cout << char(254);
			int code = _getch();


			if (code == 224)
			{
				code = _getch();
			}


			// up/down -------------------------------------------		
			if (code == 80 && cursor.Y + 1 != beginY + 5)
			{
				cursor.Y++;
			}

			else if (code == 72 && cursor.Y - 1 != beginY - 1)
			{
				cursor.Y--;
			}
			// ---------------------------------------------------

			// -------------------------------------------------------
			else if (code == 13 && cursor.Y == beginY) // Show Three
			{
				//system("cls"); 
				//cursor.X = 0;
				//cursor.Y = 0;
				//SetConsoleTextAttribute(h, 7);
				ShowText("Show Three");
			}

			// -------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 1) // Add Team
			{
				//system("cls");
				//cursor.X = 0;
				//cursor.Y = 0;
				//SetConsoleTextAttribute(h, 7);
				ShowText("Add Team");
			}

			// -------------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 2) // Add Player
			{
				//system("cls");
				//cursor.X = 0;
				//cursor.Y = 0;
				//SetConsoleTextAttribute(h, 7);
				ShowText("Add Player");
			}

			// -------------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 3) // Show log file
			{
				//system("cls");
				//cursor.X = 0;
				//cursor.Y = 0;
				//SetConsoleTextAttribute(h, 7);
				ShowText("Show log file");

			}


			// EXIT --------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 4)
			{
				int choice = MessageBoxA(0, "\tAre you sure want to exit?", "The Earth is flat", MB_YESNO);

				if (choice == IDYES)
				{
					system("cls");
					exit(0);
				}
			}

			// -------------------------------------------------------------------

			SetConsoleCursorPosition(h, cursor);
			SetConsoleTextAttribute(h, 4);
			cout << char(254);
		}
	}
	// -------------------------------------------------------

	return;
}


void ShowMenu() 
{
	int beginY = 6;
	int beginX = 25;

	ShowInterface(beginX, beginY);
	ControlMenu(beginX, beginY);
}


int main()
{
	ShowMenu();
}