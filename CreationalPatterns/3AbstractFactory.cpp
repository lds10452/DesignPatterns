#include "CreationalPatterns.h"

// 产品A抽象类
class Desk {
public:
    virtual void Show() = 0;
};

// 产品B抽象类
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

// 工厂抽象类
class Factory {
public:
    virtual Desk* CreateDesk() = 0;
    virtual Chair* CreateChair() = 0;
};

// 生产木质产品的工厂
class WoodFactory : public Factory {
public:
    Desk* CreateDesk() {
        return new WoodDesk();
    }

    Chair* CreateChair() {
        return new WoodChair();
    }
};

// 生产铁质产品的工厂
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
    // 木工厂生产木桌
    Desk* DeskWood = FactoryWood->CreateDesk();
    DeskWood->Show();

    Factory* FactoryIron = new IronFactory();
    // 铁工厂生产铁椅
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