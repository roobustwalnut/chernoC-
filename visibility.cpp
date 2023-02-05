#include <iostream>
#include<string>

//可见性修饰符：private、protected、public
//class的默认可见性为private，struct的默认可见性为public
//protected为这个类及其所有子类，都可以访问。
//可见性与性能无关，是为了更易读写，更易维护。因为写的代码很容易忘记。

class Entity
{
private:
	int X, Y;//默认的可见性是私有的（private）,子类也不能访问，只有友元可以。

	void Print() {}//如果函数为private，那么函数只能在该类调用，即使子类也不能调用。
public:
	Entity()
	{
		X = 0;
		Print();
	}
};

class Player :public Entity
{
	//Print();
};

int main()
{
	Entity e;
	std::cin.get();
}
