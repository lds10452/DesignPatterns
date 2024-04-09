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
	cout << "����ģʽ����................." << endl;
	Singleton::GetInstance();
}