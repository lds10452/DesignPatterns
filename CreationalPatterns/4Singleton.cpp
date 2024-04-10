#include "CreationalPatterns.h"

// ��־������
class LogSingleton {
public:
    // �����ṩ��ȡΨһʵ���Ľӿ�
    static LogSingleton* Instance() {
        if (NULL == m_pInstance) {
            // ֻ��һ�ε��ô˽ӿ�ʱ����ʵ��������
            m_pInstance = new LogSingleton();
        }
        return m_pInstance;
    }

    // չʾ��ǰ��־
    void Look() {
        printf("%s\n", strLog.c_str());
    }

    // д����־
    void Write(string strNew) {
        strLog += strNew;
    }

    // �ڴ����
    ~LogSingleton() {
        if (NULL != m_pInstance) {
            delete m_pInstance;
            m_pInstance = NULL;
        }
    }

private:
    // �����졢�������캯����Ϊ˽��
    LogSingleton() {}
    LogSingleton(const LogSingleton& oLog) {}

    static LogSingleton* m_pInstance; // ָ��Ψһʵ����ָ��
    string strLog;
};

// �ǵý�staticָ���ʼ��
LogSingleton* LogSingleton::m_pInstance = NULL;

void SingletonTest()
{
    cout << ".......start SingletonTest........" << endl;
    LogSingleton* pUserA = LogSingleton::Instance();
    pUserA->Write("Hello");

    LogSingleton* pUserB = LogSingleton::Instance();
    pUserB->Look();
}