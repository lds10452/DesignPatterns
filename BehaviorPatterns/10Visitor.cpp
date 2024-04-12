#include "BehaviorPatterns.h"
#include <list>

class Visitor;

//���Computer�ĸ��������
class Element
{
public:
    Element(string strName) :m_strName(strName) {}
    string GetName()
    {
        return m_strName;
    }

    //������ܷ����߷��ʵĽӿ�
    virtual void AcceptVisitor(Visitor* pVisitor) = 0;

private:
    //����ı�ʶ����
    string m_strName;
};

//�����߻��࣬��Բ�ͬ������ṩ��ͬ�ķ��ʽӿ�
class Visitor
{
public:
    virtual void VisitCPU(Element* pEle) = 0;
    virtual void VisitGPU(Element* pEle) = 0;
    virtual void VisitDISK(Element* pEle) = 0;
};

//Computer�࣬�ɸ������ɣ������߷���Computerʱ�����η��ʸ����
class Computer
{
public:
    ~Computer()
    {
        for (Element* pElement : m_listEle)
        {
            delete pElement;
        }
    }

    void AddElement(Element* pEle)
    {
        m_listEle.push_back(pEle);
    }

    void DelElement(Element* pEle)
    {
        m_listEle.remove(pEle);
    }

    //�����߷���Computerʱ�����η��ʸ����
    void AcceptVisitor(Visitor* pVisitor)
    {
        for (Element* pElement : m_listEle)
        {
            pElement->AcceptVisitor(pVisitor);
        }
    }

private:
    list<Element*> m_listEle;
};

//������ʵ���࣬ʵ�ָ��Եķ��ʷ���
class VisitorA : public Visitor
{
public:
    void VisitCPU(Element* pEle)
    {
        printf("Visitor A record CPU's name:%s\n", pEle->GetName().c_str());
    }

    void VisitGPU(Element* pEle)
    {
        printf("Visitor A do nothing to GPU:%s\n", pEle->GetName().c_str());
    }

    void VisitDISK(Element* pEle)
    {
        printf("Visitor A change DISK:%s\n", pEle->GetName().c_str());
    }
};

class VisitorB : public Visitor
{
public:
    void VisitCPU(Element* pEle)
    {
        printf("Visitor B do nothing to CPU:%s\n", pEle->GetName().c_str());
    }

    void VisitGPU(Element* pEle)
    {
        printf("Visitor B record GPU's name:%s\n", pEle->GetName().c_str());
    }

    void VisitDISK(Element* pEle)
    {
        printf("Visitor B do nothing to DISK:%s\n", pEle->GetName().c_str());
    }
};

//�����ʵ���࣬���÷�������Ӧ�ķ��ʷ���
class CPU :public Element
{
public:
    CPU(string strName) :Element(strName) {}
    void AcceptVisitor(Visitor* pVisitor)
    {
        pVisitor->VisitCPU(this);
    }
};

class GPU :public Element
{
public:
    GPU(string strName) :Element(strName) {}
    void AcceptVisitor(Visitor* pVisitor)
    {
        pVisitor->VisitGPU(this);
    }
};

class Disk :public Element
{
public:
    Disk(string strName) :Element(strName) {}
    void AcceptVisitor(Visitor* pVisitor)
    {
        pVisitor->VisitDISK(this);
    }
};

void VisitorTest()
{
	cout << ".......start VisitorTest........" << endl;
    Computer oComputer;
    oComputer.AddElement(new CPU("i9-10980XE"));
    oComputer.AddElement(new GPU("Titan RTX"));
    oComputer.AddElement(new Disk("HOF PRO M.2"));

    VisitorA oVisitorA;
    VisitorB oVisitorB;

    oComputer.AcceptVisitor(&oVisitorA);
    oComputer.AcceptVisitor(&oVisitorB);
}