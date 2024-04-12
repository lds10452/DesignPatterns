#include "BehaviorPatterns.h"
#include <set>

//�۲��߳�����
class Observer
{
public:
    virtual void ReceiveMail(string strMessage) = 0;
};

//���۲��߳�����
class Subject
{
public:
    virtual void AddObserver(Observer* pObserver) = 0;
    virtual void DeleteObserver(Observer* pObserver) = 0;
    virtual void SendMail(string strMessage) = 0;
};

//���۲���ʵ����
class Boss :public Subject
{
public:
    //��ӹ۲���
    void AddObserver(Observer* pObserver)
    {
        setObs.insert(pObserver);
    }

    void DeleteObserver(Observer* pObserver)
    {
        setObs.erase(pObserver);
    }

    //֪ͨ���й۲���
    void SendMail(string strMessage)
    {
        for (auto iter = setObs.begin(); iter != setObs.end(); ++iter)
        {
            (*iter)->ReceiveMail(strMessage);
        }
    }

private:
    //��Ź۲��ߵ�����
    set<Observer*> setObs;
};

//�۲���ʵ����
class Staff :public Observer
{
public:
    Staff(string strName) :m_strName(strName) {}

    //�յ�֪ͨ��ȡ�ʼ�����ʾ
    void ReceiveMail(string strMessage)
    {
        cout << "Staff " << m_strName << " Receive Mail:" << strMessage << endl;
    }

private:
    string m_strName;
};

void ObserverTest()
{
	cout << ".......start ObserverTest........" << endl;
    Subject* pBoss = new Boss();

    Observer* pStaffA = new Staff("Mark");
    pBoss->AddObserver(pStaffA);
    Observer* pStaffB = new Staff("Jeremy");
    pBoss->AddObserver(pStaffB);

    pBoss->SendMail("test");
}