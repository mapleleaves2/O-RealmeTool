# O+RealmeTool 欧加工具箱

一个基于 C++ 开发的辅助刷机小工具，专为 OPPO/一加/Realme 设备设计。

## 功能列表

- **一键解锁 BL**：支持一加/Pixel 设备快速解锁 Bootloader
- **临时 Root**：高通平台免解 BL 获取临时 Root 权限
- **一键投屏**：基于 scrcpy 的高清投屏
- **解包/提取 boot**：提取和解包 boot 镜像

## 使用说明

1. 下载最新版 `O+RealmeTool.exe`
2. 确保手机已开启 USB 调试
3. 运行程序，根据菜单提示操作

## 目录结构
O+RealmeTool/
├── Tool/
│ ├── adb/ # ADB 工具
│ ├── Patch/ # 修补 工具
│ ├── scrcpy/ # 投屏工具
│ └── rootapp/ # Root 管理器 APK
├── Core.dll # 主程序 DLL
├── payload.dll # 解包模块
├── root.dll # Root 模块
└── O+RealmeTool.exe # 主程序

## 编译环境

- 编译器：MinGW/GCC
- 标准：C++11
- 依赖：Windows SDK

## 免责声明

本工具仅供个人学习研究使用，请勿用于非法用途。操作刷机有一定风险，后果自负。

## 更新日志

### v1.0
- 基础功能实现
- 支持一加/Pixel 解锁 BL
- 支持高通临时 Root

## 下载地址

前往 [Releases](https://github.com/mapleleaves2/O-RealmeTool/releases) 页面下载最新版本。
