// 2022-02-26 ver 0.2
// ������ ä�� ���α׷�
// by YYK

#include <iostream>
#include <Windows.h>
#include "grade.h"

int main(void)
{
	SetConsoleTitle(TEXT("������ ä�� ���α׷�"));		// �ܼ� Ÿ��Ʋ ��
	system("mode con:cols=70 lines=45");				// �ܼ�â ũ��
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;	// �ܼ� �����
	ConsoleCursor.dwSize = true;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

//------------------------- ä�� ���α׷� ���� ----------------------------
	grade GRADE;

	GRADE.InitScore();
	while (GRADE.DrawScore())
	{
		GRADE.~grade();
		GRADE.InitScore();
	}

	return 0;
}