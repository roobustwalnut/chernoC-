#include<iostream>

//栈和堆都在ram中。栈活跃在缓存当中。
//栈通常是一个预定义大小的内存区域，2兆字节左右的内存空间。
//堆也是预定义的内存空间，但它可以增长。
//栈分配是倒着来的，从顶部地址开始分配，然后栈指针向下移动。有点像CPU指针，移动栈指针，然后返回栈指针的地址。
//new实际上调用了malloc的函数，这通常会调用底层操作系统或平台的特定函数。如果需要的内存空间超过了此时能够提供的空余内存，程序会通知操作系统，这很麻烦。
//cache（高速缓存器），cpu要访问的数据在cache中有称为hit，没有称为miss。
//在堆上分配的原因：不能在栈上分配，变量生存期比函数长。

struct Vector3
{
	float x, t, z;
};

int main()
{
	int value = 5;
	int array[5];//栈分配
	Vector3 vector;

	int* hvalue = new int;//堆分配
	*hvalue = 5;
	int* harray = new int[5];//先给它分配了一个地址，然后数组内容从这个地址开始存储。 
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;
	Vector3* hvector = new Vector3();

	delete hvalue;
	delete[] harray;//用了new要删除。
	std::cin.get();
}
