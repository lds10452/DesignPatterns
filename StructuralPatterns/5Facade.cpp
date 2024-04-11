#include "StructuralPatterns.h"

//语义分析
class CSyntaxParser
{
public:
    static void SyntaxParser()
    {
        cout << "SyntaxParser" << endl;
    }
};
//生成中间代码
class CGenMidCode
{
public:
    static void GenMidCode()
    {
        cout << "GenMidCode" << endl;
    }
};
//生成汇编代码
class CGenAssemblyCode
{
public:
    static void GenAssemblyCode()
    {
        cout << "GenAssemblyCode" << endl;
    }
};
//链接
class CLinkSystem
{
public:
    static void LinkSystem()
    {
        cout << "LinkSystem" << endl;
    }
};
//外观模式
class CFacade
{
public:
    static void Facade()
    {
        CSyntaxParser::SyntaxParser();
        CGenMidCode::GenMidCode();
        CGenAssemblyCode::GenAssemblyCode();
        CLinkSystem::LinkSystem();
    }
};

void FacadeTest()
{
	cout << ".......start FacadeTest........" << endl;
    CFacade::Facade();
}