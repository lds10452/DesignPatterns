#include "CreationalPatterns.h"

// Ҫ�����Ķ���
class Graphic {
public:
    Graphic() {}

    // �������Ե����ýӿ�
    void SetShape(string strShape) {
        m_strShape = strShape;
    }

    void SetColor(string strColor) {
        m_strColor = strColor;
    }

    // ͼ�ε���֤����
    void Show() {
        cout << m_strColor << m_strShape << endl;
    }

private:
    string m_strShape;
    string m_strColor;
};

//�����߳�����
class Builder {
public:
    Builder() : m_pGraphic(NULL) {}

    // �����հ�ͼ��
    void CreateGraphic() {
        if (NULL == m_pGraphic) {
            m_pGraphic = new Graphic();
        }
    }

    // ��ȡ�����ɵ�ͼ��
    Graphic* GetGraphic() {
        return m_pGraphic;
    }

    // ����������ʵ�ֵ�������
    virtual void DrawShape() = 0;
    virtual void DrawColor() = 0;

protected:
    Graphic* m_pGraphic;
};

class GreenCircleBuilder : public Builder {
public:
    // ������Ĺ���ʵ��������
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
    // ������Ĺ���ʵ��������
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
    // ������Ĺ���ʵ��������
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

// ������
class Director {
public:
    Director() : m_pBuilder(NULL) {}

    // �����������ö�Ӧ�Ľ�����
    void SetBuilder(Builder& pBuilder) {
        m_pBuilder = &pBuilder;
    }

    // ͨ�������߻�������ɵ�ͼ��
    Graphic* DrawGraphic() {
        if (NULL == m_pBuilder) {
            return NULL;
        }
        //�������Ϊ���������
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
    // ���ݵ��ݵĲ�ͬ���󣬷ֱ����ò�ͬ�Ľ����ߣ�������������ͼ��
    GreenCircleBuilder BuilderGC; // ��ɫԲ�εĽ�����
    MyDirector.SetBuilder(BuilderGC);
    Graphic* pGraphicGC = MyDirector.DrawGraphic(); // ����ʹ�ý����߻�ͼ
    pGraphicGC->Show();

    RedRectangleBuilder BuilderRB; // ��ɫ���εĽ�����
    MyDirector.SetBuilder(BuilderRB);
    Graphic* pGraphicRB = MyDirector.DrawGraphic(); // ����ʹ�ý����߻�ͼ
    pGraphicRB->Show();

    BlueTriangleBuilder BuilderBT; // ��ɫ���ǵĽ�����
    MyDirector.SetBuilder(BuilderBT);
    Graphic* pGraphicBT = MyDirector.DrawGraphic(); // ����ʹ�ý����߻�ͼ
    pGraphicBT->Show();

    // ��Դ����
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