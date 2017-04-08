

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <Tchar.h>


#include "Console.h"
#include "Rectangle.h"

int _tmain(int argc, _TCHAR* argv[]) {
	Console console(50, 50);
	RectangleShape rect(Vector(2, 2), Vector(5, 5));
	while (true) {
		console.clearBuffer();
		console.draw(rect);
		console.display();
	}
	return 0;

}




/*
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <Tchar.h>

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.

int _tmain(int argc, _TCHAR* argv[]) {

	// Set up the handles for reading/writing:
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);

	// Change the window title:
	SetConsoleTitle(TEXT("Win32 Console Control Demo"));

	// Set up the required window size:
	SMALL_RECT windowSize = { 0, 0, 79, 49 };

	// Change the console window size:
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);

	// Create a COORD to hold the buffer size:
	COORD bufferSize = { 80, 50 };

	// Change the internal buffer size:
	SetConsoleScreenBufferSize(wHnd, bufferSize);

	// Set up the character buffer:
	CHAR_INFO consoleBuffer[80 * 50];

	// Clear the CHAR_INFO buffer:
	for (int i = 0; i < 80 * 50; ++i) {

		// Fill it with white-backgrounded spaces
		consoleBuffer[i].Char.AsciiChar = ' ';
		consoleBuffer[i].Attributes =
			BACKGROUND_BLUE |
			BACKGROUND_GREEN |
			BACKGROUND_RED |
			BACKGROUND_INTENSITY;
	}

	// Set up the positions:
	COORD charBufSize = { 80,50 };
	COORD characterPos = { 0,0 };
	SMALL_RECT writeArea = { 0,0,79,49 };

	// Copy to display:
	WriteConsoleOutputA(wHnd, consoleBuffer, charBufSize, characterPos, &writeArea);

	// How many events have happened?
	DWORD numEvents = 0;

	// How many events have we read from the console?
	DWORD numEventsRead = 0;

	// Boolean flag to state whether app is running or not.
	bool appIsRunning = true;

	// If we set appIsRunning to false, the program will end!
	while (appIsRunning) {

		// Find out how many console events have happened:
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);

		// If it's not zero (something happened...)
		if (numEvents != 0) {

			// Create a buffer of that size to store the events
			INPUT_RECORD *eventBuffer = new INPUT_RECORD[numEvents];

			// Read the console events into that buffer, and save how
			// many events have been read into numEventsRead.
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);

			// Now, cycle through all the events that have happened:
			for (DWORD i = 0; i < numEventsRead; ++i) {

				// Check the event type: was it a key?
				if (eventBuffer[i].EventType == KEY_EVENT) {
					// Yes! Was the key code the escape key?
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {

						// Yes, it was, so set the appIsRunning to false.
						appIsRunning = false;

						// Was if the 'c' key?
					}

					else if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c') {
						// Yes, so clear the buffer to spaces:
						for (int i = 0; i < 80 * 50; ++i)
							consoleBuffer[i].Char.AsciiChar = ' ';

						// Redraw our buffer:
						WriteConsoleOutputA(wHnd, consoleBuffer, charBufSize, characterPos, &writeArea);
					}

				}

				else if (eventBuffer[i].EventType == MOUSE_EVENT) {

					// Set the index to our buffer of CHAR_INFO
					int offsetPos =
						eventBuffer[i].Event.MouseEvent.dwMousePosition.X
						+ 80 * eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;

					// Is it a left click?
					if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {

						// Yep, so set with character 0xDB (solid block)
						consoleBuffer[offsetPos].Char.AsciiChar = (char)0xDB;

						// Redraw our buffer:
						WriteConsoleOutputA(wHnd, consoleBuffer, charBufSize, characterPos, &writeArea);

						// Is it a right click?
					}
					else if (eventBuffer[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) {

						// Yep, so set with character 0xB1 (50% block)
						consoleBuffer[offsetPos].Char.AsciiChar = (char)0xB1;

						// Redraw our buffer:
						WriteConsoleOutputA(wHnd, consoleBuffer, charBufSize, characterPos, &writeArea);

						// Is it a middle click?
					}
					else if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_2ND_BUTTON_PRESSED) {

						// Yep, so set with character space.
						consoleBuffer[offsetPos].Char.AsciiChar = ' ';

						// Redraw our buffer:
						WriteConsoleOutputA(wHnd, consoleBuffer, charBufSize, characterPos, &writeArea);
					}
				}
			}

			// Clean up our event buffer:
			delete[] eventBuffer;
		}
	}

}



/*
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;



int main()
{
	int liczba;
	streambuf *p;
	p = cin.rdbuf();
	cout << "avil: " << p->in_avail() << endl;
	vector<int> liczby;
	do 
	{
		cin >> liczba;
		liczby.push_back(liczba);
		cout << p->in_avail() << endl;
	} while (p->in_avail()>1 );
	cin.ignore();
	//cin.clear();
	//cin.sync();
	cout << "====" << endl;
	cout << liczby.size();
	
	cout << endl << "Liczby: \n";
	for (int i = 0; i < liczby.size();i++)
		cout << liczby[i] << endl;
	
	cout << "avil: " << p->in_avail() << endl;
	
	system("pause");
	return 0;
}


/* Tablice i jej elementy
#include <iostream>
using namespace std;
int main()
{
	int numAmount, numToWriteAmount;
	cin >> numAmount;
	int *num = new int[numAmount], num2;
	for (int i = 0; i < numAmount; i++)
		cin >> num[i];
	cin >> numToWriteAmount;
	for (int i = 0; i < numToWriteAmount; i++) {
		cin >> num2;
		cout << num[num2-1] << endl;
	}
	return 0;
}



/* Templates
#include <iostream>
#include <string>
using namespace std;
template<class type=float>
class Vector
{
public:
	type x, y;
	Vector(type x, type y) : x(x), y(y) {}
	Vector(Vector<type> &vector) : x(vector.getx()), y(vector.gety()) {}
	Vector() {}
	type getx() const
	{
		return x;
	}
	type gety() const
	{
		return y;
	}
};

int main()
{
	Vector<> pos;
	cout << pos.x << endl;
	cin.get();
	cin.ignore();
	return 0;
}


/* Silnia
#include <iostream>
#include <string>
using namespace std;


template<class type>
type ** makeDoubleDynamicArray(int amount, int amount2)
{
	type **array = new type*[amount];
	for (int i = 0; i < amount; ++i)
		array[i] = new type[amount2];
	return array;
}

int main()
{
	int **tab = makeDoubleDynamicArray<int>(25,25);
	*(tab+24*25) = 10;
	cout << tab[24][24] << endl;


	//return 0;
	cin.ignore();
	cin.get();
	return 0;
}


/*Flushing files
#include <iostream>
#include<thread>
using namespace std;

class Klasa {
public:
	Klasa()
	{

	}
	void func() {
		cout << "Hello from klasa\n";
	}
};

int main() {
	Klasa klasa;
	&Klasa::func;
}


/*

#include <iostream>
#include <windows.h> 

using namespace std;

void setCursorPosition(COORD coord);



int main()
{
	int a=0;
	while (1)
	{
		a++;
		setCursorPosition({ 30,4 });
		cout << "Czas: " << a;
		setCursorPosition({ 0,0 });
		Sleep(1000);
	}
	return 0;
}

void setCursorPosition(COORD coord)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hCon, coord);

}
/*
#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;

COORD curCoord = { 0,0 };


COORD getCursorPosition() //Zwraca COORD, czyli pozycje kursora
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return{ 0,0 };
	return csbi.dwCursorPosition;
}

void hidecursor() // Ukrywa kursor. Wywolujesz raz, na poczatku
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void setCursorPosition(COORD coord) //USTAWIA POZYCJE KURSORA, LECZ PRZED TYM, ZAPISUJE POZYCJE OBECNA DO curCoord
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	curCoord = getCursorPosition();
	SetConsoleCursorPosition(hCon, coord);

}

void czas()
{
	for (int i = 0; i <= 60; i++)
	{
		setCursorPosition({ 10,5 });
		cout << i + 1;
		setCursorPosition(curCoord);

		Sleep(1000);

		setCursorPosition({ 10,6 });
		cout << i + 1;
		setCursorPosition(curCoord);

		Sleep(1000);


	}
}

int main()
{
	hidecursor();

	thread thrd1(czas);

	int a;
	cin >> a;
	cout << a << endl;

	
	cin.ignore();
	cin.get();

}



/* SORTOWANIE
#include <iostream>
#include <cstdio>
#include <ctime>
#include <thread>
#include <fstream>
#include <windows.h>
using namespace std;

const int s = 100;

fstream file;

void divide(int *tab, int left, int right);
void marge(int *tab, int left, int right, int mid);


int main()
{
	

	srand(time(NULL));
	int *tab = new int[s];
	//Losowanie bez powtorzen
	for (int i = 0; i < s; i++) {
		bool done;
		int num;
		do {
			done = true;
			num = rand() % s;
			for (int x = 0; x < i && done; x++)
				if (num == tab[x])
					done = false;

		} while (done == false);
		tab[i] = num;
	}

	file.open("file", ios::out);
	file << s << '\n';
	divide(tab, 0, s-1);
	file.close();

	for (int i = 0; i < s; ++i)
		cout << tab[i] << "\n";
	cout << "\n\n" << tab[0] << " " << tab[s - 1] << endl;

	cin.ignore();cin.get();
	return 0;
}


void divide(int *tab, int left, int right)
{
	if (left < right) 
	{
		int mid = (left + right) / 2;
		divide(tab, left, mid);
		divide(tab, mid + 1, right);
		marge(tab, left, right, mid);
	}
	
}

void marge(int *tab, int left, int right, int mid)
{
	//tab[left] -> tab[mid] -> tab[right]
	int lIter = left, rIter = mid + 1;

	int *temp = new int[right - left + 1];

	bool l = false, r=false;

	for (int i = 0; i < right - left + 1; ++i)
	{
		if ( (tab[lIter] < tab[rIter] && !l) || r)
		{
			temp[i] = tab[lIter];
			//cout << tab[lIter] << " >  " << tab[rIter] << "  left: " << left << "  right:  " << right << "   mid: " << mid << "    r-l: " << right - left + 1 << endl;

			if (lIter < mid)
				lIter++;
			else l = true;
		}
		else 
		{
			temp[i] = tab[rIter];
			//cout << tab[rIter] << " >= " << tab[lIter] << "  left: " << left << "  right:  " << right << "   mid: " << mid << "    r-l: " << right - left + 1 << endl;
			if (rIter < right)
				rIter++;
			else r = true;
		}
	}
	for (int i = left; i <= right; ++i)
		tab[i] = temp[i - left];
	for (int u = 0; u < s; u++)
		file << tab[u] << ' ';
	file << '\n';
}




/*
#include <iostream>
#include <string>
 
using namespace std;
 
struct car
{
    string marka;
    int rok;
};
 
int main()
{
    cout << "Ile samochodow chcesz skatalogowac? " ;
    int ile;
    cin>>ile;
	cin.ignore();
 
    car * ps = new car[ile];
 
    for(int i=0;i<ile;i++)
    {
       cout<<"Samochod #"<<(i +1)<<endl;
       cout<<"Podaj marke samochodu: ";
       getline(cin, ps[i].marka);
       cout<<"Rok produkcji: ";
	   cin >> ps[i].rok;
	   cin.ignore();
 
    }
 
    for(int j=0;j<ile;j++)
    {
        cout<<endl<<ps[j].rok<<" "<<ps[j].marka<<endl;
    }
 
 
delete [] ps;
 
 
    return 0;
}


//#include "stdafx.h"

/*
#include <iostream>
#include <cmath>
using namespace std;

void func(int **tab) {
	tab[0][0] = 0;
}

int main() {
	int tab[5][5];
	func(tab);
	cout << tab[0][0] << endl;
	cin.get();
	return 0;
}


//Przeładowania operatorów
/*
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Point {
public:
	float x, y;
	Point(float x=0, float y=0) : x(x), y(y) 
	{

	}
	Point operator + (Point point) {
		return Point(x + point.x, y + point.y);
	}
	Point operator - (Point point) {
		return Point(x - point.x, y - point.y);
	}
	Point operator * (Point point) {
		return Point(x * point.x, y * point.y);
	}
	Point operator / (Point point) {
		return Point(x / point.x, y / point.y);
	}

	Point operator + (float value) {
		return Point(x + value, y + value);
	}
	Point operator - (float value) {
		return Point(x - value, y - value);
	}
	Point operator * (float value) {
		return Point(x * value, y * value);
	}
	Point operator / (float value) {
		return Point(x / value, y / value);
	}

	Point& operator ()(float x, float y) {
		this->x = x;
		this->y = y;
		return *this;
	}

	Point& operator [](float x) {
		this->x += x;
		this->y += x;
		return *this;
	}
};


ostream& operator<<(ostream &target, Point &point) {
	return target << point.x << " " << point.y;
}

istream& operator>>(istream &target, Point &point) {
	return target >> point.x >> point.y;
}

int main() {
	Point point;
	point(20, 20);
	cout << point(20,28) << endl;
	cin.ignore();
	cin.get();
	return 0;
}
*/