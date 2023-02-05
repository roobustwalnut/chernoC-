#include <iostream>
#include<array>

//数组：一个变量中包含多个变量。
//数组是连续的数据块。
//间接寻址。可能会导致memory fragmentation（内存碎片），cache miss（缓存丢失）
//c++11有内置数组，可以代替以下的原始数组。它能够边界检查，记录数组大小
//原始数组无法知道数组大小，like：example->sizeof(),是行不通的。
//不要在数组内存中访问数组大小。
//std::array更加可靠。


class Entity
{
public:
	static const int exampleSize = 5;//如果不声明static会报错。因为编译器需要一个常量。
	int example[exampleSize];

	//在栈上创建，访问example的内存地址发现，存储的就是一排2
	int example[5];
	//在堆上创建，存储的是另一个内存地址。cool，访问该内存地址（注意要将内存地址倒过来，因为Endian内存储存顺序）
	int* example = new int[5];
	//因此最好在栈上创建，这样内存不会跳来跳去，影响性能。
	std::array<int, 5>another;

	Entity()
	{
		int a[5];
		//计数器，即用数组大小a除以单个元素的大小int。size一般指字节数，count一般指计数器。
		int count = sizeof(a) / sizeof(int);
		int count = sizeof(example) / sizeof(int);
		for (int i = 0; i < 5; i++)
			example[i] = 2;
	}
};
int main()
{
	
	std::cin.get();
}
