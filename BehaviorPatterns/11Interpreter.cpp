#include "BehaviorPatterns.h"
#include <stack>
#include <map>

//解释器抽象类
class Expression
{
public:
    //解析公式和数值，其中mapValue中的key是公式中的参数，value值是具体的值
    virtual int interpreter(map<string, int>& MapValue) = 0;
    virtual ~Expression() {};
};


//变量解析器（终结符）
class VarExpression : public Expression
{
    string m_strkey;
public:
    VarExpression(string strkey) :m_strkey(strkey) {}

    //从map中取出变量的值
    int interpreter(map<string, int>& MapValue)
    {
        return MapValue[m_strkey];
    }
};

//运算符解析器（非终结符）
class SymbolExpression : public Expression
{
protected:
    Expression* m_pLeft;
    Expression* m_pRight;
public:
    SymbolExpression(Expression* pLeft, Expression* pRight) :m_pLeft(pLeft), m_pRight(pRight) {}
};

//加法解析器
class AddExpression : public SymbolExpression
{
public:
    AddExpression(Expression* pLeft, Expression* pRight) :SymbolExpression(pLeft, pRight) {}

    //把左右两个变量相加
    int interpreter(map<string, int>& MapValue)
    {
        return m_pLeft->interpreter(MapValue) + m_pRight->interpreter(MapValue);
    }
};

//减法解析器
class SubExpression : public SymbolExpression
{
public:
    SubExpression(Expression* pLeft, Expression* pRight) : SymbolExpression(pLeft, pRight)
    {
    }

    //把左右两个变量相减
    int interpreter(map<string, int>& MapValue)
    {
        return m_pLeft->interpreter(MapValue) - m_pRight->interpreter(MapValue);
    }
};

//语义解析器
class Parse
{
private:
    Expression* m_pExpression;
public:
    //构造函数传参，并解析表达式，构建语法树
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
            case '+':  //加法
                //1.先从栈中取出左操作数
                pLeft = stackExp.top();
                stackExp.pop();

                //2.从表达式中取出+号后面的右操作数，并生成终结符解析对象
                pRight = new VarExpression(strExpStr.substr(++i, 1));

                //3.将左右操作数相加，并把结果放入栈中
                stackExp.push(new AddExpression(pLeft, pRight));

                break;

            case '-':
                //1.先从栈中取出左操作数
                pLeft = stackExp.top();
                stackExp.pop();

                //2.从表达式中取出+号后面的右操作数，并生成终结符解析对象
                pRight = new VarExpression(strExpStr.substr(++i, 1));

                //3.将左右操作数相减，并把结果放入栈中
                stackExp.push(new SubExpression(pLeft, pRight));

                break;

            default:
                //如果是变量（终结符），
                //则直接生成对应的变量解析器
                stackExp.push(new VarExpression(strExpStr.substr(i, 1)));
            }
        }

        //栈中保存的就是最终语法树的根结点（本例为SuuExpression对象）
        if (!stackExp.empty())
        {
            m_pExpression = stackExp.top();
            stackExp.pop();
        }
    }

    //开始运算
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

    Parse ParseTree(strExpression); //生成语义树

    cout << strExpression << " = " << ParseTree.Calculate(MapValue) << endl;
}