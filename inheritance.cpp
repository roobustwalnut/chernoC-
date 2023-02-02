#include <iostream>

///继承，允许有一个相互关联的关于类的层次结构，包含公共功能的基类。
///从最初的父类发展出子类，可以节省代码空间

class Entity
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}

};

class Player:public Entity//冒号后面的为继承功能
{
public:
	const char* Name; 
	//以下部分与Entity重复，因此可以用继承，创建新的Player类，但提供其它额外功能。
	//float X, Y;

	//void Move(float xa, float ya)
	//{
	//	X += xa;
	//	Y += ya;
	//}//当Player成为Entity的继承子类时，该重复部分可以删掉。

	void Printname()
	{
		std::cout << Name << std::endl;
	}
};

int main()
{
	std::cout << sizeof(Player) << std::endl;//验证Player是否继承了父类Entity。
	//Entity定义了xy，player增加了Name，故它的size应该为12。
	Player player;
	player.Move(5, 5);//player也可以用Entity内部的函数
	std::cin.get();
}
