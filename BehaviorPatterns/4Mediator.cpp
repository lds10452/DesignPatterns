#include "BehaviorPatterns.h"

/*
 * Լ������Э��
 * MessageAB��ABģ���ͨ�ŵ���Ϣ
 * MessageAC��ACģ���ͨ�ŵ���Ϣ
 * MessageBC��BCģ���ͨ�ŵ���Ϣ
 */
enum Message
{
    MessageAB,
    MessageAC,
    MessageBC,
};

class ModuleBase;
//�н��߻��࣬�ṩת���ӿ�
class MediatorBase
{
public:
    virtual void Transmit(Message enMessage, ModuleBase* pFrom) = 0;
};

//ģ����࣬ʵ�����ⷢ��Ϣ�ķ���
class ModuleBase
{
public:
    ModuleBase(MediatorBase* pMediator) :m_pMediator(pMediator) {}
    //ģ�����ⷢ��Ϣ�ķ���
    void SendMessage(Message enMessage)
    {
        m_pMediator->Transmit(enMessage, this);
    }

    //ģ�������Ϣ�Ľӿڣ���ģ���Լ�ʵ��
    virtual void vNotify(Message enMessage) = 0;

protected:
    //ÿ��ģ���ڶ���һ�ݸ���ַ���Ϣ���н���
    MediatorBase* m_pMediator;
};

//ģ��A
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

//ģ��B
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

//ģ��C
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

//�н���ʵ����
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
            //��ͨ��dynamic_castת��Ϊ��ΪNULL��ָ��,��ȷ��ָ��ָ�����������
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

    //Ϊ����ģ��ָ���н���
    ModuleBase* pModA = new ModuleA(pMediator);
    ModuleBase* pModB = new ModuleB(pMediator);
    ModuleBase* pModC = new ModuleC(pMediator);

    //Ϊ�н����趨ģ��
    ConcreteMediator* pConcreteMediator = dynamic_cast<ConcreteMediator*>(pMediator);
    pConcreteMediator->SetModuleA(pModA);
    pConcreteMediator->SetModuleB(pModB);
    pConcreteMediator->SetModuleC(pModC);

    //��ģ��俪ʼ������Ϣ
    pModA->SendMessage(MessageAC);
    pModB->SendMessage(MessageBC);
    pModC->SendMessage(MessageBC);
}