#include "StructuralPatterns.h"

//��ɫ������
class Color
{
public:
    virtual string GetColor() = 0;//��ȡ��ɫ��������֤
};

//��ɫʵ����
class Red :public Color
{
public:
    virtual string GetColor()//��ȡ��ɫ��������֤
    {
        return "Red";
    }
};

class Blue :public Color
{
public:
    virtual string GetColor()//��ȡ��ɫ��������֤
    {
        return "Blue";
    }
};

class Green :public Color
{
public:
    virtual string GetColor()//��ȡ��ɫ��������֤
    {
        return "Green";
    }
};

//��״������
class Shape
{
public:
    Shape(Color* pColor) :m_pColor(pColor) {}
    virtual void Show() = 0;//չʾ�ӿڣ���֤ʵ��������ɫ����״
protected:
    Color* m_pColor;//��ͼ�ε���ɫ��������״���Ž�
};

//��״ʵ����
class Circle :public Shape
{
public:
    Circle(Color* pColor) :Shape(pColor) {}//����Բ��ʱָ����ɫ
    void Show()//��дչʾ�ӿڣ�������֤
    {
        cout << m_pColor->GetColor() << "Circle" << endl;
    }
};

class Rectangle :public Shape
{
public:
    Rectangle(Color* pColor) :Shape(pColor) {}//�������ʱָ����ɫ
    void Show()//��дչʾ�ӿڣ�������֤
    {
        cout << m_pColor->GetColor() << "Rectangle" << endl;
    }
};

class Triangle :public Shape
{
public:
    Triangle(Color* pColor) :Shape(pColor) {}//����������ʱָ����ɫ
    void Show()//��дչʾ�ӿڣ�������֤
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