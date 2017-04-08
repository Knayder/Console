#include "Console.h"



Console::~Console()
{
	delete[] buffer;
}

Console::Console(SHORT width, SHORT height)
{
	outHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	inHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleTitle(TEXT("Console"));

	windowSize = { 0, 0, width-1, height-1 };
	// Change the console window size:
	SetConsoleWindowInfo(outHnd, TRUE, &windowSize);

	bufferSize = { width,height };
	// Change the internal buffer size:
	SetConsoleScreenBufferSize(outHnd, bufferSize);

	buffer = new CHAR_INFO[width*height];

	charBufSize = bufferSize;
	characterPos = { 0,0 };
	writeArea = windowSize;
}



