#include "BehaviorPatterns.h"

//假期请求类
class HolidayRequest
{
public:
    HolidayRequest(int iHour) :m_iHour(iHour) {}
    int GetHour() { return m_iHour; }

private:
    int m_iHour;//请求的假期时间
};

//审批者抽象类
class  Approver
{
public:
    virtual bool DealRequest(HolidayRequest*) = 0;
};

//一级审批者，可审批24小时以下假期申请
class FirstLevelApprover : public Approver
{
public:
    FirstLevelApprover(Approver* pApprover) :m_pApprover(pApprover) {}

    virtual bool DealRequest(HolidayRequest* pReq)
    {
        if (pReq->GetHour() < 24)
        {
            cout << "First Level Approved" << endl;
            return true;
        }
        return m_pApprover->DealRequest(pReq);
    }
private:
    Approver* m_pApprover;
};

//二级审批者，可审批48小时以下假期申请
class SecondLevelApprover : public Approver
{
public:
    SecondLevelApprover(Approver* pApprover) :m_pApprover(pApprover) {}

    virtual bool DealRequest(HolidayRequest* pReq)
    {
        if (pReq->GetHour() < 48)
        {
            cout << "Second Level Approved" << endl;
            return true;
        }
        return m_pApprover->DealRequest(pReq);
    }
private:
    Approver* m_pApprover;
};

//一级审批者，审批48小时以上假期申请
class ThirdLevelApprover : public Approver
{
public:
    virtual bool DealRequest(HolidayRequest* pReq)
    {
        cout << "Third Level Approved" << endl;
        return true;
    }
};

void ChainOfResponsibilityTest()
{
	cout << ".......start ChainOfResponsibilityTest........" << endl;
    ThirdLevelApprover* pThird = new ThirdLevelApprover();
    SecondLevelApprover* pSecond = new SecondLevelApprover(pThird);
    FirstLevelApprover* pFirst = new FirstLevelApprover(pSecond);

    cout << "=====18-Hours Request=====" << endl;
    HolidayRequest* pReq1 = new HolidayRequest(18);
    pFirst->DealRequest(pReq1);

    cout << "=====36-Hours Request=====" << endl;
    HolidayRequest* pReq2 = new HolidayRequest(36);
    pFirst->DealRequest(pReq2);

    cout << "=====72-Hours Request=====" << endl;
    HolidayRequest* pReq3 = new HolidayRequest(72);
    pFirst->DealRequest(pReq3);
}