#include "BehaviorPatterns.h"

//����������
class HolidayRequest
{
public:
    HolidayRequest(int iHour) :m_iHour(iHour) {}
    int GetHour() { return m_iHour; }

private:
    int m_iHour;//����ļ���ʱ��
};

//�����߳�����
class  Approver
{
public:
    virtual bool DealRequest(HolidayRequest*) = 0;
};

//һ�������ߣ�������24Сʱ���¼�������
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

//���������ߣ�������48Сʱ���¼�������
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

//һ�������ߣ�����48Сʱ���ϼ�������
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