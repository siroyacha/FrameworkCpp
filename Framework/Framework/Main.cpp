// ** Framework v11.0
// 8/4까지 작업 완료
// 홀로큐어처럼 만들어보기
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