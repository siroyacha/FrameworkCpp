// ** Framework v19.0
// ** 디스에이블 리스트 확인하기
#include "MainUpdate.h"

int main(void)
{
	system("mode con:cols=150 lines=40");

	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 100 <= GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			Main.Update();
			Main.Render();
		}
	}

	return 0;
}