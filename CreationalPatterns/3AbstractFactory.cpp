#include "CreationalPatterns.h"

// ��ƷA������
class Desk {
public:
    virtual void Show() = 0;
};

// ��ƷB������
class Chair {
public:
    virtual void Show() = 0;
};

class WoodDesk : public Desk {
public:
    void Show() {
        cout << "WoodDesk" << endl;
    }
};

class IronDesk : public Desk {
public:
    void Show() {
        cout << "IronDesk" << endl;
    }
};

class WoodChair : public Chair {
public:
    void Show() {
        cout << "WoodChair" << endl;
    }
};

class IronChair : public Chair {
public:
    void Show() {
        cout << "IronChair" << endl;
    }
};

// ����������
class Factory {
public:
    virtual Desk* CreateDesk() = 0;
    virtual Chair* CreateChair() = 0;
};

// ����ľ�ʲ�Ʒ�Ĺ���
class WoodFactory : public Factory {
public:
    Desk* CreateDesk() {
        return new WoodDesk();
    }

    Chair* CreateChair() {
        return new WoodChair();
    }
};

// �������ʲ�Ʒ�Ĺ���
class IronFactory : public Factory {
public:
    Desk* CreateDesk() {
        return new IronDesk();
    }

    Chair* CreateChair() {
        return new IronChair();
    }
};
void AbstractFactoryTest() {
    cout << ".......start AbstractFactoryTest........" << endl;
    Factory* FactoryWood = new WoodFactory();
    // ľ��������ľ��
    Desk* DeskWood = FactoryWood->CreateDesk();
    DeskWood->Show();

    Factory* FactoryIron = new IronFactory();
    // ��������������
    Chair* ChairIron = FactoryIron->CreateChair();
    ChairIron->Show();

    if (NULL != FactoryWood) {
        delete FactoryWood;
        FactoryWood = NULL;
    }
    if (NULL != FactoryIron) {
        delete FactoryIron;
        FactoryIron = NULL;
    }
}