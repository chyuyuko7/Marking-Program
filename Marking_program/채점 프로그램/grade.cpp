// 2022-02-26 ver 0.2
// 간단한 채점 프로그램
// by YYK
#include "grade.h"

grade::grade() : average(0), len(0), s_num(0)
{
	selNum = nullptr;
	answer = nullptr;
	check = nullptr;
}

grade::~grade()
{
	delete[]selNum;
	delete[]answer;
	delete[]check;
}

void grade::InitScore(void)
{

	system("cls");
	cout << "문제 개수 입력:(20 이하만) : ";
	cin >> len;
	while (cin.fail() || len > selLEN || len < 1)
	{
		system("cls");
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "## 올바른 숫자를 입력하세요 ##\n";
		cout << "문제 수 입력: ";
		cin >> len;
	}
	system("cls");
	cout << "시작 번호 입력(80이하): ";
	cin >> s_num;
	while (cin.fail() || s_num > s_LEN || s_num < 0)
	{
		system("cls");
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "## 올바른 숫자를 입력하세요 ##\n";
		cout << "시작 번호 입력(70이하): ";
		cin >> s_num;
	}
	selNum = new int[len];
	answer = new int[len];
	for (int i = 0; i < len; i++)
		answer[i] = 0;
	check = new bool[len];
		
	for (int i = 0; i < len; i++)
	{
	restart:
		system("cls");
		cout << i + s_num << "번 정답 입력(뒤로가기 0) : ";
		cin >> selNum[i];
		while (cin.fail() || selNum[i] > 5 || selNum[i] < 0)
		{
			system("cls");
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "## 5 이하의 숫자만 입력 ##\n";
			cout << i + s_num << "번 정답 입력(뒤로가기 0) : ";
			cin >> selNum[i];
		}
		if (selNum[i] == 0 && i > 0)
		{
			i--;
			goto restart;
		}
		else if (selNum[i] == 0)
			goto restart;
	}
}

bool grade::DrawScore(void)
{
	int j = 3;
	int sel = 0;
	int ex;
	bool sw = true;

	while (true)
	{
	reSel:
		Sleep(30);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("cls");
		gotoxy(TABLE_X, TABLE_Y);
		cout << "┌─────┬─────┬─────┬─────┐";
		gotoxy(TABLE_X, TABLE_Y + 1);
		cout << "│    │                 │";
		gotoxy(TABLE_X + 2, TABLE_Y + 1);
		cout << "문제│ 입력│ 정답│ 결과│";
		gotoxy(TABLE_X, TABLE_Y + 2);
		cout << "├─────┼─────┼─────┼─────┤";
		for (int i = 0; i < len; i++)
		{
			gotoxy(TABLE_X, TABLE_Y + j);
			cout << "│     │     │     │     │";
			gotoxy(TABLE_X + 2, TABLE_Y + j);
			cout << i + s_num << "번";
			if (answer[i] > 0 && answer[i] < 6)
			{
				gotoxy(TABLE_X + 15, TABLE_Y + j);
				cout << answer[i];
			}
			if (answer[i] == selNum[i])
			{
				check[i] = true;
				gotoxy(TABLE_X + 20, TABLE_Y + j);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "정답";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (answer[i] != selNum[i] && answer[i] > 0 && answer[i] < 6)
			{
				check[i] = false;
				gotoxy(TABLE_X + 20, TABLE_Y + j);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << "오답";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			gotoxy(TABLE_X + 9, TABLE_Y + j);
			cout << selNum[i];
			gotoxy(TABLE_X, TABLE_Y + j + 1);
			if (i == len - 1)
				cout << "│     │     │     │     │";
			else
				cout << "├─────┼─────┼─────┼─────┤";
			j += 2;
		}
		gotoxy(TABLE_X, TABLE_Y + (j - 1));
		cout << "└─────┴─────┴─────┴─────┘";

		gotoxy(TABLE_X + 30, TABLE_Y + 2);
		if (sel < len)
		{
			cout << sel + s_num << "번 " << "정답 입력(뒤로가기 0)";
			gotoxy(TABLE_X + 30, TABLE_Y + 4);
			cout << "입력: "; cin >> answer[sel];
		}
		else
		{
			if (sw) 
			{
				double temp = 0;
				for (int i = 0; i < len; i++)
					temp += check[i];
				average = (temp / len) * 100;
				sw = false;
			}
			cout.precision(4);
			cout << "Score: ";
			cout << average << "점";
			gotoxy(TABLE_X + 30, TABLE_Y + 4);
			cout << "처음으로 돌아가기 0, 종료하기 9";
			gotoxy(TABLE_X + 30, TABLE_Y + 6);
			cout << "입력: "; cin >> ex;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				j = 3;
				goto reSel;
			}
			else if (ex == 0)
				return true;
			else if (ex == 9)
				return false;
		}
		while (cin.fail() || answer[sel] < 0 || answer[sel] > 5)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			j = 3;
			goto reSel;
		}
		if (answer[sel] == 0 && sel > 0)
		{
			sel--;
			answer[sel] = 0;
			j = 3;
			goto reSel;
		}
		else if (answer[sel] == 0)
		{
			j = 3;
			goto reSel;
		}
		sel++;
		j = 3;
	}
}

void grade::gotoxy(int x, int y)
{
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}