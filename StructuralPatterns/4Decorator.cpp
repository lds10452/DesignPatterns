#include "StructuralPatterns.h"

//�������
class Man
{
public:
    virtual ~Man() {}
    virtual void Show()//����չʾ
    {
        cout << "A man." << endl;
    }
};

//װ����������
class ManWithCloth :public Man//�̳���Man��Ϊ��ʹ��װ�εĶ�����Դ�������װ�����������װ��
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

    virtual void Show()//����ʵ�ַ�ʽ�еĵڶ���
    {
        m_pMan->Show();//ͨ��ָ�����ԭָ����ָ����ķ�����Ȼ����ӷ�����������
        DressUp();//��ԭ������������
    }
    virtual void DressUp() = 0;//���η�����ʵ������ʵ��

private:
    Man* m_pMan;
};

//װ����ʵ����
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