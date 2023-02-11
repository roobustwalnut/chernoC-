#include<iostream>
#include<string>

//重载运算符，在C#中部分支持，在Java中不支持。运算符就是函数。

struct Vector2
{
	float x, y;
	Vector2(float x,float y)
		:x(x),y(y){}

	Vector2 Add (const Vector2& other) const
	{
		return *this + other;
		//return operator+(other);
	}

	//重载运算符
	Vector2 operator+(const Vector2& other)const
	{
		return Vector2(x + other.x, y + other.y);
		//最好还是用Add来表示重载运算符，也就是现在的表示方式反过来。
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}
	//重载运算符
	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
	}
	bool operator==(const Vector2& other)const
	{
		return x == other.x && y == other.y;
	}
	bool operator!=(const Vector2& other)const
	{
		return !(*this==other);//计算取反
	}
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << "," << other.y;
	return stream;
}

int main()
{
	Vector2 Position(4.0f, 4.0f);
	Vector2 Speed(0.5f, 1.5f);
	Vector2 Powerup(1.1f, 1.1f);//加快百分之十的速度

	Vector2 Result1 = Position.Add(Speed.Multiply(Powerup));//唯一的选择in Java
	Vector2 Result2 = Position + Speed * Powerup;

	if (Result1 == Result2)
	{
		//重载后能用了
	}
	std::cout << Result2 << std::endl;//此时<<经过了重载。

	std::cin.get();
}
