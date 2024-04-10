#include "CreationalPatterns.h"

// 日志单件类
class LogSingleton {
public:
    // 对外提供获取唯一实例的接口
    static LogSingleton* Instance() {
        if (NULL == m_pInstance) {
            // 只第一次调用此接口时创建实例化对象
            m_pInstance = new LogSingleton();
        }
        return m_pInstance;
    }

    // 展示当前日志
    void Look() {
        printf("%s\n", strLog.c_str());
    }

    // 写入日志
    void Write(string strNew) {
        strLog += strNew;
    }

    // 内存回收
    ~LogSingleton() {
        if (NULL != m_pInstance) {
            delete m_pInstance;
            m_pInstance = NULL;
        }
    }

private:
    // 将构造、拷贝构造函数设为私有
    LogSingleton() {}
    LogSingleton(const LogSingleton& oLog) {}

    static LogSingleton* m_pInstance; // 指向唯一实例的指针
    string strLog;
};

// 记得将static指针初始化
LogSingleton* LogSingleton::m_pInstance = NULL;

void SingletonTest()
{
    cout << ".......start SingletonTest........" << endl;
    LogSingleton* pUserA = LogSingleton::Instance();
    pUserA->Write("Hello");

    LogSingleton* pUserB = LogSingleton::Instance();
    pUserB->Look();
}