#include "StructuralPatterns.h"

class Proxy_Ptr
{
public:
    //构造，代理指针并开始计数
    Proxy_Ptr(int* p) :m_pData(p), m_pCnt(NULL)
    {
        m_pCnt = new int(1);
    }
    //拷贝构造，引用计数+1
    Proxy_Ptr(Proxy_Ptr& rhs) :m_pData(rhs.m_pData), m_pCnt(rhs.m_pCnt)
    {
        ++(*m_pCnt);
    }
    //赋值，原引用计数-1，新引用计数+1
    Proxy_Ptr& operator=(Proxy_Ptr& rhs)
    {
        if (m_pData == rhs.m_pData)
        {
            return *this;
        }
        if (NULL != m_pCnt)
        {
            --(*m_pCnt);
            if (0 == *m_pCnt)
            {
                cout << "delete " << *m_pData << endl;
                delete m_pData;
                m_pData = NULL;
            }
            m_pData = rhs.m_pData;
            m_pCnt = rhs.m_pCnt;
            ++(*m_pCnt);
        }
        return *this;
    }
    //析构，引用计数-1，计数为0时释放内存
    ~Proxy_Ptr()
    {
        --(*m_pCnt);
        if (0 == *m_pCnt)
        {
            cout << "delete " << *m_pData << endl;
            delete m_pData;
            m_pData = NULL;
        }
    }

    int operator*()
    {
        return *m_pData;
    }

    void Show()
    {
        cout << "Data: " << *m_pData << " Count: " << *m_pCnt << endl;
    }
private:
    int* m_pData;//被代理的对象
    int* m_pCnt;//引用计数
};

void ProxyTest()
{
	cout << ".......start ProxyTest........" << endl;
    Proxy_Ptr p(new int(6));
    Proxy_Ptr p2(new int(10));

    p = p2;
    cout << "-----no pointer to 6-----" << endl;

    cout << "p->m_pData:" << *p << endl;
    p2.Show();

    cout << "-----begin destruction-----" << endl;
}