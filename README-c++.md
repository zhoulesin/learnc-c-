# C++

## C++简介

### 面向对象程序设计

- 封装
- 抽象
- 继承
- 多态

### 标准库

- 核心语言,提供了所有构建块,包括变量,数据类型和常量
- C++标准库,提供了大量的函数,用于操作文件,字符串等
- 标准模板库STL,提供了大量的方法,用于操作数据结构

## C++基本语法

c++程序可以定义为对象的集合,这些对象通过调用彼此的方法进行交互.

- 对象:对象具有状态和行为.
- 类:类可以定义为描述对象行为/状态 的 模板/蓝图
- 方法:从基本上说,一个方法表示一种行为.一个类可以包含多个方法.可以在方法中写入逻辑,操作数据以及执行所有的动作.
- 即时变量:每个对象都有其独特的即时变量.对象的状态是由这些即时变量的值创建的,

### C++程序结构

```c++
#include <iostream>

using namespace std;

//main() 是程序开始执行的地方

int main()
{
    cout << "hello world";	//输出hello world
    return 0;
}
```

- C++语言定义了一些头文件,这些头文件包含了程序中必须的或游泳的信息,上面包含了头文件\<iostream>
- using namespace std;告诉编译器使用std命名空间.
- main是主函数,程序从这里开始执行
- cout << "hello world";在屏幕上显示消息
- return 0; 终止main,并向调用进程返回0

### C++中的分号 & 语句块

### C++中的标识符

### C++中的关键字

## C++数据类型

### 基本的内置类型

| 类型     | 关键字  |
| -------- | ------- |
| 布尔     | bool    |
| 字符     | char    |
| 整型     | int     |
| 浮点     | float   |
| 双浮点   | double  |
| 无类型   | void    |
| 宽字符型 | wchar_t |

一些基本类型可以使用一个或多个类型修饰符进行修饰

- signed
- unsigned
- short
- long

### typedef声明

typedef可以为一个已有的类型取一个新的名字.

```c++
typedef int feet;
```

这里feet是int的另一个名称.

```c++
feet number;
```

### 枚举类型

```c++
enum color{red,green,blue} c;
c = blue;
```

默认情况下,第一个值为0,后面加1,

## C++变量

### C++中的变量声明

变量声明向编译器保证变量以给定的类型和名称存在,这样编译器不需要知道变量完整的细节情况下也能继续进一步的编译.变量声明只在编译时有它的意义,在程序连接是编译器需要实际的变量声明.

当你使用多个文件且只在其中一个文件中定义变量时,变量声明就显得非常有用.你可以使用extern关键字在任何地方声明一个变量,你可以在C++程序中多次声明一个变量,但变量只能在某个文件,函数或代码块中被定义一次

### 实例

```c++
#include <iostream>
using namespace std;

extern int a,b;
extern int c;
extern float f;

int main()
{
    int a,b;
    int c;
    float f;
    
    a = 10;
    b = 20;
    c = a + b;
    cout << c << endl;
    
    f = 70.0/30.0;
    cout << f << endl;
    
    return 0;
}
```

同样,在函数声明时,提供一个函数名,而函数的实际定义可以在任何地方进行

```c++
int func();

int main(){
    int i = func();
}

int func(){
   return 0; 
}
```

## C++ 变量作用域

作用域是程序的一个区域,一般来说有三个地方可以定义变量

- 在函数或一个代码块内部声明变量,局部变量
- 在函数参数定义中声明变量,形式参数
- 在所有函数外部声明的变量,全局变量

### 局部变量

```c++
#include <iostream>
using namespace std;

int main()
{
    int a,b;
    int c;
    
    a = 10;
    b = 20;
    c = a+b;
    
    cout << c ;
    
    return 0;
}
```

### 全局变量

在所有函数外部定义的变量,成为全局变量.全局变量在程序的整个声明周期内都是有效的.

全局变量可以被任何函数访问.全局变量一旦声明,在整个程序中都是可用的.

```c++
#include <iostream>
using namespace std;

int g;

int main()
{
    int a,b;
    a = 10;
    b = 20;
    g = a+b;
    
    cout <, g;
    
    return 0;
}
```

### 初始化局部变量和全局变量

| 数据类型 | 初始化默认值 |
| -------- | ------------ |
| int      | 0            |
| char     | '\0'         |
| float    | 0            |
| double   | 0            |
| pointer  | NULL         |

## C++常量

### 定义常量

- 使用#define预处理器
- 使用const关键字

