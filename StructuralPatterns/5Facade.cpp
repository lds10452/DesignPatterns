#include "StructuralPatterns.h"

//�������
class CSyntaxParser
{
public:
    static void SyntaxParser()
    {
        cout << "SyntaxParser" << endl;
    }
};
//�����м����
class CGenMidCode
{
public:
    static void GenMidCode()
    {
        cout << "GenMidCode" << endl;
    }
};
//���ɻ�����
class CGenAssemblyCode
{
public:
    static void GenAssemblyCode()
    {
        cout << "GenAssemblyCode" << endl;
    }
};
//����
class CLinkSystem
{
public:
    static void LinkSystem()
    {
        cout << "LinkSystem" << endl;
    }
};
//���ģʽ
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