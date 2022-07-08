// ** Framework v7.0
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
	/*
	Vector3 V1 = Vector3(1.0f, 1.0f);
	Vector3 V2 = Vector3(10.0f, 10.0f);
	Vector3 V3 = V1 - V2;
	Vector3 V4 = V1 + V2;

	cout << "v3 " << endl << "X : " << V3.x << " Y : " << V3.y << endl;
	cout << "v4 " << endl << "X : " << V4.x << " Y : " << V4.y << endl;
	*/
	
	return 0;
}