#include "CreationalPatterns.h"

// 要构建的对象
class Graphic {
public:
    Graphic() {}

    // 常变属性的设置接口
    void SetShape(string strShape) {
        m_strShape = strShape;
    }

    void SetColor(string strColor) {
        m_strColor = strColor;
    }

    // 图形的验证方法
    void Show() {
        cout << m_strColor << m_strShape << endl;
    }

private:
    string m_strShape;
    string m_strColor;
};

//建造者抽象类
class Builder {
public:
    Builder() : m_pGraphic(NULL) {}

    // 创建空白图形
    void CreateGraphic() {
        if (NULL == m_pGraphic) {
            m_pGraphic = new Graphic();
        }
    }

    // 获取描绘完成的图形
    Graphic* GetGraphic() {
        return m_pGraphic;
    }

    // 留给派生类实现的描绘过程
    virtual void DrawShape() = 0;
    virtual void DrawColor() = 0;

protected:
    Graphic* m_pGraphic;
};

class GreenCircleBuilder : public Builder {
public:
    // 根据类的功能实现描绘过程
    void DrawShape() {
        if (NULL != m_pGraphic) {
            m_pGraphic->SetShape("Circle");
        }
    }

    void DrawColor() {
        if (NULL != m_pGraphic) {
            m_pGraphic->SetColor("Green");
        }
    }
};

class RedRectangleBuilder : public Builder {
public:
    // 根据类的功能实现描绘过程
    void DrawShape() {
        if (NULL != m_pGraphic) {
            m_pGraphic->SetShape("Rectangle");
        }
    }

    void DrawColor() {
        if (NULL != m_pGraphic) {
            m_pGraphic->SetColor("Red");
        }
    }
};

class BlueTriangleBuilder : public Builder {
public:
    // 根据类的功能实现描绘过程
    void DrawShape() {
        if (NULL != m_pGraphic) {
            m_pGraphic->SetShape("Triangle");
        }
    }

    void DrawColor() {
        if (NULL != m_pGraphic) {
            m_pGraphic->SetColor("Blue");
        }
    }
};

// 导演类
class Director {
public:
    Director() : m_pBuilder(NULL) {}

    // 根据需求设置对应的建造者
    void SetBuilder(Builder& pBuilder) {
        m_pBuilder = &pBuilder;
    }

    // 通过建造者获得描绘完成的图形
    Graphic* DrawGraphic() {
        if (NULL == m_pBuilder) {
            return NULL;
        }
        //建造过程为不变的因素
        m_pBuilder->CreateGraphic();
        m_pBuilder->DrawShape();
        m_pBuilder->DrawColor();
        return m_pBuilder->GetGraphic();
    }

private:
    Builder* m_pBuilder;
};

void BuilderTest()
{
    cout << ".......start BuilderTest........" << endl;
    Director MyDirector;
    // 根据导演的不同需求，分别设置不同的建造者，获得满足需求的图形
    GreenCircleBuilder BuilderGC; // 绿色圆形的建造者
    MyDirector.SetBuilder(BuilderGC);
    Graphic* pGraphicGC = MyDirector.DrawGraphic(); // 导演使用建造者画图
    pGraphicGC->Show();

    RedRectangleBuilder BuilderRB; // 红色矩形的建造者
    MyDirector.SetBuilder(BuilderRB);
    Graphic* pGraphicRB = MyDirector.DrawGraphic(); // 导演使用建造者画图
    pGraphicRB->Show();

    BlueTriangleBuilder BuilderBT; // 蓝色三角的建造者
    MyDirector.SetBuilder(BuilderBT);
    Graphic* pGraphicBT = MyDirector.DrawGraphic(); // 导演使用建造者画图
    pGraphicBT->Show();

    // 资源回收
    if (NULL == pGraphicGC) {
        delete pGraphicGC;
        pGraphicGC = NULL;
    }
    if (NULL == pGraphicRB) {
        delete pGraphicRB;
        pGraphicRB = NULL;
    }
    if (NULL == pGraphicBT) {
        delete pGraphicBT;
        pGraphicBT = NULL;
    }
}