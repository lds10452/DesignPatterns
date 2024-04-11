#include "StructuralPatterns.h"

//人物基类
class Man
{
public:
    virtual ~Man() {}
    virtual void Show()//用于展示
    {
        cout << "A man." << endl;
    }
};

//装饰器抽象类
class ManWithCloth :public Man//继承自Man，为了使被装饰的对象可以传入其他装饰器进行组合装饰
{
public:
    ManWithCloth(Man* pMan)
        :m_pMan(pMan) {}
    virtual ~ManWithCloth()
    {
        if (NULL != m_pMan)
        {
            delete m_pMan;
            m_pMan = NULL;
        }
    }

    virtual void Show()//上述实现方式中的第二步
    {
        m_pMan->Show();//通过指针调用原指针所指对象的方法，然后添加方法进行修饰
        DressUp();//对原方法增加修饰
    }
    virtual void DressUp() = 0;//修饰方法在实现类中实现

private:
    Man* m_pMan;
};

//装饰器实现类
class ManWearAHat :public ManWithCloth
{
public:
    ManWearAHat(Man* pMan)
        :ManWithCloth(pMan) {}
    virtual void DressUp()
    {
        cout << "Wear a Hat." << endl;
    }
};

class ManWearShoes :public ManWithCloth
{
public:
    ManWearShoes(Man* pMan)
        :ManWithCloth(pMan) {}
    virtual void DressUp()
    {
        cout << "Wear shoes." << endl;
    }
};

void DecoratorTest()
{
	cout << ".......start DecoratorTest........" << endl;
    Man* pMan = new Man();
    pMan->Show();

    cout << "=====Wear Hat=====" << endl;
    pMan = new ManWearAHat(pMan);
    pMan->Show();

    cout << "====Wear Shoes====" << endl;
    pMan = new ManWearShoes(pMan);
    pMan->Show();

    delete pMan;
    pMan = NULL;
}