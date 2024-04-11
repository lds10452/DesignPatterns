#include "StructuralPatterns.h"
#include <list>
//部门抽象类
class Department
{
public:
    //构造，传入部门名称作为部门标记
    Department(string strName) :m_strName(strName) {}
    //内存管理，析构时析构所有下属部门
    virtual ~Department()
    {
        cout << m_strName << "部门解散" << endl;
        //下属部门析构
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
    //获取部门名称的方法
    string GetName()
    {
        return m_strName;
    }
    //展示所有下属部门名称
    virtual void ShowSubDep()
    {
        cout << m_strName << "部门下属部门：";
        list<Department*>::iterator Iter = m_listDep.begin();
        for (; Iter != m_listDep.end(); ++Iter)
        {
            cout << " " << (*Iter)->GetName();
        }
        cout << endl;
    }
    //添加下属部门并打印信息
    void AddDepartment(Department* pDep)
    {
        m_listDep.push_back(pDep);
        cout << m_strName << "部门增加了下属的" << pDep->GetName() << "部门" << endl;
    }
    //删除下属部门并打印信息
    void DelDepartment(Department* pDep)
    {
        list<Department*>::iterator Iter = m_listDep.begin();
        for (; Iter != m_listDep.end(); ++Iter)
        {
            if (pDep == (*Iter))
            {
                cout << m_strName << "部门删除了下属的" << pDep->GetName() << "部门" << endl;
                delete (*Iter);
                m_listDep.erase(Iter);
                break;
            }
        }
    }

private:
    string m_strName;//部门名称
    list<Department*> m_listDep;//存放下属部门的列表，用列表为了方便增删
};

//一级部门
class FirstLevelDepartment :public Department
{
public:
    FirstLevelDepartment(string strName) :Department(strName) {}
    virtual ~FirstLevelDepartment() {}
};

//二级部门
class SecondLevelDepartment :public Department
{
public:
    SecondLevelDepartment(string strName) :Department(strName) {}
    virtual ~SecondLevelDepartment() {}
};

//三级部门
class ThirdLevelDepartment :public Department
{
public:
    ThirdLevelDepartment(string strName) :Department(strName) {}
    virtual ~ThirdLevelDepartment() {}
};

void CompositeTest()
{
    cout << ".......start CompositeTest........" << endl;
    //1级部门A1
    Department* pFstLvA = new FirstLevelDepartment("A1");
    //2级部门B2、C2、D2
    Department* pSndLvB = new SecondLevelDepartment("B2");
    Department* pSndLvC = new SecondLevelDepartment("C2");
    Department* pSndLvD = new SecondLevelDepartment("D2");
    //3级部门E3、F3、G3、H3
    Department* PTrdLvE = new ThirdLevelDepartment("E3");
    Department* PTrdLvF = new ThirdLevelDepartment("F3");
    Department* PTrdLvG = new ThirdLevelDepartment("G3");
    Department* PTrdLvH = new ThirdLevelDepartment("H3");
    //组建树形结构
    cout << "=======组建部门结构=======" << endl;
    pFstLvA->AddDepartment(pSndLvB);
    pFstLvA->AddDepartment(pSndLvC);
    pFstLvA->AddDepartment(pSndLvD);
    pSndLvB->AddDepartment(PTrdLvE);
    pSndLvB->AddDepartment(PTrdLvF);
    pSndLvC->AddDepartment(PTrdLvG);
    pSndLvD->AddDepartment(PTrdLvH);
    //展示一级部门A所有子部门
    cout << "========展示子部门========" << endl;
    pFstLvA->ShowSubDep();
    //删除A下属二级部门B
    cout << "========解散子部门========" << endl;
    pFstLvA->DelDepartment(pSndLvB);
    //析构，资源回收
    cout << "=========开始析构=========" << endl;
    delete pFstLvA;
}