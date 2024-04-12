#include "BehaviorPatterns.h"

//���Ի���
class Strategy
{
public:
    virtual float Calculate(float fTotal) = 0;
};

//����A����8��
class StrategyA :public Strategy
{
public:
    virtual float Calculate(float fTotal)
    {
        printf("�Żݻ��ȫ��8��\n");
        return fTotal * 0.8;
    }
};

//����B����7��
class StrategyB :public Strategy
{
public:
    virtual float Calculate(float fTotal)
    {
        printf("�Żݻ��ȫ��7��\n");
        return fTotal * 0.7;
    }
};

//����C����300��100
class StrategyC :public Strategy
{
public:
    virtual float Calculate(float fTotal)
    {
        printf("�Żݻ����300��100\n");
        float fFinal = fTotal - static_cast<int>(fTotal / 300) * 100;
        return fFinal;
    }
};

//�̳���
class Shop
{
public:
    Shop(Strategy* pStrategy = NULL) :m_pStrategy(pStrategy) {}
    ~Shop()
    {
        if (m_pStrategy)
        {
            delete m_pStrategy;
            m_pStrategy = NULL;
        }
    }

    //�����̳�����
    void SetStrategy(Strategy* pStrategy)
    {
        if (m_pStrategy)
        {
            delete m_pStrategy;
        }
        m_pStrategy = pStrategy;
    }

    //���ò�����ļ��㷽�������ۺ��
    void CalculatePay(float fTotal)
    {
        if (m_pStrategy)
        {
            float fFinal = m_pStrategy->Calculate(fTotal);
            printf("ԭ��:%.2fԪ, �ۺ�:%.2fԪ\n", fTotal, fFinal);
        }
        else
        {
            printf("�޻���ܼ�:%.2fԪ\n", fTotal);
        }
    }

private:
    Strategy* m_pStrategy;
};

void StrategyTest()
{
	cout << ".......start StrategyTest........" << endl;
    Shop oShop;
    oShop.CalculatePay(400);

    oShop.SetStrategy(new StrategyA());
    oShop.CalculatePay(400);

    oShop.SetStrategy(new StrategyB());
    oShop.CalculatePay(400);

    oShop.SetStrategy(new StrategyC());
    oShop.CalculatePay(400);
}