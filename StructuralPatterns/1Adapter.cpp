#include "StructuralPatterns.h"

//市电类
class Electricity
{
public:
    virtual void Charge()//使用市电进行充电，输出验证电压的数值
    {
        cout << "220V charging..." << endl;
    }
};

//适配器类
class Adapter5V
{
public:
    void Transfer()//将电压转换为5V，输出验证
    {
        cout << "5V charging..." << endl;
    }
};

//类适配器，使用多继承的方式
class ElecWithClassAdapter5V :public Electricity, Adapter5V
{
public:
    virtual void Charge()//重写充电方法
    {
        Transfer();//直接调用适配器电压转换方法
    }
};

void ClassAdapterTest()
{
    Electricity* pEle = new Electricity();//如果不使用适配器
    pEle->Charge();

    Electricity* pEleWithAdapter = new ElecWithClassAdapter5V();//使用适配器
    pEleWithAdapter->Charge();
}

//对象适配器
class ElecWithObjectAdapter5V :public Electricity
{
public:
    ElecWithObjectAdapter5V() :pAdapter(NULL)
    {
        pAdapter = new Adapter5V();
    }
    virtual void Charge()//重写充电方法
    {
        pAdapter->Transfer();//通过适配器指针，调用电压转换方法
    }

private:
    Adapter5V* pAdapter;
};

void ObjectAdapterTest()
{
    Electricity* pEle = new Electricity();//如果不使用适配器
    pEle->Charge();

    Electricity* pEleWithAdapter = new ElecWithObjectAdapter5V();//使用适配器
    pEleWithAdapter->Charge();
}

void AdapterTest()
{
    cout << ".......start AdapterTest........" << endl;
    cout << ".......start ClassAdapterTest........" << endl;
    ClassAdapterTest();
    cout << ".......start ObjectAdapterTest........" << endl;
    ObjectAdapterTest();
}