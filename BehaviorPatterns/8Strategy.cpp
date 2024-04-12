#include "BehaviorPatterns.h"

//策略基类
class Strategy
{
public:
    virtual float Calculate(float fTotal) = 0;
};

//策略A，打8折
class StrategyA :public Strategy
{
public:
    virtual float Calculate(float fTotal)
    {
        printf("优惠活动，全部8折\n");
        return fTotal * 0.8;
    }
};

//策略B，打7折
class StrategyB :public Strategy
{
public:
    virtual float Calculate(float fTotal)
    {
        printf("优惠活动，全部7折\n");
        return fTotal * 0.7;
    }
};

//策略C，满300减100
class StrategyC :public Strategy
{
public:
    virtual float Calculate(float fTotal)
    {
        printf("优惠活动，满300减100\n");
        float fFinal = fTotal - static_cast<int>(fTotal / 300) * 100;
        return fFinal;
    }
};

//商场类
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

    //设置商场策略
    void SetStrategy(Strategy* pStrategy)
    {
        if (m_pStrategy)
        {
            delete m_pStrategy;
        }
        m_pStrategy = pStrategy;
    }

    //调用策略类的计算方法计算折后价
    void CalculatePay(float fTotal)
    {
        if (m_pStrategy)
        {
            float fFinal = m_pStrategy->Calculate(fTotal);
            printf("原价:%.2f元, 折后:%.2f元\n", fTotal, fFinal);
        }
        else
        {
            printf("无活动，总价:%.2f元\n", fTotal);
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