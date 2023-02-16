#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

//auto关键字，C++可以推断出可能的类型。
//好处是如果定义的函数返回类型需要更改，那么在主函数中不用改就可以用（例如发布到客户端）。但坏处是会破坏依赖特定类型的代码。

const char* GetName()//这里要加上const，保证这是一个常量字符串字面量。尝试通过返回指针修改常量字面量会导致未定义行为。C++中允许将一个字符数组指针隐式转换为一个char*类型的指针。
{
	return "Cherno";//字符串名称是指向其第一个元素的指针。返回字符串实际上是返回该数组的指针。
	//返回指向局部变量的指针是一种未定义行为，但Cherno是常量字面量，存储在程序的静态存储区域，在函数调用后仍然有效。
}

class Device{};
class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}
};

int main()
{
	std::string name = GetName();//在这里如果使用auto，则会发生错误，这是硬币的另一面。
	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	for (std::vector<std::string>::iterator it = strings.begin();//这里把std::vector<std::string>::iterator换成auto可以让代码更可读。
		it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	int a = 5;
	auto b = a;

	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	typedef std::unordered_map<std::string, std::vector<Device*>>DeviceMap;

	DeviceManager dm;
	dm.GetDevices();
	const DeviceMap& devices = dm.GetDevices();//如果类型名巨长无比，像这个DeviceMap这样，我们可以用auto，就不用using了。
	
	std::cin.get();
}
