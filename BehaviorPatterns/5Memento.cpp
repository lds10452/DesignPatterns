#include "BehaviorPatterns.h"
#include <vector>

//单条备忘的记录
class Memento
{
public:
    Memento(uint32_t uiLevel, uint32_t uiHp, uint32_t uiAttack)
        :m_uiLevel(uiLevel), m_uiHp(uiHp), m_uiAttack(uiAttack)
    {
    }
public:
    uint32_t m_uiLevel;
    uint32_t m_uiHp;
    uint32_t m_uiAttack;
};

//需要保存的数据类
class GameRole
{
public:
    GameRole(string strName)
        :m_strName(strName)
        , m_uiLevel(1)
        , m_uiHp(100)
        , m_uiAttack(10)
    {
    }

    void Show()
    {
        cout << "Name:" << m_strName << " Level:" << m_uiLevel << " HP:" << m_uiHp << " ATK:" << m_uiAttack << endl;
    }

    Memento* Save()
    {
        Memento* pSaveInfo = new Memento(m_uiLevel, m_uiHp, m_uiAttack);
        return pSaveInfo;
    }

    void Load(Memento* pMem)
    {
        m_uiLevel = pMem->m_uiLevel;
        m_uiHp = pMem->m_uiHp;
        m_uiAttack = pMem->m_uiAttack;
        cout << "Loaded" << endl;
    }

private:
    string m_strName;
public:
    uint32_t m_uiLevel;
    uint32_t m_uiHp;
    uint32_t m_uiAttack;
};

//备忘管理者
class Recorder
{
public:
    void Record(Memento* pMem)
    {
        vecMemento.push_back(pMem);
        cout << "Saved" << endl;
    }
    Memento* Get(uint32_t uiIndex)
    {
        return vecMemento[uiIndex];
    }

private:
    vector<Memento*> vecMemento;
};

void MementoTest()
{
    cout << ".......start MementoTest........" << endl;
    Recorder oRecorder;
    GameRole oPlayer("Mark");
    oPlayer.Show();

    oRecorder.Record(oPlayer.Save());

    oPlayer.m_uiLevel = 100;
    oPlayer.m_uiHp = 1000;
    oPlayer.m_uiAttack = 100;
    oPlayer.Show();

    oPlayer.Load(oRecorder.Get(0));
    oPlayer.Show();
}