#include <iostream>

class Entity
{
public:
	
	float x, y;

	//void Init()//Entity对象实例初始化。缺点是每次创建实例都要初始化，非常麻烦。故考虑构造函数。
	//{
	//	x = 0.0f;
	//	y = 0.0f;
	//}

	//构造函数。若不构造函数，也会默认指定一个函数，只是该函数为空
	/*Entity()
	{
		x = 0.0f;
		y = 0.0f;
	}*/

	//函数重载
	Entity(float X,float Y)//X,Y作为参数
	{
		x = X;
		y = Y;
	}
	void Print()
	{
		std::cout << x << "," << y << std::endl;
	}
};

class Log
{
private://方法一、隐藏构造函数
	Log(){}

public:
	Log() = delete;//方法二、删除默认函数（一、二选其一）
	static Log Write()
	{

	};
};

int main()
{
	Log::Write();//调用方法
	Log l;//创建实例
	Entity e(10.f,5.f);//任意赋值
	/*e.Init();*/
	std::cout << e.x << std::endl;//局部变量需要初始化
	e.Print();
	std::cin.get();
}
