#include <iostream> // library that contains basic input output functions
#include <windows.h>
#include <algorithm>
#include <cstdlib>	//for exit()

void setttings_main_menu();
void display_menu();
void window_size_menu();
void text_main_menu();
void sound_main_menu();
void Background_Music();
void Sound_Effects();
void Exit_Program();
void ClearScreen();

using namespace std;

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
void Sound_Effects()
{
	ClearScreen();
	char Sound_Effects_option;
	//Displaying Options for the menu
	cout << "a) On" << endl;
	cout << "b) Off" << endl;
	cout << "c) Exit" << endl;
	//Prompting user to enter an option according to menu
	cout << "Please select an option : ";

	cin >> Sound_Effects_option;
	switch (Sound_Effects_option) //main menu selection
	{
	case 'a':
	{
		Sound_Effects();
		Sleep(500);
		sound_main_menu();

	}
	case 'b':
	{
		Sound_Effects();
		break;
	}
	case 'c':
	{
		sound_main_menu();
	}
	default:
	{
		Sound_Effects();
	}
	}
}
void Background_Music()
{
	ClearScreen();
	char background_option;
	//Displaying Options for the menu
	cout << "a) Track Choice " << endl;
	cout << "b) Exit " << endl;
	//Prompting user to enter an option according to menu
	cout << "Please select an option : ";

	cin >> background_option;
	switch (background_option) //main menu selection
	{
	case 'a':
	{
		Background_Music();
		Sleep(500);
		sound_main_menu();

	}
	case 'b':
	{
		sound_main_menu();
		break;
	}
	default:
	{
		Background_Music();
	}
	}
}
void sound_main_menu()
{
	ClearScreen();
	char sound_option;
	//Displaying Options for the menu
	cout << "a) Background Music " << endl;
	cout << "b) Sound Effects " << endl;
	cout << "c) Exit Program" << endl;
	//Prompting user to enter an option according to menu
	cout << "Please select an option : ";

	cin >> sound_option;
	switch (sound_option) //main menu selection
	{
	case 'a':
	{
		Background_Music();
		Sleep(500);
		sound_main_menu();

	}
	case 'b':
	{
		Sound_Effects();
		break;
	}
	case 'c':
	{
		setttings_main_menu();
	}
	default:
	{
		sound_main_menu();
	}
	}

}
void text_color_menu()
{


     ClearScreen();
       HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	char text_color;
	//Displaying Options for the menu
	cout << "a) Blue text Color " << endl;
	cout << "b) Gray text Color" << endl;
	cout << "c) Red text color" << endl;
	cout << "d) Back" << endl;
	//Prompting user to enter an option according to menu
	cout << "Please select an option : ";

	cin >> text_color;
	switch (text_color) //main menu selection
	{
	case 'a':
	{
	    SetConsoleTextAttribute(hConsole, 1);

		text_color_menu();
		Sleep(500);
		text_main_menu();

	}
	case 'b':
	{
	    SetConsoleTextAttribute(hConsole, 8);
		text_color_menu();
		Sleep(500);
		text_main_menu();
		break;
	}
	case 'c':
	{
	     SetConsoleTextAttribute(hConsole, 12);
		text_color_menu();
		Sleep(500);
		text_main_menu();
	}
	default:
	{
		text_main_menu();
	}
	}

}

void background_color_menu()
{

    ClearScreen();
	char background_color;
	//Displaying Options for the menu
	cout << "a) White Background Color " << endl;
	cout << "b) Gray Background Color" << endl;
	cout << "c) Back" << endl;
	//Prompting user to enter an option according to menu
	cout << "Please select an option : ";

	cin >> background_color;
	switch (background_color) //main menu selection
	{
	case 'a':
	{
	    SetConsoleTextAttribute( GetStdHandle( STD_INPUT_HANDLE ), 0x5B );

		background_color_menu();
		Sleep(500);
		setttings_main_menu();

	}
	case 'b':
	{
		background_color_menu();
		Sleep(500);
		setttings_main_menu();
		break;
	}
	case 'c':
	{
		background_color_menu();
		Sleep(500);
		setttings_main_menu();
	}
	default:
	{
		display_menu();
	}
	}

}
void text_main_menu()
{
	ClearScreen();
	char text_option;
	//Displaying Options for the menu
	cout << "a) Background Color " << endl;
	cout << "b) Text Color" << endl;
	cout << "c) Text Speed" << endl;
	cout << "d) Exit" << endl;
	//Prompting user to enter an option according to menu
	cout << "Please select an option : ";

	cin >> text_option;
	switch (text_option) //main menu selection
	{
	case 'a':
	{
		background_color_menu();
		Sleep(500);
		setttings_main_menu();

	}
	case 'b':
	{
		text_color_menu();
		Sleep(500);
		setttings_main_menu();
		break;
	}
	case 'c':
	{
		display_menu();
		Sleep(500);
		setttings_main_menu();
	}
	default:
	{
		display_menu();
	}
	}
}
void window_size_menu()
{
	ClearScreen();
	char window_option;
	//Displaying Options for the menu
	cout << "a) Size 1 " << endl;
	cout << "b) Size 2 " << endl;
	cout << "c) Size 3" << endl;
	cout << "d) Back" << endl;
	//Prompting user to enter an option according to menu
	cout << "Please select an option : ";

	cin >> window_option;
	switch (window_option) //main menu selection
	{
	case 'a':
	{
	    system("mode con cols=200 lines=50");
		window_size_menu();
		Sleep(500);
		setttings_main_menu();

	}
	case 'b':
	{
	    system("mode con cols=100 lines=85");
		window_size_menu();
		Sleep(500);
		setttings_main_menu();
		break;
	}
	case 'c':
	{
	    system("mode con cols=50 lines=50");
		window_size_menu();
		Sleep(500);
		setttings_main_menu();
	}
	default:
	{
		display_menu();
	}
	}

}
void display_menu()
{
	ClearScreen();
	char display_option;
	//Displaying Options for the menu
	cout << "a) Window Size " << endl;
	cout << "b) Text " << endl;
	cout << "c) Exit Program" << endl;
	//Prompting user to enter an option according to menu
	cin >> display_option;
	cout << "Please select an option : ";


	switch (display_option) //main menu selection
	{
	case 'a':
	{
		window_size_menu();
		Sleep(500);
		display_menu();

	}
	case 'b':
	{
		text_main_menu();
		break;
	}
	case 'c':
	{
		setttings_main_menu();
	}
	default:
	{
		display_menu();

	}
	}


}

void setttings_main_menu()
{
	ClearScreen();
	char display_option;
	cout << "a) Display " << endl;
	cout << "b) Sound " << endl;
	cout << "c) Exit Program" << endl;
	//Prompting user to enter an option according to menu
	cout << "Please select an option : ";

	cin >> display_option;

	switch (display_option) //main menu selection
	{
	case 'a':
	{
		display_menu();
		Sleep(500);
		setttings_main_menu();

	}
	case 'b':
	{
		sound_main_menu();
		break;
	}
	case 'c':
	{
		Exit_Program();
	}
	default:
	{
		setttings_main_menu();
	}
	}
}
void Exit_Program()
{
	exit(0);
}


int main()
{

	setttings_main_menu();
	return 0;
}
