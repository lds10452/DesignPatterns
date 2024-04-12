#include "BehaviorPatterns.h"
#include <set>

//观察者抽象类
class Observer
{
public:
    virtual void ReceiveMail(string strMessage) = 0;
};

//被观察者抽象类
class Subject
{
public:
    virtual void AddObserver(Observer* pObserver) = 0;
    virtual void DeleteObserver(Observer* pObserver) = 0;
    virtual void SendMail(string strMessage) = 0;
};

//被观察者实现类
class Boss :public Subject
{
public:
    //添加观察者
    void AddObserver(Observer* pObserver)
    {
        setObs.insert(pObserver);
    }

    void DeleteObserver(Observer* pObserver)
    {
        setObs.erase(pObserver);
    }

    //通知所有观察者
    void SendMail(string strMessage)
    {
        for (auto iter = setObs.begin(); iter != setObs.end(); ++iter)
        {
            (*iter)->ReceiveMail(strMessage);
        }
    }

private:
    //存放观察者的容器
    set<Observer*> setObs;
};

//观察者实现类
class Staff :public Observer
{
public:
    Staff(string strName) :m_strName(strName) {}

    //收到通知，取邮件并显示
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