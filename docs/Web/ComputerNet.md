# 计算机网络学习笔记

教材：计算机网络（自顶向下方法）第七版
课程视频：[中科大计算机网络公开课](https://www.bilibili.com/video/BV1JV411t7ow?p=2&vd_source=e0c5d304125ac648272a937672080091)

## 1. 计算机网络概述
### 书本预习内容
- 计算机网络的定义
计算机网络是互连的、自治的计算机集合。
因特网是一个全球的计算机网络，是由互联网服务提供商（ISP）和其他组织共同构成的。
- 端系统通过通信链路和分组交换机连接到因特网。
通信链路（communication link）：不同的物理媒介，如同轴电缆、铜线、光纤等。
分组交换机（packet switch）：将数据分组从一个端系统移动到另一个端系统。
端系统通过因特网服务提供商（ISP）接入因特网。
- 所有的通信和传输都需要遵守协议。
协议定义了在两个或多个通信实体之间交换的报文格式和顺序，以及报文发送和接收一条报文或其他事件所采取的动作。
TCP（Transmission Control Protocol）和IP（Internet Protocol）是因特网的两个核心协议。
零碎知识点：
分布式应用程序：运行在不同端系统上的应用程序。
套接字接口：应用程序通过套接字接口调用协议来发送和接收报文。该接口规定了运行
在一个端系统上的程序请求因特网基础设施向运行在另一个端系统上的特定目的地程序交
付数据的方式。
- 网络边缘
网络边缘是指连接到因特网的端系统。
端系统又称为主机（host），包括台式机、笔记本电脑、手机、Web 服务器、Web 客户端
又分为客户端和服务器。

- 接入网络
接入网络是端系统连接到其边缘路由器的物理链路。
1. 家庭接入：DSL、电缆、FTTH、拨号调制解调器、卫星
DSL：数字用户线（Digital Subscriber Line）是一种家庭接入技术，它使用现有的电话线来传输数字信号。
电缆因特网接入：通过有线电视公司提供的电缆来接入因特网。
FTTH：光纤到户（Fiber To The Home）是一种家庭接入技术，它使用光纤来传输数字信号。
拨号调制解调器：通过电话线接入因特网。
卫星因特网接入：通过卫星接入因特网。
2. 企业接入：以太网、WiFi
使用局域网（Local Area Network）技术，如以太网和 WiFi。
以太网：一种局域网技术，使用双绞线或光纤来传输数据，需要有线交换机。
WiFi：一种无线局域网技术，使用无线接入点（wireless access point）来传输数据。
3. 移动接入：3G、4G、5G
广域无线接入技术，通过蜂窝网络连接到因特网。

- 物理媒介
1. 双绞线：一种传输数据的物理媒介，由四对绝缘的铜线组成。
2. 同轴电缆：一种传输数据的物理媒介，由一对中心导体、绝缘层、外导体和外部绝缘层组成。
3. 光纤：一种传输数据的物理媒介，由一根玻璃纤维组成，可以传输光信号。
4. 无线电频谱：一种传输数据的物理媒介，通过无线电波传输数据。分为陆地无线电频谱和卫星无线电频谱。
   
- 网络核心
