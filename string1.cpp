#include<iostream>

//字符类型，要用双引号。
//人们习惯声明const，因为字符串通常不可变，并不能将其扩展。
//它是固定分配的内存块，如果要更大的字符串，则需要将原来的内存块删掉，再分配一个新的内存。跟python似乎不一样。
//不能用delete name或是delete[name]之类的语句删除。
//经验法则：如果不用new，就别用delete。


int main()
{
	//注意，双引号默认指针。
	const char* name = "Cherno";
	//如果const了，就不能name[2]="a"，来改变第三个字符。若没有const则可以。
	//内存显示的00为空终止符。字符串从name指针的内存地址开始，终止于00。

	//也可以对字符串自行初始化，6个字符，用单引号‘’！下面的语句为数组，而非字符串
	char name2[6] = { 'C','h','e','r','n','o' };
	std::cout << name2 << std::endl;
	std::cin.get();
}