```c
#include <iostream>
using namespace std;

#define LENGTH 10
#define WIDTH 5

int main(){
    int haha = LENGTH * WIDTH;
    
    const int AAA = 1;
    const int BBB = 4;
    
    int hehe = AAA * BBB;
    
    cout << haha << endl;
    cout << hehe;
    
    return 0;
}

```

## C++中的修饰符

### c++中的类型限定符

| 限定符   | 含义                                                         |
| -------- | ------------------------------------------------------------ |
| const    | cosnt类型的对象在程序执行期间不能被修改                      |
| volatile | 修饰符volatile告诉编译器不需要优化volatile声明的变量,让程序可以直接从内存读取变量.对于一般的变量编译会对变量进行优化,将内存中的变量值放在寄存器中以加快读写效率 |
| restrict | 由restrict修饰的指针是唯一一种访问它所指向对象的方式         |

## C++存储类

存储类定义C++程序中变量/函数的范围和生命周期.这些说明符放置在他们所修饰的类型之前.

- auto
- register
- static
- extern
- mutable
- thread_local

### auto存储类

auto关键字用于两种情况,声明变量时根据初始化表达式自动推断该变量的类型,声明函数时函数返回值的占位符.

### register存储类

register存储类用于定义存储在寄存器中而不是RAM中的局部变量.这意味着变量的最大尺寸等于寄存器的大小

切不能对他应用一元&运算符

```c++
{
    register int miles;
}
```

寄存器只用于需要快速访问的变量,比如计数器.

定义register并不意味着变量将被存储在寄存器中,它意味着变量可能存储在寄存器中,这取决于硬件和实现的限制

### static存储类

static存储类只是编译器在程序的生命周期内保持局部变量的存在,而不需要在每次进入和离开作用域时进行创建和销毁.因此使用static修饰局部变量可以在函数调用之间保持局部变量的值.

static修饰符也可以应用于全局变量.当static修饰全局变量时,会使变量的作用域限制在声明它的文件中.

```c++
#include <iostream>

void func(void);

static int count = 10;

int main()
{
    while(count --){
        func();
    }
    return 0;
}

void fun(void){
    static int i = 5;
    i++;
    std::cout << "变量 i 为" << i;
    std::cout << ", 变量count 为 " << count << std::endl;
}
```

### extern存储类

extern存储类用于提供一个全局变量的引用,全局变量对所有的程序文件都是可见的,当你使用extern时,对于无法初始化的变量,会把变量名指向一个之前定义过的存储位置

当你有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时,可以在其他文件中使用extern来得到已定义的变量或函数的引用,可以这么理解,extern是用来在另一个文件中声明一个全局变量或函数

extern修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候

```c
#include <iostream>

int count;
extern void write_extern();

int main()
{
    count = 5;
    write_extern();
}
```

第二个cpp文件

```c++
#include <iostream>
extern int count;
void write_extern()
{
    std::cout << "count is" << cout << std::endl;
}
```

### mutable存储类

mutable说明符仅适用于类的对象,它允许对象的成员替代常量..也就是说,mutable成员可以通过const成员函数修饰

### thread_local存储类

使用thread_local说明符声明的变量仅可在它在其上创建的线程上访问.变量在创建线程时创建,并在销毁线程时销毁.每个线程都有其自己的变量副本.

thread_local说明符可以与static或extern合并

可以将thread_local仅应用于数据声明和定义,thread_local不能用于函数声明或定义.

```c++
thread_local int x;	//命名空间下的全局变量

class X
{
    static thread_local std::string s;	//类的static成员变量
}
static thread_local std::string X::s;	//X::s 是需要定义的

void foo()
{
    thread_local std::vector<int> v;	//本地变量
}
```

## C++运算符

### 杂项

| 运算符        | 描述                                                         |
| ------------- | ------------------------------------------------------------ |
| sizeof        | sizeof返回变量的大小.                                        |
| condition?x:y | 三元                                                         |
| ,             | 逗号,会顺序执行一系列运算.整个逗号表达式的值是以逗号分隔的列表中的最后一个表达式的值 |
| .   ->        | 成员运算符,用于引用类,结构,共用体的成员                      |
| cast          | 强转                                                         |
| &             | 指针运算符,返回变量的地址,                                   |
| *             | 指针运算符,指向一个变量                                      |

## C++循环

## C++判断

## C++函数

函数是一组一起执行一个任务的语句.每个c++程序都至少有一个函数,main,所有简单的程序都可以定义其他额外的函数

你可以把代码划分到不同的函数中.

函数声明告诉编译器函数的名称,返回类型和参数.函数定义提供了函数的实际主体

c++标准库提供了大量的程序可以调用的内置函数.strcat用来连接两个字符串,memcpy用来赋值内存到另一个位置

