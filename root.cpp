//root.dll --- Core.dll附属函数，用于root
#include "Tool\\iav.h"
#include <fstream>
#include <stdio.h>
#include <shellapi.h>

int rootshowbox; //root主页存储用户选择的变量
std::string rootyn = "y"; //root重复大while循环的变量
int kersuandsukisu;

void selinuxroot() //宽容后临时root
{
    systemdevice();
    if (andsystem == "yes")
    {
        std::cout << "----------请选择临时root管理器----------" << std::endl;
        std::cout << "1:KernelSU" << std::endl;
        std::cout << "2:Sukisu Ultra" << std::endl;
        std::cout << "请输入:";
        std::cin >> kersuandsukisu;
        if(kersuandsukisu == 1)
        {
            system(".\\Tool\\adb\\adb.exe install .\\Tool\\rootapp\\KernelSU.apk");
            std::cout << "安装root管理器成功" << std::endl;
            system(".\\Tool\\adb\\adb.exe shell am start -n me.weishu.kernelsu/.ui.MainActivity");
            std::cout << "是否返回主菜单?(y/n):";
            std::cin >> rootyn;
        }
        else if(kersuandsukisu == 2)
        {
            system(".\\Tool\\adb\\adb.exe install .\\Tool\\rootapp\\Sukisu.apk");
            std::cout << "安装root管理器成功" << std::endl;
            system(".\\Tool\\adb\\adb.exe shell am start -n com.sukisu.ultra/.ui.MainActivity");
            std::cout << "是否返回主菜单?(y/n):";
            std::cin >> rootyn;
            Clear();
        }
    }
}

void ShowBox() //root主页
{
    system("color 1F");
    system("chcp 65001 > nul");
    std::cout << "\n";
    std::cout << "╔════════════════════════════════╗" << std::endl;
    std::cout << "║         欧加工具箱 v1.1        ║" << std::endl;
    std::cout << "║       O+ Realme Toolbox        ║" << std::endl;
    std::cout << "║      by酷安 @mapleleaves5      ║" << std::endl;
    std::cout << "║            root目录            ║" << std::endl;
    std::cout << "╚════════════════════════════════╝" << std::endl;
    std::cout << "\n";
    std::cout << "----------root目录----------" << std::endl;
    std::cout << "1:一键root方案(开发中)" << std::endl;
    std::cout << "2:临时root方案" << std::endl;
    std::cout << "3:返回主菜单" << std::endl;
    std::cout << "请输入:";
    std::cin >> rootshowbox;
}

// DLL 导出函数
extern "C" __declspec(dllexport) void Run()
{
    rootyn = "y";
    
    while(rootyn == "y")
    {
        ShowBox();
        
        if (rootshowbox == 1)
        {
            Clear();
            std::cout << "该功能开发中" << std::endl;
            std::cout << "是否返回主菜单?(y/n)" << std::endl;
            std::cout << "请输入:";
            std::cin >> rootyn;
            Clear();
        }
        else if(rootshowbox == 2)
        {
            Clear();
            std::cout << "请确保手机已经开启usb调试并连接电脑,按下回车继续" << std::endl;
            system("pause");
            std::cout << "开始执行临时root流程" << std::endl;
            std::string whileroot = "y";
            while(whileroot == "y")
            {
                systemdevice();
                if (andsystem == "yes")
                {
                    std::string line3 = exec(".\\Tool\\adb\\adb.exe shell getenforce");
                    
                    if(line3.find("Enforcing") != std::string::npos)
                    {
                        std::cout << "设备未宽容,执行宽容流程" << std::endl;
                        std::cout << "重启到fastboot......" << std::endl;
                        system(".\\Tool\\adb\\adb.exe reboot bootloader");
                        fastbootdevice();
                        if (andfastboot == "yes")
                        {
                            std::string line4 = exec(".\\Tool\\adb\\fastboot.exe oem set-gpu-preemption 0 androidboot.selinux=permissive 2>&1");
                            system(".\\Tool\\adb\\fastboot.exe continue");
                            if(line4.find("OKAY") != std::string::npos)
                            {
                                std::cout << "宽容成功,开始执行临时root流程" << std::endl;
                                Clear();
                            }
                            else
                            {
                                std::cout << "宽容失败";
                                Sleep(1000);
                                return;
                            }
                        }
                       else
                        {
                             return;  // 改为 return，不是 return 0
                        }
                    }
                    else if(line3.find("Permissive") != std::string::npos)
                    {
                        std::cout << "设备已经宽容,无需再次宽容" << std::endl;
                        Sleep(1000);
                        Clear();
                        selinuxroot();
                        whileroot = "n";
                    }
                }
            }
        }
        else if (rootshowbox == 3)
        {
            rootyn = "n";
        }
    }
}

// DLL 入口
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    return TRUE;
}