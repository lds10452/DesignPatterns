#include "BehaviorPatterns.h"

/*
 * 约定三种协议
 * MessageAB是AB模块间通信的消息
 * MessageAC是AC模块间通信的消息
 * MessageBC是BC模块间通信的消息
 */
enum Message
{
    MessageAB,
    MessageAC,
    MessageBC,
};

class ModuleBase;
//中介者基类，提供转发接口
class MediatorBase
{
public:
    virtual void Transmit(Message enMessage, ModuleBase* pFrom) = 0;
};

//模块基类，实现向外发消息的方法
class ModuleBase
{
public:
    ModuleBase(MediatorBase* pMediator) :m_pMediator(pMediator) {}
    //模块向外发消息的方法
    void SendMessage(Message enMessage)
    {
        m_pMediator->Transmit(enMessage, this);
    }

    //模块接收消息的接口，由模块自己实现
    virtual void vNotify(Message enMessage) = 0;

protected:
    //每个模块内都有一份负责分发消息的中介者
    MediatorBase* m_pMediator;
};

//模块A
class ModuleA : public ModuleBase
{
public:
    ModuleA(MediatorBase* pMediator) :ModuleBase(pMediator) {}
    virtual void vNotify(Message enMessage)
    {
        switch (enMessage)
        {
        case MessageAB:
            cout << "ModuleA get MessageAB from ModuleB" << endl;
            break;
        case MessageAC:
            cout << "ModuleA get MessageAC from MoudleC" << endl;
            break;
        default:
            break;
        }
    }
};

//模块B
class ModuleB : public ModuleBase
{
public:
    ModuleB(MediatorBase* pMediator) :ModuleBase(pMediator) {}
    virtual void vNotify(Message enMessage)
    {
        switch (enMessage)
        {
        case MessageAB:
            cout << "ModuleB get MessageAB from ModuleA" << endl;
            break;
        case MessageBC:
            cout << "ModuleB get MessageBC form ModuleC" << endl;
            break;
        default:
            break;
        }
    }
};

//模块C
class ModuleC : public ModuleBase
{
public:
    ModuleC(MediatorBase* pMediator) :ModuleBase(pMediator) {}
    virtual void vNotify(Message enMessage)
    {
        switch (enMessage)
        {
        case MessageAC:
            cout << "ModuleC get MessageAC from ModuleA" << endl;
            break;
        case MessageBC:
            cout << "ModuleC get MessageBC form ModuleB" << endl;
            break;
        default:
            break;
        }
    }
};

//中介者实现类
class ConcreteMediator : public MediatorBase
{
public:
    ConcreteMediator() :m_pModA(NULL), m_pModB(NULL), m_pModC(NULL) {}
    void Transmit(Message enMessage, ModuleBase* pFrom)
    {
        switch (enMessage)
        {
        case MessageAB:
        {
            ModuleA* pFromWhere = dynamic_cast<ModuleA*>(pFrom);
            //能通过dynamic_cast转换为不为NULL的指针,可确认指针指向的子类类型
            if (NULL != pFromWhere)
            {
                m_pModB->vNotify(enMessage);
            }
            else
            {
                m_pModA->vNotify(enMessage);
            }
        }
        break;
        case MessageAC:
        {
            ModuleA* pFromWhere = dynamic_cast<ModuleA*>(pFrom);
            if (NULL != pFromWhere)
            {
                m_pModC->vNotify(enMessage);
            }
            else
            {
                m_pModA->vNotify(enMessage);
            }
        }
        case MessageBC:
        {
            ModuleB* pFromWhere = dynamic_cast<ModuleB*>(pFrom);
            if (NULL != pFromWhere)
            {
                m_pModC->vNotify(enMessage);
            }
            else
            {
                m_pModB->vNotify(enMessage);
            }
        }
        }
    }

    void SetModuleA(ModuleBase* pModuleA) { m_pModA = pModuleA; }
    void SetModuleB(ModuleBase* pModuleB) { m_pModB = pModuleB; }
    void SetModuleC(ModuleBase* pModuleC) { m_pModC = pModuleC; }

private:
    ModuleBase* m_pModA;
    ModuleBase* m_pModB;
    ModuleBase* m_pModC;
};

void MediatorTest()
{
    cout << ".......start MediatorTest........" << endl;
    MediatorBase* pMediator = new ConcreteMediator();

    //为所有模块指定中介者
    ModuleBase* pModA = new ModuleA(pMediator);
    ModuleBase* pModB = new ModuleB(pMediator);
    ModuleBase* pModC = new ModuleC(pMediator);

    //为中介者设定模块
    ConcreteMediator* pConcreteMediator = dynamic_cast<ConcreteMediator*>(pMediator);
    pConcreteMediator->SetModuleA(pModA);
    pConcreteMediator->SetModuleB(pModB);
    pConcreteMediator->SetModuleC(pModC);

    //各模块间开始互发消息
    pModA->SendMessage(MessageAC);
    pModB->SendMessage(MessageBC);
    pModC->SendMessage(MessageBC);
}