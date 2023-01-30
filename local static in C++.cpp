#include<iostream>

class Singleton {

public:
	static Singleton& Get() {
		static Singleton instance;//若没有static，则该程序运行到下面的花括号后，该实例会被销毁
		return instance; }
	

	void hello(){}
};

Singleton* Singleton::s_Instance=nullptr;


int main()
{
	Singleton::Get().hello();
	std::cin.get();
}
