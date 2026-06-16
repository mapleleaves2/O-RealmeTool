//payload.dll --- Core.dll附属函数，用于解包相关功能
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <shellapi.h>

int payload1;//showbox里的
int payload2;//void payload里面的
std::string payload3; //payload.bin文件路径
std::string payload4; //解包保存路径
std::string payload5; //返回询问函数
std::string payload6; //存储解包要提取的分区名
std::string payloadshell;// 全部解包命令
std::string payloadshell1;//boot解包
std::string payloadshell2;//init_boot解包
std::string payloadshell3; //任意分区解包

void EscapePath(std::string& path)
{
    std::string result;
    for (char c : path)
    {
        if (c == '\\')
        {
            result += "\\\\";
        }
        else
        {
            result += c;
        }
    }
    path = result;
}

void Clear()
{
    system("cls");
}

void ShowBox() //解包主页
{
    system("color 1F");
    system("chcp 65001 > nul");
    std::cout << "\n";
    std::cout << "╔════════════════════════════════╗" << std::endl;
    std::cout << "║         欧加工具箱 v1.1        ║" << std::endl;
    std::cout << "║       O+ Realme Toolbox        ║" << std::endl;
    std::cout << "║      by酷安 @mapleleaves5      ║" << std::endl;
    std::cout << "║            解包目录            ║" << std::endl;
    std::cout << "╚════════════════════════════════╝" << std::endl;
    std::cout << "\n";
    std::cout << "----------解包目录----------" << std::endl;
    std::cout << "1:通过云端url解包(开发中)" << std::endl;
    std::cout << "2:通过本地payload.bin文件一键解包" << std::endl;
    std::cout << "3:通过整理好的资源包选择(作者正在整理中,请勿选择)" << std::endl;
    std::cout << "4:返回主菜单" << std::endl;
    std::cout << "请输入:";
    std::cin >> payload1;
}

void payload()
{
    Clear();
    std::cout << "请将payload.bin文件拖入此窗口,出现路径后按下回车,路径不能有空格!!!!!!" << std::endl;
    std::cout << "请输入:";
    std::cin >> payload3;
    Clear();
    std::cout << "请输入解包后的文件保存位置" << std::endl;
    std::cout << "请输入:" << std::endl;
    std::cin >> payload4;
    Clear();
    EscapePath(payload3);
    EscapePath(payload4);    
    payloadshell = ".\\Tool\\Patch\\payload.exe -o " + payload4 + "\\images " + payload3;
    payloadshell1 = ".\\Tool\\Patch\\payload.exe -p boot -o " + payload4 + "\\images " + payload3;
    payloadshell2 = ".\\Tool\\Patch\\payload.exe -p init_boot -o " + payload4 + "\\images " + payload3;
    std::cout << "你当前选择的是:通过本地payload文件一键解包" << std::endl;
    std::cout << "你选择的payload.bin文件为" << payload3 <<std::endl;
    std::cout << "----------payload解包选项----------" << std::endl;
    std::cout << "1:一键提取全部分区(线刷选择)" << std::endl;
    std::cout << "2:提取boot分区" << std::endl;
    std::cout << "3:提取init_boot分区" << std::endl;
    std::cout << "4:提取任意分区" << std::endl;
    std::cout << "5:重新选择" << std::endl;
    std::cout << "请输入:";
    std::cin >> payload2;
    Clear();
    if (payload2 == 1)
    {
        Clear();
        std::cout << "开始解包位于" << payload3 << "的payload.bin文件,保存在" << payload4 <<std::endl;
        system(payloadshell.c_str());
        std::cout << "解包成功,是否返回主菜单(y/n)" << std::endl;;
        std::cout << "请输入:";
        std::cin >> payload5; 
        Clear();      
    }  
    else if (payload2 == 2)
    {
        Clear();
        std::cout << "开始提取boot分区" << std::endl;
        system (payloadshell1.c_str());
        std::cout << "提取完成" << std::endl;
        std::cout << "是否返回主菜单(y/n)" << std::endl;
        std::cout << "请输入:";
        std::cin >> payload5;
        Clear();
    } 
    else if (payload2 == 3)
    {
        Clear();
        std::cout << "开始提取init_boot分区" << std::endl;
        system (payloadshell2.c_str());
        std::cout << "提取完成" << std::endl;
        std::cout << "是否返回主菜单(y/n)" << std::endl;
        std::cout << "请输入:";
        std::cin >> payload5;
        Clear();
    } 
    else if (payload2 == 4)
    {
        Clear();
        std::cout << "请输入要提取的分区名:";
        std::cin >> payload6;
        payloadshell3 = ".\\Tool\\Patch\\payload.exe -p " + payload6 + " -o " + payload4 + "\\images " + payload3;
        std::cout << "你要提取的分区是:" << payload6 << std::endl;
        Sleep(2000);
        std::cout << "按回车继续" << std::endl;
        system("pause");
        system (payloadshell3.c_str());
        std::cout << "提取完成" << std::endl;
        std::cout << "是否返回主菜单(y/n)" << std::endl;
        std::cout << "请输入:";
        std::cin >> payload5;
        Clear();
    }
    else if (payload2 == 5)
    {
        payload5 = "y";
    }
    else
    {
        Clear();
        std::cout << "输入无效" << std::endl;
        std::cout << "是否返回主菜单(y/n)" << std::endl;
        std::cout << "请输入:";
        std::cin >> payload5;
        Clear();
    }
}

// DLL 入口点
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// 导出 Run 函数
extern "C" __declspec(dllexport) void Run()
{
    system("color 1F");
    system("chcp 65001 > nul");
    payload5 = "y";
    while (payload5 == "y")
    {
        ShowBox();
        if (payload1 == 1)
        {
            std::cout << "该功能开发中" << std::endl;
            Sleep(500);
            std::cout << "是否返回主菜单(y/n)" << std::endl;
            std::cout << "请输入:";
            std::cin >> payload5;
            Clear();
        }
        else if(payload1 == 2)
        {
            payload();
        }
        else if(payload1 == 3)
        {
            std::cout << "该功能开发中" << std::endl;
            Sleep(500);
            std::cout << "是否返回主菜单(y/n)" << std::endl;
            std::cout << "请输入:";
            std::cin >> payload5;
            Clear();
        }
        else if(payload1 == 4)
        {
            std::cout << "即将返回主程序" << std::endl;
            payload5 = "n";
        }
        else
        {
            std::cout << "输入无效" << std::endl;
            std::cout << "是否返回主菜单(y/n)" << std::endl;
            std::cout << "请输入:";
            std::cin >> payload5;
            Clear();
        }
    }
}