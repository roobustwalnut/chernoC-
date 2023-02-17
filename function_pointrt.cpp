#include<iostream>
#include<vector>

//函数指针（raw function pointer），将函数赋值给一个变量。可以把函数作为参数传递给另一个函数（？）因此auto关键字在函数指针中非常有用。
//函数只是CPU指令，因此编译时它就在二进制文件的某个地方。
//lamda函数，本质是一个普通函数，但函数声明与普通函数有所不同。在代码中生成，用完即弃。


void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void PrintValue(int value)
{
	std::cout << "Value:" << value << std::endl;
}

//常量引用，表示传入一个整数类型的向量，调用函数指针访问向量中的元素。第二个参数是函数指针，用这个函数来处理前一个参数里的每个元素。
void ForEach(const std::vector<int>& values,void(*func)(int))
{
	for (int value : values)
		func(value);
}

int main()
{
	typedef void(*HelloWorldFuntion)();
	HelloWorldFuntion function = HelloWorld;

	//void (*function)() = HelloWorld;//function只是一个名字。第二个括号里面放参数。奇怪的代码，别用。
	// 
	//auto function = HelloWorld();//不能推导，因为它的返回类型是void。
	//auto function = HelloWorld;//去掉括号就能行得通，这是因为此时调用的是函数指针。隐式转换，前面可以加个&。

	//function();//如果HelloWorld函数有参数，则必须在该括号内赋值。

	//以下是vector的例子
	std::vector<int> values = { 1, 5, 4, 2, 3 };//初始化列表。
	ForEach(values, PrintValue);//传入的是一个函数。

	//用lamda函数操作，匿名函数。[]是捕获方式，也就是如何传入传出参数。
	ForEach(values, [](int value) {std::cout << "Value:" << value << std::endl; });

	std::cin.get();
}
