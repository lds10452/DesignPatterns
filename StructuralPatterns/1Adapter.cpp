#include "StructuralPatterns.h"

//�е���
class Electricity
{
public:
    virtual void Charge()//ʹ���е���г�磬�����֤��ѹ����ֵ
    {
        cout << "220V charging..." << endl;
    }
};

//��������
class Adapter5V
{
public:
    void Transfer()//����ѹת��Ϊ5V�������֤
    {
        cout << "5V charging..." << endl;
    }
};

//����������ʹ�ö�̳еķ�ʽ
class ElecWithClassAdapter5V :public Electricity, Adapter5V
{
public:
    virtual void Charge()//��д��緽��
    {
        Transfer();//ֱ�ӵ�����������ѹת������
    }
};

void ClassAdapterTest()
{
    Electricity* pEle = new Electricity();//�����ʹ��������
    pEle->Charge();

    Electricity* pEleWithAdapter = new ElecWithClassAdapter5V();//ʹ��������
    pEleWithAdapter->Charge();
}

//����������
class ElecWithObjectAdapter5V :public Electricity
{
public:
    ElecWithObjectAdapter5V() :pAdapter(NULL)
    {
        pAdapter = new Adapter5V();
    }
    virtual void Charge()//��д��緽��
    {
        pAdapter->Transfer();//ͨ��������ָ�룬���õ�ѹת������
    }

private:
    Adapter5V* pAdapter;
};

void ObjectAdapterTest()
{
    Electricity* pEle = new Electricity();//�����ʹ��������
    pEle->Charge();

    Electricity* pEleWithAdapter = new ElecWithObjectAdapter5V();//ʹ��������
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