// 2022-02-26 ver 0.2
// ������ ä�� ���α׷�
// by YYK
#ifndef __GRADE_H__
#define __GRADE_H__
#include <iostream>
#include <Windows.h>

#define TABLE_X 5					// ���̺� X ��ǥ
#define TABLE_Y 1					// ���̺� Y ��ǥ

using namespace std;

class grade
{
private:
	int* selNum;	// üũ ���
	int* answer;	// ���� ���
	int len;		// ���� ����
	int s_num;		// ���� ��ȣ
	bool* check;	// ä�� 
	double average;	// ����� ����� ���
	COORD Pos;		// ��ǥ ��
public:
	grade();		// �⺻ ������
	~grade();		// �Ҹ��� 

//-------------------------------------------------------------
	void InitScore(void);			// ���� ������ ���� üũ�ϱ�
	bool DrawScore(void);			// �Է��� ���� ǥ�� �� ���� üũ
//-------------------------------------------------------------

	void gotoxy(int x, int y);		// ��ǥ �̵� �Լ�
};

#endif