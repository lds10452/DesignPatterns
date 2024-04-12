#include "BehaviorPatterns.h"
#include <vector>
#include <algorithm>

//请求抽象类
class Request
{
public:
    Request(int iNo) :m_iNo(iNo) {}
    virtual void Execute() = 0;
    int GetID() { return m_iNo; }

protected:
    int m_iNo;//请求ID
};

//审核人
class  Approver
{
public:
    Approver(string strName) :m_strName(strName) {}
    //审核请求，打印信息
    void DealRequest(Request* pRequest)
    {
        cout << "Request " << pRequest->GetID() << " Approved by " << m_strName << endl;
    }
private:
    string m_strName;//审核人的名字
};

//假期请求
class HolidayRequest : public Request
{
public:
    //构造时指定请求ID和审核人
    HolidayRequest(int iNO, Approver* pApprover) :Request(iNO), m_pApprover(pApprover) {}
    //请求被处理
    virtual void Execute()
    {
        m_pApprover->DealRequest(this);
    }
private:
    Approver* m_pApprover;
};

//汇总请求者
class Invoker
{
public:
    //收集请求
    void AddReq(Request* pReq)
    {
        m_vecReq.push_back(pReq);
    }
    //统一申请
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
    //假设有两个经理负责审批，分别叫Mark和Nancy
    Approver* pManagerMark = new Approver("Mark");
    Approver* pManagerNancy = new Approver("Nancy");

    //一个请求收集者
    Invoker* pInvoker = new Invoker();

    pInvoker->AddReq(new HolidayRequest(1, pManagerMark));
    pInvoker->AddReq(new HolidayRequest(2, pManagerMark));
    pInvoker->AddReq(new HolidayRequest(3, pManagerNancy));
    pInvoker->AddReq(new HolidayRequest(4, pManagerNancy));

    //收集所有请求后统一送去审批
    pInvoker->InvokeAllReq();
}