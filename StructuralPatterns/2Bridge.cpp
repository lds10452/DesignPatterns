#include "StructuralPatterns.h"

//颜色抽象类
class Color
{
public:
    virtual string GetColor() = 0;//获取颜色，用于验证
};

//颜色实现类
class Red :public Color
{
public:
    virtual string GetColor()//获取颜色，用于验证
    {
        return "Red";
    }
};

class Blue :public Color
{
public:
    virtual string GetColor()//获取颜色，用于验证
    {
        return "Blue";
    }
};

class Green :public Color
{
public:
    virtual string GetColor()//获取颜色，用于验证
    {
        return "Green";
    }
};

//形状抽象类
class Shape
{
public:
    Shape(Color* pColor) :m_pColor(pColor) {}
    virtual void Show() = 0;//展示接口，验证实现类中颜色与形状
protected:
    Color* m_pColor;//将图形的颜色抽象，与形状类桥接
};

//形状实现类
class Circle :public Shape
{
public:
    Circle(Color* pColor) :Shape(pColor) {}//构造圆形时指定颜色
    void Show()//重写展示接口，用于验证
    {
        cout << m_pColor->GetColor() << "Circle" << endl;
    }
};

class Rectangle :public Shape
{
public:
    Rectangle(Color* pColor) :Shape(pColor) {}//构造矩形时指定颜色
    void Show()//重写展示接口，用于验证
    {
        cout << m_pColor->GetColor() << "Rectangle" << endl;
    }
};

class Triangle :public Shape
{
public:
    Triangle(Color* pColor) :Shape(pColor) {}//构造三角形时指定颜色
    void Show()//重写展示接口，用于验证
    {
        cout << m_pColor->GetColor() << "Triangle" << endl;
    }
};

void BridgeTest()
{
    cout << ".......start BridgeTest........" << endl;
    Shape* pBlueCircle = new Circle(new Blue());
    pBlueCircle->Show();
}