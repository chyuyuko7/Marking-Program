// 2022-02-26 ver 0.2
// 간단한 채점 프로그램
// by YYK

#include <iostream>
#include <Windows.h>
#include "grade.h"

int main(void)
{
	SetConsoleTitle(TEXT("간단한 채점 프로그램"));		// 콘솔 타이틀 명
	system("mode con:cols=70 lines=45");				// 콘솔창 크기
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;	// 콘솔 숨기기
	ConsoleCursor.dwSize = true;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

//------------------------- 채점 프로그램 시작 ----------------------------
	grade GRADE;

	GRADE.InitScore();
	while (GRADE.DrawScore())
	{
		GRADE.~grade();
		GRADE.InitScore();
	}

	return 0;
}