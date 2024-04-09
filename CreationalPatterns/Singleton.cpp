#include "CreationalPatterns.h"
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &instance;
	}
private:
	static Singleton instance;
	Singleton(){};
	Singleton(const Singleton&){}
};
Singleton Singleton::instance;
void SingletonTest()
{
	cout << "µ¥ÀýÄ£Ê½²âÊÔ................." << endl;
	Singleton::GetInstance();
}