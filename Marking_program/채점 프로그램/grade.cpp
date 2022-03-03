// 2022-02-26 ver 0.2
// ������ ä�� ���α׷�
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
	cout << "���� ���� �Է�:(20 ���ϸ�) : ";
	cin >> len;
	while (cin.fail() || len > selLEN || len < 1)
	{
		system("cls");
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "## �ùٸ� ���ڸ� �Է��ϼ��� ##\n";
		cout << "���� �� �Է�: ";
		cin >> len;
	}
	system("cls");
	cout << "���� ��ȣ �Է�(80����): ";
	cin >> s_num;
	while (cin.fail() || s_num > s_LEN || s_num < 0)
	{
		system("cls");
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "## �ùٸ� ���ڸ� �Է��ϼ��� ##\n";
		cout << "���� ��ȣ �Է�(70����): ";
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
		cout << i + s_num << "�� ���� �Է�(�ڷΰ��� 0) : ";
		cin >> selNum[i];
		while (cin.fail() || selNum[i] > 5 || selNum[i] < 0)
		{
			system("cls");
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "## 5 ������ ���ڸ� �Է� ##\n";
			cout << i + s_num << "�� ���� �Է�(�ڷΰ��� 0) : ";
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
		cout << "��������������������������������������������������";
		gotoxy(TABLE_X, TABLE_Y + 1);
		cout << "��    ��                 ��";
		gotoxy(TABLE_X + 2, TABLE_Y + 1);
		cout << "������ �Է¦� ���䦢 �����";
		gotoxy(TABLE_X, TABLE_Y + 2);
		cout << "��������������������������������������������������";
		for (int i = 0; i < len; i++)
		{
			gotoxy(TABLE_X, TABLE_Y + j);
			cout << "��     ��     ��     ��     ��";
			gotoxy(TABLE_X + 2, TABLE_Y + j);
			cout << i + s_num << "��";
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
				cout << "����";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (answer[i] != selNum[i] && answer[i] > 0 && answer[i] < 6)
			{
				check[i] = false;
				gotoxy(TABLE_X + 20, TABLE_Y + j);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << "����";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			gotoxy(TABLE_X + 9, TABLE_Y + j);
			cout << selNum[i];
			gotoxy(TABLE_X, TABLE_Y + j + 1);
			if (i == len - 1)
				cout << "��     ��     ��     ��     ��";
			else
				cout << "��������������������������������������������������";
			j += 2;
		}
		gotoxy(TABLE_X, TABLE_Y + (j - 1));
		cout << "��������������������������������������������������";

		gotoxy(TABLE_X + 30, TABLE_Y + 2);
		if (sel < len)
		{
			cout << sel + s_num << "�� " << "���� �Է�(�ڷΰ��� 0)";
			gotoxy(TABLE_X + 30, TABLE_Y + 4);
			cout << "�Է�: "; cin >> answer[sel];
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
			cout << average << "��";
			gotoxy(TABLE_X + 30, TABLE_Y + 4);
			cout << "ó������ ���ư��� 0, �����ϱ� 9";
			gotoxy(TABLE_X + 30, TABLE_Y + 6);
			cout << "�Է�: "; cin >> ex;
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