### 定义函数

c++中函数定义

- 返回类型
- 函数名称
- 参数
- 函数主体

```c++
int max(int a,int b){
    int result;
    if(a > b){
        result = a;
    }else{
        result = b;
    }
    return result;
}
```

### 函数声明

函数声明会告诉编译器函数名称和如何调用函数,函数的实际主体可以单独定义

```c++
int max(int a,int b);
```

```c++
int max(int ,int);
```

当你在一个文件A中定义函数且在另一个文件B中调用该函数时,B中的函数声明时必须的.

### 调用函数

创建c++函数时,会定义函数做什么,然后通过调用函数来完成已定义的任务.

### 函数参数

形式参数

| 调用类型 | 描述                                      |
| -------- | ----------------------------------------- |
| 传值调用 | 该方法把参数的实际值复制给函数的形式参数, |
| 指针调用 | 该方法把参数的地址复制给形式参数.         |
| 引用调用 | 该方法吧参数的引用复制给形式参数          |

默认情况下,c++使用传值调用来传递参数.一般来说,这意味着函数内的代码不能改变用于调用函数的参数.

### 参数的默认值

当你定义一个函数,你可以为参数列表中后边的每一个参数指定默认值.当调用函数时,如果实际参数的值留空,则使用这个默认值.这是通过在函数定义中使用赋值运算符来为参数赋值的.调用函数时,如果未传递参数的值,会使用默认的值,如果指定了值,则会忽略默认值.

```c++
#include <iostream>
using namespace std;

int sum(int a,int b = 20){
    int result;
    
    result = a + b;
    
    return result;
}

int main()
{
    //局部变量声明
    int a = 200;
    int b = 100;
    int result;
    
    result = sum(a,b);
    cout << "total value is :" << result << endl;
    
    result = sum(a);
    cout << "title value is :" << result << endl;
    
    return 0;
}
```

### lambda函数与表达式

c++提供了堆匿名函数的支持,成为lambda函数

lambda表达式把函数看做对象.lambda表达式可以像对象一样使用,比如可以将他们赋给变量和作为参数传递,还可以像函数一样对其求值

lambda表达式本质上与函数声明非常类似

```c++
[](int x,int y){return x < y;}
```

如果没有返回值

```c++
[]{++global_x;}
```

返回类型可以被明确的指定

```c++
[](int x,int y) -> int{int z = x+y;return z+x;}
```

一个临时的参数z被创建用来存储中间结果.如同一般的函数,z的值不会保留到下一次该不具名函数再次被调用时.

如果lambda函数没有传回值,其返回类型可被完全忽略.

在lambda表达式内可以访问当前作用域的变量,这是lambda表达式的闭包closure行为.c++变量传递有传值和传引用的区别

> [] //没有定义任何变量,使用未定义变量会引发错误
>
> [x,&y]//x以传值方式传入,y以引用凡是传入
>
> [&]//任何被使用到的外部变量都隐式地以引用方式加以引用
>
> [=]//任何被使用到的外部变量都隐式地以传值方式加以引用
>
> [&,x]	//x显示地以传值方式加以引用,其他变量以引用方式加以引用
>
> [=,&z]	//z显示地以引用方式加以引用,其余变量以传值方式加以引用

- 对于[=]或[&]的形式,lambda表达式可以直接使用this指针,但是对于[]的形式,必须显示传入

  ```c++
  [this](){this->someFunc();}();
  ```

## C++数字

### C++数学运算

数学头文件\<cmath>

cos sin tan log pow hypot sqrt abs fabs floor

### C++随机数

rand 该函数返回一个伪随机数.生成随机数之前必须先调用srand函数

```c++
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int i,j;
    
    srand((unsigned)time(NULL));
    
    for(i = 0;i<10;i++){
        j = rand();
        cout << "随机数:" << j << endl;
    }
    
    return 0;
}
```

## C++数组

c++支持数组数据结构,他可以存储一个固定大小的相同类型元素的顺序集合.数组是用来存储一系列数据,但他往往被认为是一系列相同类型的变量.

数组的生命斌故事生命一个个单独的变量,比如num0,num1,...num55,而是声明一个数组变量,比如nums,然后使用nums[0],nums[1]...nums[55]来代表一个个单独的变量,数组中的特定元素可以通过索引访问.

所有的数组都是由连续的内存位置组成.最低的地址对应第一个元素,最高的地址对应最后一个元素.

### 声明数组

```c++
double bal[10];
```

### 初始化数组

c++可以逐个初始化数组,也可以使用初始化语句

