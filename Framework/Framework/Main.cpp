// ** Framework v3.1.1
// 숙제 : 메인 돌아가는 함수 순서도 써서 찍어서 개인톡으로 보내기
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