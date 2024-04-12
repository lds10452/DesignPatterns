#include "BehaviorPatterns.h"
#include <stack>
#include <map>

//������������
class Expression
{
public:
    //������ʽ����ֵ������mapValue�е�key�ǹ�ʽ�еĲ�����valueֵ�Ǿ����ֵ
    virtual int interpreter(map<string, int>& MapValue) = 0;
    virtual ~Expression() {};
};


//�������������ս����
class VarExpression : public Expression
{
    string m_strkey;
public:
    VarExpression(string strkey) :m_strkey(strkey) {}

    //��map��ȡ��������ֵ
    int interpreter(map<string, int>& MapValue)
    {
        return MapValue[m_strkey];
    }
};

//����������������ս����
class SymbolExpression : public Expression
{
protected:
    Expression* m_pLeft;
    Expression* m_pRight;
public:
    SymbolExpression(Expression* pLeft, Expression* pRight) :m_pLeft(pLeft), m_pRight(pRight) {}
};

//�ӷ�������
class AddExpression : public SymbolExpression
{
public:
    AddExpression(Expression* pLeft, Expression* pRight) :SymbolExpression(pLeft, pRight) {}

    //�����������������
    int interpreter(map<string, int>& MapValue)
    {
        return m_pLeft->interpreter(MapValue) + m_pRight->interpreter(MapValue);
    }
};

//����������
class SubExpression : public SymbolExpression
{
public:
    SubExpression(Expression* pLeft, Expression* pRight) : SymbolExpression(pLeft, pRight)
    {
    }

    //�����������������
    int interpreter(map<string, int>& MapValue)
    {
        return m_pLeft->interpreter(MapValue) - m_pRight->interpreter(MapValue);
    }
};

//���������
class Parse
{
private:
    Expression* m_pExpression;
public:
    //���캯�����Σ����������ʽ�������﷨��
    Parse(string strExpStr)
    {
        m_pExpression = NULL;
        stack<Expression*> stackExp;

        Expression* pLeft = NULL;
        Expression* pRight = NULL;

        for (unsigned int i = 0; i < strExpStr.length(); ++i)
        {
            switch (strExpStr[i])
            {
            case '+':  //�ӷ�
                //1.�ȴ�ջ��ȡ���������
                pLeft = stackExp.top();
                stackExp.pop();

                //2.�ӱ��ʽ��ȡ��+�ź�����Ҳ��������������ս����������
                pRight = new VarExpression(strExpStr.substr(++i, 1));

                //3.�����Ҳ�������ӣ����ѽ������ջ��
                stackExp.push(new AddExpression(pLeft, pRight));

                break;

            case '-':
                //1.�ȴ�ջ��ȡ���������
                pLeft = stackExp.top();
                stackExp.pop();

                //2.�ӱ��ʽ��ȡ��+�ź�����Ҳ��������������ս����������
                pRight = new VarExpression(strExpStr.substr(++i, 1));

                //3.�����Ҳ�������������ѽ������ջ��
                stackExp.push(new SubExpression(pLeft, pRight));

                break;

            default:
                //����Ǳ������ս������
                //��ֱ�����ɶ�Ӧ�ı���������
                stackExp.push(new VarExpression(strExpStr.substr(i, 1)));
            }
        }

        //ջ�б���ľ��������﷨���ĸ���㣨����ΪSuuExpression����
        if (!stackExp.empty())
        {
            m_pExpression = stackExp.top();
            stackExp.pop();
        }
    }

    //��ʼ����
    int Calculate(map<string, int>& MapValue)
    {
        return (!m_pExpression) ? 0 : m_pExpression->interpreter(MapValue);
    }
};

void InterpreterTest()
{
	cout << ".......start InterpreterTest........" << endl;
    string strExpression = "a-b+c";

    map<string, int> MapValue;
    MapValue["a"] = 50;
    MapValue["b"] = 40;
    MapValue["c"] = 30;

    Parse ParseTree(strExpression); //����������

    cout << strExpression << " = " << ParseTree.Calculate(MapValue) << endl;
}