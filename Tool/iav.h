// iav.h
#ifndef IAV_H
#define IAV_H

#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>
int syst = 0;
int fbsyst = 0;
std::string waitphone;
std::string andfb;
std::string waitfb;
std::string andsystem = "no";
std::string andfastboot = "no";
std::string wait2 = "no";
std::string wait3 = "no";
std::string exec(const char* cmd) {
    char buf[128];
    std::string result;
    FILE* pipe = _popen(cmd, "r");
    if (!pipe) return "ERROR";
    while (fgets(buf, sizeof(buf), pipe)) result += buf;
    _pclose(pipe);
    return result;
}
void Clear()
{
    system("cls");
}
void systemdevice() //系统模式重启fastboot
{
    wait3 = "no";
    while(wait3 == "no")
    {
        if (syst > 60)
        {
            std::cout << "等待设备超时,是否重试(y/n):";
            std::cin >> waitphone;
            Clear();
            if (waitphone == "y")
            {
                syst = 0;
            }
            else
            {
            return;
            }
        }
        else
        {
            std::cout << "等待设备连接(系统模式)" << std::endl;
            std::string readsystxt = exec(".\\Tool\\adb\\adb.exe devices"); 
            std::istringstream iss(readsystxt);
            std::string line;
            bool found = false;
            std::getline (iss,line);
            while (std::getline (iss,line))
            {
                if (line.find("device") != std::string::npos)
                {
                found = true;
                break;
                }
            }     
            if (found)
            {
                std::cout << "设备已连接!(系统模式)" << std::endl;
                waitphone = "n";
                wait3 = "yes";
                andsystem = "yes";
            }
            else
            {
                syst = syst + 1;
                Sleep(1000);
                Clear();
            }
        }
    }
}

void fastbootdevice() //检测fastboot设备连接
{
    wait2 = "no";
    while(wait2 == "no")
    {
        if (fbsyst > 60)
        {
            std::cout << "检测设备超时,是否重试(y/n):";
            std::cin >> andfb;
            Clear();
            if (andfb == "y")
            {
                fbsyst = 0;
                waitphone = "y";
            }
            else
            {
                waitphone = "n";
            }
        }
        std::cout << "等待设备连接(fastboot模式)" << std::endl;
        std::string readfbtxt = exec(".\\Tool\\adb\\fastboot.exe devices"); 
        std::istringstream iss2(readfbtxt);
        std::string line2;
        bool found2 = false;
        while(std::getline (iss2,line2))
        {
            if (line2.find("fastboot") != std::string::npos)
            {
                found2 = true;
                break; 
            }
        }
        if (found2)
        {
            std::cout << "设备已连接!(fastboot模式)" << std::endl;
            wait2 = "yes";
            andfastboot = "yes";
            Sleep(1000);
            waitfb = "n";
            fbsyst = 0;
        }
        else
        {
            fbsyst = fbsyst + 1;
            Sleep(1000);
            Clear();
            waitfb = "y";
        }
    }
}
#endif