#include<iostream>

//如果想要一个函数能够返回不同类型的参数，一般情况下需要写好几个参数。用template模板就可以解决这个问题。
//编译器不会对不使用的模板报错，模板只有在调用时，才会转换为真正的代码。

template <typename T, int N>//不用动态数组的情况下。
class Array
{
private:
	T m_Array[N];//栈分配数组，希望在编译时获得该数组的大小。
public:
	int GetSize() const { return N; }
};

template<typename T>//在这里写class也行
void Print(T value)
{
	//如果把下面一行的value改为valu（不存在的名），若不调用Print函数，编译器依然能够编译。这意味着模板实际上并不存在，直到我们调用它。
	std::cout << value << std::endl;
}

int main()
{
	Print(5);
	Print<std::string>("Good!");//尖括号内的类型名会代替T，括号内的内容要与尖括号填写的类型匹配。

	Array<int, 5> array;//意味着创建这个模板类型，N=5。
	std::cout << array.GetSize() << std::endl;
	std::cin.get();
}
