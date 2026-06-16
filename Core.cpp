// Core.dll
#include "Tool\\iav.h"
#include <fstream>
#include <stdio.h>
#include <shellapi.h>
int tool1;
int devicewait = 0;
std::string adbpath = ".\\Tool\\adb\\adb.exe";
std::string adbdevice = (adbpath + " devices");
std::string fbpath = ".\\Tool\\adb\\fastboot.exe";
std::string fbdevice = (fbpath + " devices");
std::string unlock;
std::string yn = "y";
std::string wait;
int result;
void ShowBox() //工具箱主页
{
    system("color 1F");
    system("chcp 65001 > nul");
    std::cout << "\n";
    std::cout << "╔════════════════════════════════╗" << std::endl;
    std::cout << "║         欧加工具箱 v1.3        ║" << std::endl;
    std::cout << "║       O+ Realme Toolbox        ║" << std::endl;
    std::cout << "║      by酷安 @mapleleaves5      ║" << std::endl;
    std::cout << "╚════════════════════════════════╝" << std::endl;
    std::cout << "\n";
    std::cout << "----------功能列表----------" << std::endl;
    std::cout << "1:一加/Pixel设备一键解锁BL" << std::endl;
    std::cout << "2:一键Root菜单" << std::endl;
    std::cout << "3:安卓一键投屏" << std::endl;
    std::cout << "4:解包/提取boot相关" << std::endl;
    std::cout << "请输入:";
}
// DLL 导出函数
extern "C" __declspec(dllexport) void Run() //主程序
{
    MessageBoxW(NULL,L"本次更新到了1.3版本\n1:优化了操作逻辑\n2:优化了部分代码\n3:开发了root功能",L"更新日志",MB_OK);
    while(yn == "y")
    {
        system("chcp 65001 > nul");
        ShowBox();
        std::cin >> tool1;
        
        if (tool1 == 1)
        {
            Clear();
            syst = 0;
            fbsyst = 0;
            waitphone = "y";
            while (waitphone == "y")
            {
                systemdevice();
                if (andsystem == "yes")
                {
                    system(".\\Tool\\adb\\adb.exe reboot bootloader");
                    Sleep(500);
                    waitfb = "y";
                    while(waitfb == "y")
                    {
                        fastbootdevice();
                        if (andfastboot == "yes")
                        {
                            system(".\\Tool\\adb\\fastboot.exe flashing unlock > nul 2>&1");
                            Sleep(1000);
                            std::cout << "命令执行成功,骁龙按两下音量下,一下电源键,天玑按音量上,不是按住" << std::endl;
                            std::cout << "是否返回主菜单?(y/n):";
                            std::cin >> yn;
                            Clear();
                        }
                        
                    }
                }
            }
        }
        else if (tool1 == 3)
        {
            Clear();
            std::cout << "请确认你现在已经将手机连接电脑并且开启了usb调试" << std::endl;
            std::cout << "是否继续?(y/n):";
            std::cin >> wait;
            if (wait == "y")
            {
                system("start .\\Tool\\scrcpy\\scrcpy.exe");
                Sleep(2000);
                std::cout << "投屏成功" << std::endl;
                std::cout << "是否返回主菜单?(y/n):";
                std::cin >> yn;
                Clear();
            }
            else
            {
                std::cout << "是否返回主菜单?(y/n):";
                std::cin >> yn;
                Clear();
            }
        }
        else if(tool1 == 2)
        {
            Clear();
                        
            // 加载 root.dll
            HMODULE hPayload = LoadLibraryA("root.dll");
            if (hPayload != NULL)
            {
                // 获取 Run 函数
                typedef void (*PayloadRun)();
                PayloadRun payloadRun = (PayloadRun)GetProcAddress(hPayload, "Run");
                
                if (payloadRun != NULL)
                {
                    payloadRun();  // 运行 root.dll
                }
                else
                {
                    std::cout << "无法找到 root.dll 入口" << std::endl;
                    system("pause");
                }
                
                FreeLibrary(hPayload);
            }
            else
            {
                std::cout << "无法加载 root.dll" << std::endl;
                system("pause");
            }
            Clear();
            yn = "y";  // 返回主菜单
        }
        else if(tool1 == 4)
        {
            Clear();
            
            // 加载 payload.dll
            HMODULE hPayload = LoadLibraryA("payload.dll");
            if (hPayload != NULL)
            {
                // 获取 Run 函数
                typedef void (*PayloadRun)();
                PayloadRun payloadRun = (PayloadRun)GetProcAddress(hPayload, "Run");
                
                if (payloadRun != NULL)
                {
                    payloadRun();  // 运行 payload.dll
                }
                else
                {
                    std::cout << "无法找到 payload.dll 入口" << std::endl;
                    system("pause");
                }
                
                FreeLibrary(hPayload);
            }
            else
            {
                std::cout << "无法加载 payload.dll" << std::endl;
                system("pause");
            }
            
            Clear();
            yn = "y";  // 返回主菜单
        }
        else
        {
            Clear();
            std::cout << "输入的值无效" << std::endl;
            std::cout << "是否返回主菜单?(y/n):";
            std::cin >> yn;
            Clear();
        }
    }
}

// DLL 入口
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    return TRUE;
}