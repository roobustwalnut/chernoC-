#include<iostream>
#include<string>
#include<vector>

//Vector本质上是动态数组，也就是没有固定大小的数组。跟数学上的向量完全不同。
//开始创建一个Vector时，系统可能自动给它分配10个元素，如果用满了，系统会另外开一块内存空间存储所有的元素，并把原来的内存空间存的数据删掉。

struct Vertex
{
	float x, y, z;
};

//重载运算符
std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << "," << vertex.y << "," << vertex.z;
	return stream;
}

void Function(const std::vector<Vertex>& vertices)
{
	//在函数中传递时，确保用的是引用，不会在调用函数时复制了整个数组。
}

int main()
{
	std::vector<Vertex> Vertices;//<>内是数组内元素的类型，最右侧是该数组的名称。Java和C#比较像，不能指定类类型？
	//要存储Vertex对象还是Vertex指针呢？存储对象在技术上更优。因为存储对象在内存上是连续的（动态数组的特性）。他们都在一条高速缓存线上。
	//反正最好用对象。不到万不得已不用指针。
	Vertices.push_back({ 1,2,3 });//加入Vertex
	Vertices.push_back({ 4,5,6 });

	for (int i = 0; i < Vertices.size(); i++)
		std::cout << Vertices[i] << std::endl;

	Vertices.erase(Vertices.begin() + 1);//删除第2个元素。不能直接在括号里写2。括号里的类型是iterator迭代器。

	for (const Vertex& v : Vertices)//用range来构造for函数。加&防止复制。
		std::cout << v << std::endl;

	
	Vertices.clear();//清除数组。

	std::cin.get();
}
