#include<iostream>

//在此列出想要的类型，如此ABC就不需要int了
enum Example :unsigned char //通过冒号指定枚举的整数类型，左侧示例为8位。不能指定浮点数。
{
	A,B,C //若指定A=3，则BC会顺次递增为4、5，除非指定
};

int A = 0;
int B = 1;
int C = 2;

int main() 
{
	Example value = B;//这里的int改为Example，如果该value设为别的值，会出现error
	if (value == B)
	{
		//do something
	}

	std::cin.get();
}
