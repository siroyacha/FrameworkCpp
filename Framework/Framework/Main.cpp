/*
?Zoom 회의 참가
https://zoom.us/j/6367483103?pwd=QzlMazRvSlhGTVVxakEvSm8zaUlBUT09

회의 ID: 636 748 3103
암호: M9XKQ0
*/

// ** Framework v1.0
#include <iostream>
#include <Windows.h>

using namespace std;

int main(void)
{
	// ** DWORD unsigned long
	// ** ULONGLONG unsigned int64
	
	
	//									1 / 1000		max 시간 = 49일
	DWORD dwTime = GetTickCount();

	//									1 / 1000		max 시간 = 500년
	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 1000 <= GetTickCount64())
		{
			Time = GetTickCount64();
		}
	}


	return 0;
}