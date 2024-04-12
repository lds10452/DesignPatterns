#include "BehaviorPatterns.h"

class Clock;
//Ê±ÖÓµÄ×´Ì¬ÊôÐÔ
class StateForClock
{
public:
    virtual void Show(Clock* pClock) = 0;
};

//Ê±ÖÓÀà
class Clock
{
public:
    Clock() : m_pState(NULL) {}
    ~Clock()
    {
        if (m_pState)
        {
            delete m_pState;
            m_pState = NULL;
        }
    }

    void SetState(StateForClock* pState)
    {
        if (!m_pState)
        {
            delete m_pState;
        }
        m_pState = pState;
    }

    void Show()
    {
        m_pState->Show(this);
    }

private:
    StateForClock* m_pState;
};


//ÎçÒ¹×´Ì¬
class MidNightState :public StateForClock
{
public:
    virtual void Show(Clock* pClock)
    {
        cout << "MidNight Mode" << endl;
    }
};

//ÉÏÎç×´Ì¬
class NoonState :public StateForClock
{
public:
    virtual void Show(Clock* pClock)
    {
        cout << "Noon Mode" << endl;
    }
};

//ÏÂÎç×´Ì¬
class AfterNoonState :public StateForClock
{
public:
    virtual void Show(Clock* pClock)
    {
        cout << "AfterNoon Mode" << endl;
    }
};

//ÍíÉÏ×´Ì¬
class NightState :public StateForClock
{
public:
    virtual void Show(Clock* pClock)
    {
        cout << "Night Mode" << endl;
    }
};

void StateTest()
{
	cout << ".......start StateTest........" << endl;
    Clock oClock;
    oClock.SetState(new NoonState());
    oClock.Show();

    oClock.SetState(new AfterNoonState());
    oClock.Show();

    oClock.SetState(new MidNightState());
    oClock.Show();
}