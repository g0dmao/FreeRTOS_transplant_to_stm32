# 基于 **stm32f103c8** 的 *FreeRTOS* 移植新建工程模板
<!-- vscode-markdown-toc -->
* 1. [1、作者说](#)
* 2. [2、版本说明](#-1)
* 3. [3、项目简介](#-1)
* 4. [4、特点](#-1)
* 5. [5、说明](#-1)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->


##  1. <a name=''></a>作者说

作为一名刚入门的萌新程序猿，以前在写代码时，版本备份都是复制粘贴，不知道有git这样的神器，偶然了解到了git这个东西，才发现github是这样用的，（以前只用它来白嫖别人的代码）于是兴奋的注册了github账号，然后迫不及待的想尝试一下版本发布，但是发现自己写的一堆bug完全没脸发出来啊。。。正好最近在学FreeRTOS，决定把最近整的FreeRTOS移植模板发出来试试。。。顺便再学学怎么写md。。。纯萌新一坨，，，如有问题请指正！

##  2. <a name='-1'></a>版本说明

- 2024.12.8 第一次发布

##  3. <a name='-1'></a>项目简介

此项目是基于**stm32f103c8**的 *FreeRTOS* 移植模板(手动配置的，非cubeMX或keil生成)，可以通过该工程模板构建项目，其中*FreeRTOSconfig.h*中有根据我自己理解写的注释同时也保留官方原版英文注释。

##  4. <a name='-1'></a>特点

- 本模板使用CubeMX配置外设（比较懒不想自己调用Hal库函数配置）。

- 本模板不使用CubeMX自动生成的*main.c*文件（自动生成的 *main.c* 注释太多太繁杂，个人比较喜欢简洁，于是新建了个main文件自己写了main函数入口）。不用再忍受CubeMX生成的一坨注释！

##  5. <a name='-1'></a>说明

- 使用了条件编译让编译器不编译CubeMX生成的 *main.c* 文件，但是CubeMX生成的代码还是会自动生成在其自己生成的 *“Core/Src/main.c“* 中，每次使用CubeMX生成代码后，你可以将原本main.c里自动生成的代码复制粘贴到自己的 *“UserDefined/* 中。

- *”UserDefined/“*：将自己写的头文件和源文件定义在这里。

- *”UserDefined/user_task.c“*: 存放的是所有用户任务函数和中断回调。

- *”UserDefined/export_fuc.c“*: 此文件定义了一些必要的功能函数，如一些处理系统错误的钩子函数、在一些宏定义开启时所需要的自己实现的函数（保能正确实现其功能）、断言等等。系统的时钟配置也在此。
- 文件采用UTF8编码。

<br>MarkDowm应该是这么写的吧。。qaq
