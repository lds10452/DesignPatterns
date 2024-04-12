#include "BehaviorPatterns.h"
#include <vector>
#include <algorithm>

//���������
class Request
{
public:
    Request(int iNo) :m_iNo(iNo) {}
    virtual void Execute() = 0;
    int GetID() { return m_iNo; }

protected:
    int m_iNo;//����ID
};

//�����
class  Approver
{
public:
    Approver(string strName) :m_strName(strName) {}
    //������󣬴�ӡ��Ϣ
    void DealRequest(Request* pRequest)
    {
        cout << "Request " << pRequest->GetID() << " Approved by " << m_strName << endl;
    }
private:
    string m_strName;//����˵�����
};

//��������
class HolidayRequest : public Request
{
public:
    //����ʱָ������ID�������
    HolidayRequest(int iNO, Approver* pApprover) :Request(iNO), m_pApprover(pApprover) {}
    //���󱻴���
    virtual void Execute()
    {
        m_pApprover->DealRequest(this);
    }
private:
    Approver* m_pApprover;
};

//����������
class Invoker
{
public:
    //�ռ�����
    void AddReq(Request* pReq)
    {
        m_vecReq.push_back(pReq);
    }
    //ͳһ����
    void InvokeAllReq()
    {
        for_each(m_vecReq.begin(), m_vecReq.end(), Invoke);
    }
private:
    static void Invoke(Request* pReq)
    {
        if (pReq)
        {
            pReq->Execute();
        }
    }
    vector<Request*> m_vecReq;
};

void CommandTest()
{
    cout << ".......start CommandTest........" << endl;
    //�����������������������ֱ��Mark��Nancy
    Approver* pManagerMark = new Approver("Mark");
    Approver* pManagerNancy = new Approver("Nancy");

    //һ�������ռ���
    Invoker* pInvoker = new Invoker();

    pInvoker->AddReq(new HolidayRequest(1, pManagerMark));
    pInvoker->AddReq(new HolidayRequest(2, pManagerMark));
    pInvoker->AddReq(new HolidayRequest(3, pManagerNancy));
    pInvoker->AddReq(new HolidayRequest(4, pManagerNancy));

    //�ռ����������ͳһ��ȥ����
    pInvoker->InvokeAllReq();
}