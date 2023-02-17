#include<iostream>
#include<array>

//array和vector的存储位置不同，array存储在栈中，vector存储在堆中。

//或者PrintArray(const std::array<int,5>& data)这样传递必须知道详细的数组信息，好像不好。用模板？
void PrintArray(int* array,unsigned int size)
{
	for (int i=0;i<size;i++)//如果要for循环。
	{ }
}

int main()
{
	std::array<int, 5> data;
	data.size();//可以访问它的大小，因为它是一个类。size函数直接返回一个int，即5。
	data[0] = 1;
	data[1] = 2;
	data[6] = 3;//这在debug情况下会崩溃，提醒超出边界

	int dataold[5];
	data[6] = 1;//这在debug情况下没有问题，但会覆盖未被分配的内存
	std::cin.get();
}
