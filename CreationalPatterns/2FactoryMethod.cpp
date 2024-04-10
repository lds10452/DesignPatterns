#include "CreationalPatterns.h"
// 产品抽象类
class Product {
public:
    virtual void Show() = 0; // 用于验证产品信息
};

class Desk : public Product {
public:
    void Show() {
        cout << "Desk" << endl;
    }
};

class Chair : public Product {
public:
    void Show() {
        cout << "Chair" << endl;
    }
};

// 工厂抽象类
class Factory {
public:
    virtual Product* CreateProduct() = 0;
};

class DeskFactory : public Factory {
public:
    Product* CreateProduct() {
        return new Desk();
    }
};

class ChairFactory : public Factory {
public:
    Product* CreateProduct() {
        return new Chair();
    }
};

void FactoryMethodTest() 
{
    cout << ".......start FactoryMethodTest........" << endl;
    Factory* FactoryDesk = new DeskFactory();
    Product* Desk = FactoryDesk->CreateProduct();
    Desk->Show();

    Factory* FactoryChair = new ChairFactory();
    Product* Chair = FactoryChair->CreateProduct();
    Chair->Show();

    if (NULL != FactoryDesk) {
        delete FactoryDesk;
        FactoryDesk = NULL;
    }
    if (NULL != FactoryChair) {
        delete FactoryChair;
        FactoryChair = NULL;
    }
}