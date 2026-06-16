#include <iostream>
#include <Windows.h>
#include <string>

std::string adbpath = ".\\Tool\\adb\\adb.exe";
std::string fastbootpath = ".\\Tool\\adb\\fastboot.exe";
std::string adbversion = (adbpath + " version");
std::string fbversion = (fastbootpath + " --version");
int result;
int result2;

void adb()
{
    result = system(adbversion.c_str());
    // 成功时输出 0，失败时输出一个非零数字（比如 1）
    result2 = system(fbversion.c_str());
}

void Clear()
{
    system("cls");  // 清屏
}

int main() //切换背景色
{
    system("chcp 65001 > nul");
    std::cout << "正在切换背景色..." << std::endl;
    system("color 1F");
    Sleep(500);
    std::cout << "成功" << std::endl;
    Sleep(500);
    Clear();
    Sleep(500);
    std::cout << "开始测试命令是否可执行" << std::endl;
    Sleep(500);
    adb();
    Sleep(500);
    if (result == 0 && result2 == 0)
    {
        Sleep(500);
        std::cout << "命令可用" << std::endl;
    }
    else
    {
        Sleep(500);
        std::cout << "命令执行失败,请检查工具是否完整" << std::endl;
        system("pause");
        return 1;
    }
    std::cout << "正在进入主程序..." << std::endl;
    Sleep(500);
    Clear();
    
    // 加载并调用 Core.dll
    HMODULE hCore = LoadLibraryA("..\\Core.dll");
    if (hCore == NULL)
    {
        // 尝试当前目录
        hCore = LoadLibraryA("Core.dll");
        if (hCore == NULL)
        {
            std::cout << "加载 Core.dll 失败！" << std::endl;
            system("pause");
            return 1;
        }
    }
    
    // 获取 Run 函数（您的 DLL 导出的函数名是 Run）
    typedef void (*RunFunction)();
    RunFunction Run = (RunFunction)GetProcAddress(hCore, "Run");
    
    if (Run == NULL)
    {
        std::cout << "获取 Run 函数失败！" << std::endl;
        FreeLibrary(hCore);
        system("pause");
        return 1;
    }
    
    // 调用 DLL 中的主程序
    Run();
    
    // 程序结束（DLL 内部有自己的循环，执行完后才会到这里）
    FreeLibrary(hCore);
    std::cout << "程序已退出" << std::endl;
    system("pause");
    return 0;
}