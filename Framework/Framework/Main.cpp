// ** Framework v3.2
// 시험 : 오늘자 분량까지 암기시험

#include "MainUpdate.h"

int main(void)
{
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