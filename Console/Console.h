
#pragma once

#include <Windows.h>
#include <tchar.h>
#include "Drawable.h"



class Console
{
public:
	Console(SHORT width, SHORT height);

	~Console();

	/*copying constr. and operat.*/
	Console(const Console &source) {
		inHnd = source.inHnd;
		outHnd = source.outHnd;
		windowSize = source.windowSize;
		bufferSize = source.bufferSize;
		charBufSize = source.charBufSize;
		characterPos = source.characterPos;
		writeArea = source.writeArea;

		int tempBufferSize = bufferSize.X * bufferSize.Y;
		buffer = new CHAR_INFO[tempBufferSize];
		for (int i = 0; i < tempBufferSize; i++)
			buffer[i] = source.buffer[i];
	}

	void operator = (const Console &source) {
		inHnd = source.inHnd;
		outHnd = source.outHnd;
		windowSize = source.windowSize;
		bufferSize = source.bufferSize;
		charBufSize = source.charBufSize;
		characterPos = source.characterPos;
		writeArea = source.writeArea;

		int tempBufferSize = bufferSize.X * bufferSize.Y;
		buffer = new CHAR_INFO[tempBufferSize];
		for (int i = 0; i < tempBufferSize; i++)
			buffer[i] = source.buffer[i];
	}

	/*Getters*/

	inline CHAR_INFO * getBuffer() {
		return buffer;
	}

	inline HANDLE getOutHnd() {
		return outHnd;
	}

	inline HANDLE getInHnd() {
		return inHnd;
	}

	inline COORD getBufferSize() {
		return bufferSize;
	}

	inline SMALL_RECT getWindowSize() {
		return windowSize;
	}


	inline CHAR_INFO * getFromBuffer(INT x, INT y) {
		return buffer + (x + bufferSize.X * y);
	}

	/*Display buffer to console's buffer*/
	inline void display() {
		WriteConsoleOutputA(outHnd, buffer, charBufSize, characterPos, &writeArea);
	}

	/*Add drawable object to buffer*/
	void draw(const Drawable &drawable) {
		drawable.draw(*this);
	}

	/*Clear buffer*/
	inline void clearBuffer(WORD value = 0) {
		for (int i = 0; i < bufferSize.X * bufferSize.Y; i++) {
			buffer[i].Attributes = value;
			buffer[i].Char.AsciiChar = ' ';
		}
	}

	

private:
	
	HANDLE inHnd; //From console - rHnd
	HANDLE outHnd; //To console - wHnd

	SMALL_RECT windowSize;
	COORD bufferSize;
	CHAR_INFO *buffer;
	COORD charBufSize;
	COORD characterPos;
	SMALL_RECT writeArea;
};

