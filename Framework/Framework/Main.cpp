// ** Framework v33.0
// ** 27일 끝내기
#include "MainUpdate.h"

int main(void)
{
	system("mode con:cols=150 lines=60");

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