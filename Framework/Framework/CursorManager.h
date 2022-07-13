#pragma once
#include"Headers.h"


class CursorManager
{
private:
	static CursorManager* Instance;
public:
	static CursorManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new CursorManager;
		return Instance;
	}
private:
	int BufferIndex;
	HANDLE HBuffer[2];
public:
	void CreateBuffer(const int& _Width, const int& _Height);
	void WriteBuffer(float _x, float _y, char* _str, int _Color = 15);
	void WriteBuffer(Vector3 _Position, char* _str, int _Color = 15);
	void FlippingBuffer();
private:
	void SetColor(int _Color);
	void ClearBuffer();
	void DestroyBuffer();
private:
	CursorManager();
public:
	~CursorManager();
};