#include "CreationalPatterns.h"

// ö�ٶ����Ʒ����
typedef enum ProductType {
    PRODUCT_DESK,
    PRODUCT_CHAIR,
} PROTYPE;

// ��Ʒ������
class Product {
public:
    virtual void Show() = 0; // ������֤��Ʒ��Ϣ
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

// ������
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
    // ��������
    Factory* MyFactory = new Factory();

    // �����Ʒ���ʹ�����Ʒ
    Product* DeskWood = MyFactory->CreateProduct(PRODUCT_DESK);
    DeskWood->Show();
    Product* ChairWood = MyFactory->CreateProduct(PRODUCT_CHAIR);
    ChairWood->Show();

    if (NULL != MyFactory) {
        delete MyFactory;
        MyFactory = NULL;
    }
}
