#include <iostream>

//数组：一个变量中包含多个变量。
//数组是连续的数据块。
//间接寻址。可能会导致memory fragmentation（内存碎片），cache miss（缓存丢失）

int main()
{
	int example[5];//1、创建数组，该数组内有5个变量。2、在栈上创建，到右花括号时会被销毁。
	//example[0] = 2;
	//example[4] = 4;
	for (int i; i < 5; i++)
		example[i] = 2;
	/*
	* //1、关于数组与指针
	int* ptr = example;//事实证明example确实是指针类型。

	//for循环赋值，最好用i<5，而不是i<=4。因为前者一方面更易读，即5个整数；另一方面提高性能，≤要分别比较＜和=。
	for (int i; i < 5; i++)
		example[i] = 2;

	//会出现memory access violation，即内存访问违规。在debug情况下，会显示内存溢出来帮助你debug
	example[2] = 5;
	*(ptr + 2) = 6;//逆向引用指针。指针类型的+2意味着地址偏移量为2*4.因为example是4位的int
	//如果要变成字节类的，则为以下语句。首先将ptr改为字符型，字符型则应+8，然后再将该字符串改为整数指针。
	*(int*)((char*)ptr + 8) = 6;
	* 
	*/

	int* another = new int[5];//在堆上创建的数组，在程序将它销毁前都处于活动状态。用new分配的内存将一直存在，直到被删除
	for (int i; i < 5; i++)
		another[i] = 2;
	delete another[];
	std::cout << example[4] << std::endl;
	std::cout << example << std::endl;//example在这里是指针整形类型，打印出的是地址。
	std::cin.get();
}
