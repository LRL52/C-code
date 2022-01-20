## 思路

- 写一个$\text{\color{Red}益智游戏}$程序，程序分为多个关卡，每个关卡是一个独立的"小游戏"，**把游戏设计的难度尽量放在C语言代码设计上（这样可以锻炼我们这学期学的知识），减少UI或前端的设计（毕竟咋也不会，如果有大佬会可以搞当然没问题）**，当然既然是游戏，需要保证一定的用户的**交互性（比如可以是输入答案，与程序博弈最优解）**

- 关于文件操作：项目要求我们需要将数据保存在文件中，以便下次启动程序能够读入数据。数据可以保存用户的关卡进度存档、关卡最高分 or 最优解等，还可以使用RSA加密原理实现一个简单的本地用户登录功能

目前游戏idea：

1. （二分) 猜数：

   ​		随机一个数，让用户来猜，程序反馈相对大小信息。猜数肯定二分最快，可以据此算出最小猜测次数，用户超过这个次数还未猜中则游戏失败

2. 简单AI五子棋：

   ​		用户和程序下五子棋，赢了即通关，这个UI界面貌似简单点。（当然让程序下五子棋肯定很难，写个简单点的就可以了）

3. 取石子游戏（idea来自Nim博弈）

   ​		Nim 游戏的规则是这样的：地上有 n*n 堆石子（每堆石子数量小于 $10^4$），每人每次可从任意一堆石子里取出任意多枚石子扔掉，可以取完，不能不取。每次只能从一堆里取。最后没石子可取的人就输了。用户和程序相互拿石子，按照规则用户赢了就算通过

4. 埃及分数

   ![image-20211129225844235](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20211129225844235.png)

   分数由计算机给出，用户需要拆出来提交答案，包括拆分方案，例如

   ![image-20211129225915343](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20211129225915343.png)

5. 钟城伟的游戏



## 合作指南

- 统一使用文件分割，共享部分数据，同时又可以保证没有变量名冲突问题
- 目前实现了多用户简单异或加密登录，数据存档，**现在鲁棒性还较弱，确保你输入的每一个指令都在提示内容内，不然肯定会出bug，此外密码目前仅支持long long范围内的数字**，这只是一个框架，便于你们参照编写可以合并的程序

- 每位提交者以`Subtask[number].c`和`Subtask[number].h`的方式提交，确保能在主框架程序`frame.c`中能编译通过

- 使用指南如下，以还没写的Subtask2**为例！！！！！，请按需替换更改相应部分**：

  - Subtask2.h

    ```c
    void Switchtask(); //切换关卡函数 
    void Subtask2(); //你的游戏函数入口 
    ```

  - Subtask2.c

    ```c
    #include "Subtask2.h" //引入你的头文件
    #include "diynode.h"  //引入自定义结构体类型,
    #include<stdio.h>
    extern node Data[]; //共享游戏数据Data 
    extern int id, taskid; //共享id, taskid, id为当前用户对应的数字序号, 用作Data[]下标, taskid表示当前正在进行或即将进入的关卡, 你很可能会用到 
    //你可以在下面写函数，定义变量等等
    
    void Subtask2(){ //下面将是你的游戏入口, 确保return后将taskid更改为合适的值, 1~Gamecnt表示对应关卡, -1表示退出游戏
        puts("Subtask2:"); //这只是一个演示测试而已, 建议删除
        Data[id].taskid = Data[id].taskid > 2 ? Data[id].taskid : 2; //更新用户的最高关卡记录
    	Switchtask(); //切换关卡, 可在退出时调用
    }
    
    ```

  - 游戏数据格式约定：

    自己游戏的数据保存在`Data[id].[number][] `中，id为用户编号，已经计算出，number为你的游戏编号，例如你做的Subtask2就是第2个游戏，然后你就可以在`Data[id].[number][0...9]`中存放数据了，其中`Data[id].[number][0]`表示你的数据个数

  - 可以参考我的Subtask1的实现，也可看看data.txt的格式

  - 确保你从你的游戏函数return后已经选好了下一个关卡

  - 编译命令（把你的程序和frame框架程序一起编译）：

    ![image-20211205163400627](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20211205163400627.png)
    
    ```
    gcc -o frame.exe frame.c Subtask1.c Subtask2.c 
    ```

- 暂定Subtask1为猜数游戏，Subtask2为五子棋，Subtask3为Nim博弈游戏，Subtask4为钟城伟的游戏，Subtask5为埃及分数，**请按照按照分配替换对应函数名、头文件名和最高关卡更新的关卡号**

