#include <iostream>
#include<string>

//C++的标准库有个类叫string，（即）模板类BasicString类：std::string，模板参数是char。叫template specialization
//string有一个构造函数，接受char*或者const char*参数

//打印string的函数
//最好不要这样做，因为这实际上是一个副本。当把一个类对象传递给函数，实际上是在复制这个类对象
void PrintString(std::string string)
{
	//若将字符串延长，则延长的是复制后的字符串，不会影响原来的字符串。复制很耗费时间，所以最好以常量类型引用它。
	//可以将括号内改成(const std::string& string)
	string += "h";
	std::cout << string << std::endl;
}

int main()
{
	std::string name = "Cherno";
	//增长字符串，不能直接"cherno"+"hello!"这样加。+=这个字符号会被string类重载。
	name += "hello!";

	//或者调用一个显式string如下所示，但这会出现更多拷贝，它相当于多建了一个字符串。
	std::string name2 = std::string("Cherno") + "hello!";
	std::cout << name << std::endl;

	std::cin.get();
}
