#include "StructuralPatterns.h"
#include <map>

//棋子坐标
struct POINT
{
    int m_ix;
    int m_iy;
};
//棋子类
class CPieces
{
public:
    CPieces(string strColor) :m_strColor(strColor) {}
    //设置棋子坐标的方法
    void SetPosition(int ix, int iy)
    {
        m_stPosition.m_ix = ix;
        m_stPosition.m_iy = iy;
    }
    //将棋子按照属性描画在棋盘上
    void Draw()
    {
        cout << "Draw a " << m_strColor << " piece, at position " << m_stPosition.m_ix << "-" << m_stPosition.m_iy << endl;
    }
private:
    string m_strColor;
    POINT m_stPosition;
};
//棋子工厂类
class CPiecesFactory
{
public:
    CPieces* GetPiece(string strColor)
    {
        if (NULL == mapPieces[strColor])//如果map中原来没有
        {
            CPieces* pNewPieces = new CPieces(strColor);
            cout << "Create a new " << strColor << " Piece " << endl;
            mapPieces[strColor] = pNewPieces;
        }
        return mapPieces[strColor];
    }
private:
    map<string, CPieces*> mapPieces;//按照棋子颜色属性作为键值
};

void FlyweightTest()
{
	cout << ".......start FlyweightTest........" << endl;
    CPiecesFactory* pFactory = new CPiecesFactory();

    cout << "-----Round 1-----" << endl;
    CPieces* pPieceA = pFactory->GetPiece("White");
    pPieceA->SetPosition(1, 2);
    pPieceA->Draw();

    cout << "-----Round 2-----" << endl;
    CPieces* pPieceB = pFactory->GetPiece("Black");
    pPieceB->SetPosition(3, 4);
    pPieceB->Draw();

    cout << "-----Round 3-----" << endl;
    CPieces* pPieceC = pFactory->GetPiece("White");
    pPieceC->SetPosition(5, 6);
    pPieceC->Draw();

    cout << "-----Round 4-----" << endl;
    CPieces* pPieceD = pFactory->GetPiece("Black");
    pPieceD->SetPosition(7, 8);
    pPieceD->Draw();
}