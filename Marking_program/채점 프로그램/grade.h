// 2022-02-26 ver 0.2
// 간단한 채점 프로그램
// by YYK
#ifndef __GRADE_H__
#define __GRADE_H__
#include <iostream>
#include <Windows.h>

#define TABLE_X 5					// 테이블 X 좌표
#define TABLE_Y 1					// 테이블 Y 좌표

using namespace std;

class grade
{
private:
	int* selNum;	// 체크 기록
	int* answer;	// 정답 기록
	int len;		// 문제 개수
	int s_num;		// 시작 번호
	bool* check;	// 채점 
	double average;	// 결과의 평균을 계산
	COORD Pos;		// 좌표 값
public:
	grade();		// 기본 생성자
	~grade();		// 소멸자 

//-------------------------------------------------------------
	void InitScore(void);			// 문제 개수와 문항 체크하기
	bool DrawScore(void);			// 입력한 문항 표시 및 정답 체크
//-------------------------------------------------------------

	void gotoxy(int x, int y);		// 좌표 이동 함수
};

#endif