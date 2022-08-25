# THU_Programming-2

**清华大学杨昉-程序设计基础（2)（雷系）小学期C++大作业**

---

## 总体要求

**设计课题题目**：每个同学都单独完成1道课题。后面有范题，仅供同学们参考，不列入本次课程设计的课题。

**对于程设题目**，按照范题的格式。自行虚构软件需求。并按照第4点要求，编写设计文档。基本要求系统中设计的类的数目不少于4个，每个类中要有各自的属性（多于3个成员）和方法（多于3个成员函数）；需要定义一个抽象类，采用继承方式派生这些类。并设计一个多重继承的派生类。在程序设计中，引入虚函数的多态性、运算符重载等机制。

### 程序设计要求

1. 要求利用面向对象的方法以及C++的编程思想来完成系统的设计； 
2. 要求在设计的过程中，建立清晰的类层次； 
3. 根据课题完成以下主要工作：
   1. 完成系统**需求**分析：包括系统设计目的与意义；系统功能需求（**系统流程图**）；输入输出的要求。
   2. 完成系统**总体**设计：包括系统功能分析；系统功能模块划分与设计（**系统功能模块图**）。
   3. 完成系统**详细**设计：数据文件；类层次图；界面设计与各功能模块实现。
   4. 系统**调试**：调试出现的主要问题，编译语法错误及修改，重点是运行逻辑问题修改和调整。
   5. 使用**说明书**及编程体会：说明如何使用你编写的程序，详细列出每一步的操作步骤。
   6. 关键源程序（带注释）。
4. 自己设计测试数据，将测试数据存在文件中，通过文件进行数据读写来获得测试结果。
5. 按规定格式完成课程设计报告，并在网络学堂上按时提交。
6. 不得抄袭他人程序、课程设计报告，每个人应独立完成，在程序和设计报告中体现自己的个性设计。 

---

## 设计进度

### DAY 1

考虑了一些系统需求
1. **用户**：学生和老师
2. **类的组成**
   1. 操纵类：用于读取、存储、增减数据，并按要求进行类似求均绩、展示不及格人数等操作
      - 操纵人员类
      - 操纵课程类
   2. 数据类：用于存储人员、课程的相关信息，提供信息的保护和读取接口
      - 人员类
        - 教师类
        - 学生类
      - 课程类

> Alexander Hamilton, 
We are waiting in the wings for you.  
You could never back down.  
You never learned to take your time.  
Oh, Alexander Hamilton~  
When America sings for you,  
Will they know what you overcame?  
Will they know you rewrote the game?  
The world will never be the same, oh~

### DAY 2

添加了一个新的类：菜单类-->用于展示菜单

搭建了系统的框架，包括
1. [ ] 数据类的大体内容
   1. [x] 人员类User
   2. [ ] 课程类Class
2. [ ] 操纵类的大体内容
   1. [x] 人员操纵类Interface
   2. [ ] 课程操纵类ClassInterface
3. [ ] 菜单类的大体内容
   1. [x] 主菜单
   2. [ ] 教师菜单
   3. [ ] 学生菜单
4. [ ] main.cpp进度**---**--------------------> 

>Raise a glass to freedom,  
Something they can never take away,  
No matter what they tell you!  
>
>Raise a glass to the four of us.  
>Tomorrow there’ll be more of us  
>Telling the story of tonight!  
>
>They’ll tell the story of tonight~

### DAY 3

搭建了系统的框架，包括
1. [x] 数据类的大体内容
   1. [x] 人员类User
   2. [x] 课程类Class
2. [x] 操纵类的大体内容
   1. [x] 人员操纵类Interface
   2. [x] 课程操纵类ClassInterface
   3. [ ] 补充一些操纵函数
3. [x] 菜单类的大体内容
   1. [x] 主菜单
   2. [x] 教师菜单
   3. [x] 学生菜单
4. [ ] main.cpp进度**----**-------------------> 

>Let me tell you what I wish I’d known,  
When I was young and dreamed of glory:  
You have no control:  
Who lives, who dies, who tells your story.  
>
>I know that we can win.  
I know that greatness lies in you.  
But remember from here on in,  
**History has its eyes on you.** 

### DAY 4

继续完善了main.cpp，添加了许多操纵函数，包括选课、退课、计算GPA等等，预计今天可以完成所有程序的编写，明天开始debug
1. [x] 数据类的大体内容
   1. [x] 人员类User
   2. [x] 课程类Class
2. [x] 操纵类的大体内容
   1. [x] 人员操纵类Interface
   2. [x] 课程操纵类ClassInterface
   3. [x] 补充一些操纵函数
3. [x] 菜单类的大体内容
   1. [x] 主菜单
   2. [x] 教师菜单
   3. [x] 学生菜单
4. [ ] main.cpp进度**-----------------**------> 

>Look at where you are.  
Look at where you started.  
The fact that you’re alive is a miracle.  
Just stay alive, that would be enough!  
And if your wife could share a fraction of your time,  
If I could grant you peace of mind,  
Would that be enough?


### DAY 5

羽毛球害人。

### DAY 6

终于把main.cpp搞完了，开始debug
1. [x] 数据类的大体内容
   1. [x] 人员类User
   2. [x] 课程类Class
2. [x] 操纵类的大体内容
   1. [x] 人员操纵类Interface
   2. [x] 课程操纵类ClassInterface
   3. [x] 补充一些操纵函数
3. [x] 菜单类的大体内容
   1. [x] 主菜单
   2. [x] 教师菜单
   3. [x] 学生菜单
4. [x] main.cpp进度**-----------------------**> 

>I wrote my way out of hell！  
I wrote my way to revolution！  
I was louder than the crack in the bell！  
I wrote Eliza love letters until she fell！  
I wrote about The Constitution and defended it well！  
And in the face of ignorance and resistance,  
I wrote financial systems into existence！  
And when my prayers to God were met with indifference,  
I picked up a pen, I wrote my own deliverance！！！  

### DAY idk

离ddl还有10天，重写一次代码其实还来得及，但是说实话有点懒了……  
为啥我会用这么蠢的办法去存取数据？为啥不搜一下C++的多映射库嘞……
重写的话就是删掉登录部分，做一个纯粹的数据管理，然后用一下multimap做课程和学号的映射。

---

## 使用说明和菜单操作

Is the System initiated？

- **Yes**-->login by entering id and password;
  - #### Student:
    1. Show GPA info;
        - Show grades of all class;
        - Show grade of one specific class;
        - Calculate GPA;
        - Return to previous menu;
            just usr the while loop;
	2. Register a class;  
        use the ***addStudent*** function;
	3. Withdraw a class; 
        usr the ***removeStudent*** function;
	- Exit system;
  - #### Teacher:
    1. Show GPA info;
       - 
    2. Register a class that you teach;  
        use the ***addClass*** function;  
    3. Upload GPA info;  
        use the ***Upload GPA info*** function;  
    4. Show class info;  
    5. Add a user;
        use the ***addUser*** function
    - Exit system;
- **No** or **New to the system**-->Add a user to the system first;



