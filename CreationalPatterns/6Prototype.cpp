#include "CreationalPatterns.h"

//��֭�ĳ�����
class Juice
{
public:
    virtual Juice* Clone() = 0; // ���ڶ������Ϳ���
    virtual void Show() = 0; // ��֤��֭����
};

//������
class OrangeJuice : public Juice
{
public:
    virtual Juice* Clone()
    {
        return new OrangeJuice(*this); // ���ص�ǰ�������͵Ŀ���
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
    Juice* pJuice = new AppleJuice(); // ����ָ��ָ�����������
    pJuice->Show();
    /*
     * ����/�����˺ܾúܾ�֮��
     * �����������˻�����ȷ��
     * �û���ָ����ָ��Ķ����������
     */
    Juice* pNewJuice = pJuice->Clone(); // ��ȡ��������
    pNewJuice->Show();
}