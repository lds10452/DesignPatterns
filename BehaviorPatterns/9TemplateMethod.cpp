#include "BehaviorPatterns.h"

//默认的模板方法类
class DefaultTemplate
{
public:
    //固定的模板方法流程
    void TemplateMethod()
    {
        Step1();
        Step2();
        Step3();
    }

private:
    virtual void Step1()
    {
        cout << "Default Step1" << endl;
    }
    virtual void Step2()
    {
        cout << "Default Step2" << endl;
    }
    virtual void Step3()
    {
        cout << "Default Step3" << endl;
    }
};

//重写步骤1、3
class NewTemplate :public DefaultTemplate
{
private:
    virtual void Step1()
    {
        cout << "New Step1" << endl;
    }
    virtual void Step3()
    {
        cout << "New Step3" << endl;
    }
};

void TemplateMethodTest()
{
	cout << ".......start TemplateMethodTest........" << endl;
    DefaultTemplate oDefault;
    oDefault.TemplateMethod();

    NewTemplate oNew;
    oNew.TemplateMethod();
}