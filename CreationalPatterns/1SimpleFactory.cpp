#include "CreationalPatterns.h"

// 枚举定义产品类型
typedef enum ProductType {
    PRODUCT_DESK,
    PRODUCT_CHAIR,
} PROTYPE;

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

// 工厂类
class Factory {
public:
    Product* CreateProduct(PROTYPE type) {
        switch (type) {
        case PRODUCT_DESK:
            return new Desk();
        case PRODUCT_CHAIR:
            return new Chair();
        default:
            break;
        }
        return NULL;
    }
};

void SimpleFactoryTest()
{
    cout << ".......start SimpleFactoryTest........" << endl;
    // 创建工厂
    Factory* MyFactory = new Factory();

    // 传入产品类型创建产品
    Product* DeskWood = MyFactory->CreateProduct(PRODUCT_DESK);
    DeskWood->Show();
    Product* ChairWood = MyFactory->CreateProduct(PRODUCT_CHAIR);
    ChairWood->Show();

    if (NULL != MyFactory) {
        delete MyFactory;
        MyFactory = NULL;
    }
}
