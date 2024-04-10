#include "CreationalPatterns.h"

//果汁的抽象类
class Juice
{
public:
    virtual Juice* Clone() = 0; // 用于对象类型拷贝
    virtual void Show() = 0; // 验证果汁类型
};

//派生类
class OrangeJuice : public Juice
{
public:
    virtual Juice* Clone()
    {
        return new OrangeJuice(*this); // 返回当前对象类型的拷贝
    }

    virtual void Show()
    {
        cout << "Orange Juice" << endl;
    }
};

class LemonJuice : public Juice
{
public:
    virtual Juice* Clone()
    {
        return new LemonJuice(*this);
    }

    virtual void Show()
    {
        cout << "Lemon Juice" << endl;
    }
};

class AppleJuice : public Juice
{
public:
    virtual Juice* Clone()
    {
        return new AppleJuice(*this);
    }

    virtual void Show()
    {
        cout << "Apple Juice" << endl;
    }
};

void PrototypeTest()
{
    cout << ".......start PrototypeTest........" << endl;
    Juice* pJuice = new AppleJuice(); // 基类指针指向派生类对象
    pJuice->Show();
    /*
     * 经过/传递了很久很久之后
     * 以至于忘记了或难以确定
     * 该基类指针所指向的对象具体类型
     */
    Juice* pNewJuice = pJuice->Clone(); // 获取拷贝对象
    pNewJuice->Show();
}