#include<iostream>

//由于分配的不是连续的缓冲区，因此读取内存的时候，有可能出现cache miss。
//这样访问非常慢，比一维数组慢很多。

int main()
{
	int* array = new int[50];//分配50个4字节的内存块

	int** a2d = new int* [50];//指向指针的指针。只是分配了50*4的内存。
	for (int i = 0; i < 50; i++)
		a2d[i] = new int[50];//每个指针都指向一个50个元素的数组。

	a2d[0][0] = 0;//右一是要访问的整数，左一是指针的索引。
	a2d[0][1] = 0;
	a2d[0][1] = 0;

	for (int i = 0; i < 50; i++)
	{
		delete[] a2d[i];
	}
	delete[] a2d;//删除实际保存整型数组的指针。如果只有这句删除会内存泄漏，因为我们永远也无法访问了。

	int*** a3d = new int** [50];//三维数组。
	for (int i = 0; i < 50; i++)
	{
		a3d[i] = new int* [50];
		for (int j = 0; j < 50; j++)
		{
			int** ptr = a3d[i];
			ptr[j] = new int[50];
		}
	}
	
	//a2d[0] = nullptr;//分配的是int指针。
	std::cin.get();
}
