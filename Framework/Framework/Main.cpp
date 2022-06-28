// ** Framework v2.0.1
#include "MainUpdate.h"

// ** Singleton
class Singleton
{
private:
	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance==nullptr)
		{
			Instance = new Singleton;
		}
		return Instance;
	}
};
Singleton* Singleton::Instance = nullptr;

int main(void)
{


	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	int i = 0;
	while (true)
	{
		if (Time + 30 <= GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");
			Main.Update();

			Main.Render();

		}
	}


	return 0;
}