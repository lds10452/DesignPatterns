#include "BehaviorPatterns.h"

//�Զ���Ľڵ�
typedef struct Node
{
    int iData;
    struct Node* pNext;
}NODE;

//�Զ����ĳ������
class MyList
{
public:
    MyList() :m_pHead(NULL), m_pTail(NULL) {}
    //���Ԫ��
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

    //��ȡͷָ��λ��
    Node* Begin()
    {
        return m_pHead;
    }

    //��ȡβָ��λ��
    Node* End()
    {
        return m_pTail->pNext;
    }

private:
    NODE* m_pHead;
    NODE* m_pTail;
};

//�Զ���������Ӧ�ĵ�������
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
    //�����Զ����������������
    MyList oList;
    oList.Add(1);
    oList.Add(2);

    //���ʲ����
    MyListIterator oIterator = oList.Begin();
    cout << *oIterator << endl;
    ++oIterator;
    cout << *oIterator << endl;
}