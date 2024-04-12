#include "BehaviorPatterns.h"

//自定义的节点
typedef struct Node
{
    int iData;
    struct Node* pNext;
}NODE;

//自定义的某种容器
class MyList
{
public:
    MyList() :m_pHead(NULL), m_pTail(NULL) {}
    //添加元素
    void Add(int iNewData)
    {
        NODE* pNewNode = new Node();
        pNewNode->iData = iNewData;
        pNewNode->pNext = NULL;
        if (NULL == m_pHead)
        {
            m_pHead = pNewNode;
            m_pTail = m_pHead;
        }
        else
        {
            m_pTail->pNext = pNewNode;
            m_pTail = m_pTail->pNext;
        }
    }

    //获取头指针位置
    Node* Begin()
    {
        return m_pHead;
    }

    //获取尾指针位置
    Node* End()
    {
        return m_pTail->pNext;
    }

private:
    NODE* m_pHead;
    NODE* m_pTail;
};

//自定义容器对应的迭代器类
class MyListIterator
{
public:
    MyListIterator(Node* pNode = NULL)
    {
        m_pCurrentNode = pNode;
    }

    Node* operator=(Node* pNode)
    {
        m_pCurrentNode = pNode;
        return m_pCurrentNode;
    }

    int operator*()
    {
        return m_pCurrentNode->iData;
    }

    MyListIterator& operator++()
    {
        m_pCurrentNode = m_pCurrentNode->pNext;
        return *this;
    }

private:
    NODE* m_pCurrentNode;
};

void IteratorTest()
{
    cout << ".......start IteratorTest........" << endl;
    //先向自定义容器中填充数据
    MyList oList;
    oList.Add(1);
    oList.Add(2);

    //访问并输出
    MyListIterator oIterator = oList.Begin();
    cout << *oIterator << endl;
    ++oIterator;
    cout << *oIterator << endl;
}