```c++
double bal[5] = {1.1,2.2,3.3,4.4,5.5};
```

大括号{}之间的值的数目不能大于数组长度

如果省略小了数组大小,数组大IAO则初始化为元素个数

### 访问数组元素

## C++字符串

c++提供了两种类型字符串

- c风格字符串
- c++引入的string类型

### C++风格字符串

c字符串实际上是使用null字符'\0'终止的一维字符数组.

c++中有大量的函数来操作以null结尾的字符串

| 函数          | 目的                                |
| ------------- | ----------------------------------- |
| strcpy(s1,s2) | 复制字符串s2到字符串s1              |
| strcat(s1,s2) | 连接s2到s1末尾                      |
| strlen(s1)    | 返回s1长度                          |
| strcmp(s1,s2) | 比较s1和s2                          |
| strchr(s1,ch) | 返回指针,指向s1中ch第一次出现的位置 |
| strstr(s1,s2) | 返回指针,指向s1中s2第一次出现的位置 |

### C++中的string类

c++标准库提供了string类型,支持上述所有的操作,另外还增加了其他更多的功能.

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "hello";
    string str2 = "world";
    string str3;
    int len;
    
    str3 = str1;
    cout << "str3:" << str3 << endl;
    
    str3 = str1 + str2;
    cout << "str1 +str2 :" << str3 << endl;
    
    len = str3.size();
    cout << "str3.size() :" << len << endl;
    
    return 0;
}
```

## C++指针

学习c++的指针既简单又有趣.通过指针,可以简化一些c++编程任务的执行,还有一些任务,如动态分配内存,没有指针是无法执行的.

每一个变量都有一个内存位置,每一个内存位置都定义了可使用连字号&运算符访问的地址,他表示了在内存中的一个地址.

```c++
#include <iostream>
using namespace std;
int main()
{
    int var1;
    char var2[10];
    
    cout << "var1 变量的地址 :";
    cout << &var1 << endl;
    
    cout << "var2 变量的地址 : ";
    cout << &var2 << endl;
    
    return 0;
}
```

### 什么是指针

指针是一个变量,其值为另一个变量的地址.即内存位置的直接地址.就像其他变量或常量一样,你必须在使用指针存储其他变量地址之前,对其进行声明.

```c++
int *ip;
double *dp;
float *fp;
char *ch;
```

所有指针的值的实际数据类型,不管是整型,浮点型,字符型,还是其他的数据类型,都是一样的,都是一个代表内存地址的长的十六进制数.

### C++中使用指针

定义指针变量,把变量地址赋值给指针,访问指针变量中可用地址的值

```c++
#include <iostream>
using namespace std;
int main()
{
    int var = 20;
    int * ip;
    
    ip = &var;
    
    cout << "value of var :" ;
    cout << var << endl;
    
    cout << "adddress ip :";
    cout << ip << endl;
    
    cout << "value of *IP :" ;
    cout << *ip << endl;
    
    return 0;
        
}
```

![](.\imgs\20190111172236.png)

## C++引用

引用变量是一个别名,也就是说,它是某个已存在变量的另一个名字,一旦把引用初始化为变量,就可以使用该引用名称或变量名称来指向变量.

### C++引用 VS 指针

- 不存在空引用,引用必须连接到一块合法内存
- 一旦引用被初始化为一个对象,就不能被指向到另一个对象.指针可以在任何时候指向到另一个对象
- 引用必须在创建时被初始化.指针可以在任何事件被初始化

### C++中创建引用

变量名称是变量附属在内存位置中的标签,你可以把引用当成是变量附属在内存位置中的第二个标签.因此你可以通过原始变量名称或引用俩访问变量的内容

```c++
int i = 17;
int& r = i;
double& s = d;
```

在这些声明中,&读作引用.因此r是一个初始化为i的整型引用,s是一个初始化为d的double型引用.

```c++
#include <iostream>
using namespace std;

int main()
{
    int i;
    double d;
    int& r= i;
    double& s = d;
    
    i = 5;
    cout << "value of i:" << i<< endl;
    cout << "value of i reference : " << r << endl;
    
    d = 11.7;
    cout << "value of d:" << d << endl;
    cout << "value of d reference :" << s << endl;
    
    return 0;
}
```

引用通常用于函数参数列表和函数返回值,

| 概念             | 描述                                                 |
| ---------------- | ---------------------------------------------------- |
| 把引用作为参数   | C++支持吧引用作为参数传给函数,这比传一半的参数更安全 |
| 把引用作为返回值 | 可以从c++函数中返回引用,就像返回其他数据类型一样.    |

























































