#include "StructuralPatterns.h"
#include <list>
//���ų�����
class Department
{
public:
    //���죬���벿��������Ϊ���ű��
    Department(string strName) :m_strName(strName) {}
    //�ڴ��������ʱ����������������
    virtual ~Department()
    {
        cout << m_strName << "���Ž�ɢ" << endl;
        //������������
        list<Department*>::iterator Iter = m_listDep.begin();
        for (; Iter != m_listDep.end(); ++Iter)
        {
            if (NULL != (*Iter))
            {
                delete (*Iter);
                (*Iter) = NULL;
            }
        }
    }
    //��ȡ�������Ƶķ���
    string GetName()
    {
        return m_strName;
    }
    //չʾ����������������
    virtual void ShowSubDep()
    {
        cout << m_strName << "�����������ţ�";
        list<Department*>::iterator Iter = m_listDep.begin();
        for (; Iter != m_listDep.end(); ++Iter)
        {
            cout << " " << (*Iter)->GetName();
        }
        cout << endl;
    }
    //����������Ų���ӡ��Ϣ
    void AddDepartment(Department* pDep)
    {
        m_listDep.push_back(pDep);
        cout << m_strName << "����������������" << pDep->GetName() << "����" << endl;
    }
    //ɾ���������Ų���ӡ��Ϣ
    void DelDepartment(Department* pDep)
    {
        list<Department*>::iterator Iter = m_listDep.begin();
        for (; Iter != m_listDep.end(); ++Iter)
        {
            if (pDep == (*Iter))
            {
                cout << m_strName << "����ɾ����������" << pDep->GetName() << "����" << endl;
                delete (*Iter);
                m_listDep.erase(Iter);
                break;
            }
        }
    }

private:
    string m_strName;//��������
    list<Department*> m_listDep;//����������ŵ��б����б�Ϊ�˷�����ɾ
};

//һ������
class FirstLevelDepartment :public Department
{
public:
    FirstLevelDepartment(string strName) :Department(strName) {}
    virtual ~FirstLevelDepartment() {}
};

//��������
class SecondLevelDepartment :public Department
{
public:
    SecondLevelDepartment(string strName) :Department(strName) {}
    virtual ~SecondLevelDepartment() {}
};

//��������
class ThirdLevelDepartment :public Department
{
public:
    ThirdLevelDepartment(string strName) :Department(strName) {}
    virtual ~ThirdLevelDepartment() {}
};

void CompositeTest()
{
    cout << ".......start CompositeTest........" << endl;
    //1������A1
    Department* pFstLvA = new FirstLevelDepartment("A1");
    //2������B2��C2��D2
    Department* pSndLvB = new SecondLevelDepartment("B2");
    Department* pSndLvC = new SecondLevelDepartment("C2");
    Department* pSndLvD = new SecondLevelDepartment("D2");
    //3������E3��F3��G3��H3
    Department* PTrdLvE = new ThirdLevelDepartment("E3");
    Department* PTrdLvF = new ThirdLevelDepartment("F3");
    Department* PTrdLvG = new ThirdLevelDepartment("G3");
    Department* PTrdLvH = new ThirdLevelDepartment("H3");
    //�齨���νṹ
    cout << "=======�齨���Žṹ=======" << endl;
    pFstLvA->AddDepartment(pSndLvB);
    pFstLvA->AddDepartment(pSndLvC);
    pFstLvA->AddDepartment(pSndLvD);
    pSndLvB->AddDepartment(PTrdLvE);
    pSndLvB->AddDepartment(PTrdLvF);
    pSndLvC->AddDepartment(PTrdLvG);
    pSndLvD->AddDepartment(PTrdLvH);
    //չʾһ������A�����Ӳ���
    cout << "========չʾ�Ӳ���========" << endl;
    pFstLvA->ShowSubDep();
    //ɾ��A������������B
    cout << "========��ɢ�Ӳ���========" << endl;
    pFstLvA->DelDepartment(pSndLvB);
    //��������Դ����
    cout << "=========��ʼ����=========" << endl;
    delete pFstLvA;
}