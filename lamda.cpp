#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

//lamda是一个不需要通过函数定义，就可以定义一个函数的方法。
//lamda的用法是我们设置它为函数指针，指向函数的任何地方，都可以设置为lamda。将函数传递给api，等待某个时刻调用，此时还没有具体的数据。

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)//void(*func)(int)
{
	for (int value : values)
		func(value);
}
int main()
{
	std::vector<int> values = { 1,5,3,4,2 };
	auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });
	std::cout << *it << std::endl;//要解引用，打印出的是values里面的第一个＞3的值，即5。

	int a = 5;//如果要访问这个，那么可以通过值传入或引用传入。如果[]内不写东西，会报错，因为后面跟着的是封闭函数。

	//可以写[=]（传递所有变量）、[&]（引用所有变量）、[a]（传递a）
	auto lamda = [=](int value) {std::cout << "Value:" << value << std::endl; };//中括号叫捕获，可以什么都不捕获，也可以捕获多个。可以通过复制捕获，也可以通过引用捕获。
	ForEach(values,lamda);
	std::cin.get();
}
