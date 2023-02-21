#include<iostream>
#include<vector>
#include<algorithm>//里面有排序
#include<functional>

int main()
{
	std::vector<int> values = { 3,5,1,4,2 };
	std::sort(values.begin(), values.end(),std::greater<int>());//如果不提供这个的话，会按整数升序排列。加上greater是从大到小。
	for (int value : values)
		std::cout << value << std::endl;
	std::cin.get();
}
