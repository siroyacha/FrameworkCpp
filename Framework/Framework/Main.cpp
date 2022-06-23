// ** Framework v.0.2
#include <iostream>

namespace AAA
{
	void Output()
	{
		printf_s("AAA");
	}
}

namespace BBB
{
	void Output()
	{
		printf_s("BBB");
	}
}

namespace CCC
{
	void Output()
	{
		printf_s("CCC");
	}
}

int main(void)
{
	AAA::Output();




	return 0;
}