#include <iostream>

class Log
{
public:
	//定义枚举，则可以将int删掉。注意，它并不是一个真正的命名空间。
	enum Level 
	{
		LevelError = 0, LevelWarning, LevelInfo
	};

private:
	//Everything get printted
	Level m_LogLevel = LevelInfo;//将该变量限定在Level中
public:
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[Error]:" << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[Warning]:" << message << std::endl;
	}
	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[Info]:" << message << std::endl;
	}
};

int main()
{
	Log log;
	log.SetLevel(Log::LevelError);
	log.Error("Hello");
	log.Warn("Hello");
	log.Info("Hello");
	std::cin.get();

}
