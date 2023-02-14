#include<iostream>
#include<string>
#include<vector>

//优化vector类。优化的规则之一是，了解环境。
//构造一个Vertex时，实际上是在主函数的当前栈帧中构造它。

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		:x(x), y(y), z(z)
	{
	}
	Vertex(const Vertex& vertex)
		:x(vertex.x),y(vertex.y),z(vertex.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

int main()
{
	std::vector<Vertex> vertices;
	/*vertices.push_back({ 1,2,3 });
	vertices.push_back({ 4,5,6 });*/

	vertices.reserve(3);//可以让vertices的内存大小不必调整两次。
	//如果在构造函数中分配3个，就不仅是分配了三个对象的内存，还创建了三个vertex对象。当然这实际上也无法编译。
	/*vertices.push_back(Vertex(1, 2, 3));
	vertices.push_back(Vertex(4, 5, 6));
	vertices.push_back(Vertex(7, 8, 9));*/
	//有六次copied！！！
	//首先，创建一个Vertex是在主函数的栈帧中创建，然后C++会将该Vertex复制，放到vector分配的内存中。因此又复制了一次。
	//其次，vector在默认大小上是1，在这里为了增加新加进来的对象，调整了两次内存，因此copy了好多次。

	//用emplace_back，只是传递了构造函数的参数列表。
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);
	std::cin.get();
}
