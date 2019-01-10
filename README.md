# learnc-c-

## 基本语法

### 关键字

| 关键字   | 说明                                             |
| -------- | ------------------------------------------------ |
| auto     | 自动变量                                         |
| break    |                                                  |
| case     |                                                  |
| char     |                                                  |
| const    | 只读变量                                         |
| continue |                                                  |
| default  |                                                  |
| do       |                                                  |
| double   |                                                  |
| else     |                                                  |
| enum     |                                                  |
| extern   | 声明变量或函数是在其他文件或本文件的其他位置定义 |
| float    |                                                  |
| for      |                                                  |
| goto     | 无条件跳转语句                                   |
| if       |                                                  |
| int      |                                                  |
| long     |                                                  |
| register | 声明寄存器变量                                   |
| return   |                                                  |
| short    |                                                  |
| signed   | 声明有符号类型变量或函数                         |
| sizeof   | 计算数据类型或变量长度                           |
| static   |                                                  |
| struct   | 声明结构体类型                                   |
| switch   |                                                  |
| typedef  | 用以给数据类型取                                 |
| unsigned |                                                  |
| union    | 声明共用体类型                                   |
| void     |                                                  |
| volatile | 说明变量在程序执行中可被隐含地改变               |
| while    |                                                  |

## 数据类型

| 类型     | 描述                                                         |
| -------- | ------------------------------------------------------------ |
| 基本类型 | 他们是算术类型,包括整数类型和浮点类型                        |
| 枚举类型 | 也是算术类型,被用来定义在程序 中只能赋予其一定的离散整数值的变量 |
| void类型 | void表明没有可用的值                                         |
| 派生类型 | 包括,指针类型,数组类型,结构类型,共用体类型和函数类型         |

### 整数类型

| 类型           | 存储大小 | 值范围                                 |
| -------------- | -------- | -------------------------------------- |
| char           | 1字节    | -128到127或0-255                       |
| unsigned char  | 1        | 0-255                                  |
| signed char    | 1        | -128-127                               |
| int            | 2或4字节 | -32768到32767或-2147483648到2147483647 |
| unsigned int   |          |                                        |
| signed int     |          |                                        |
| short          | 2字节    | -32768-32767                           |
| unsigned short |          |                                        |
| signed short   |          |                                        |
| long           | 4        | -2147483648-2147483647                 |
| unsigned long  |          |                                        |

- %lu 为32位无符号整数

### 浮点类型

| 类型       | 存储达小 | 值范围 |
| ---------- | -------- | ------ |
| float      | 4        |        |
| double     | 8        |        |
| longdouble | 16       |        |

- 头文件 float.h定义了宏
- %E 为以指数形式输出单.双精度实数.

### void类型

| 类型         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| 函数返回空   | C中有函数都不返回值,或者你可以说他们返回空..不返回值的函数返回类型为空. |
| 函数参数为空 | C中有函数不接受任何参数.不带参数的函数可以接受一个void       |
| 指针指向void | 类型为void *的指针代表对象的地址,而不是类型..内存分配函数void *malloc(size_t size);返回指向void的指针,可以转换为任何数据类型. |

## C变量

基本变量类型

char  int  float  double  void

### C中变量定义

```c
int i,j,k;
char c,ch;
float f,salary;
double d;
```

```c
extern int d=1,f=5;
int d=2,ff=1;
byte z = 11;
char x = 'x';
```

### C中的变量声明

变量声明向编译器保证变量以指定的类型和名称存在,这样编译器在不需要知道变量完整细节的情况下也能继续进一步的编译.变量声明只在编译时有他的意义,在程序连接时编译器需要实际的变量声明.

- 一种是需要建立存储空间的,int a在声明的时候就已经建立了存储空间

- 一种是不需要建立存储空间的,通过使用extern关键字声明变量名而不定义它.extern int a其中变量a可以在别的文件中定义的.

- 除非有extern关键字,否则都是变量的定义

  ```c
  extern int i;//声明,不是定义
  int i;//声明,也是定义
  ```

## C常量

常量是固定值,在程序执行期间不会改变,又叫字面量.

### 定义常量

在C中,有两种简单的定义常量的方式

- 使用#define 预处理
- 使用const 关键字

#### #define预处理

```c
#define LENGTH 10
#define VALUE 20
```

#### const关键字

```c
const int LENGTH = 10;
const int VALUE = 20;
```

## C存储类

存储类定义C程序中变量/函数的范围和生命周期.这些说明符放置在他们所修饰的类型之前.

- auto
- register
- static
- extern

### auto存储类

auto是所有局部变量默认的存储类

```c
{
    int mount;
    auto int mount;
}
```

上面的实例定义了两个带有相同存储类的变量,auto只能用在函数内,即auto只能修饰局部变量

### register存储类

register用于定义存储在寄存器中而不是RAM中的局部变量.这意味着变量的最大尺寸等于寄存器的大小,切不能对它应用一元的 & 运算符

```c
{
    register int miles;
}
```

寄存器只用于需要快速访问的变量,比如计数器.注意:定义register并不意味着变量将被存储在寄存器中,他意味着变量可能存储在寄存器中,这取决于硬件和实现的限制.

### static存储类

static存储类指示编译器在程序的生命周期内保持局部变量的存在,而不需要在每次他进入和离开作用域时进行创建和销毁.因此使用static修饰局部变量可以在函数调用之间保持局部变量的值.

static修饰符也可应用于全局变量.当static修饰全局变量时,会使变量的作用域限制在声明它的文件内

全局声明的一个static变量或方法可以被任何函数或方法调用,只要这些方法出现在根static变量或方法同一个文件中.

```c
#include <stdio.h>

void fun1(void);

static int count = 10;	//全局变量

int main()
{
    while(count--){
        fun1();
    }   
    return 0;
}

void fun1(void)
{
    static int thing = 5;
    thing ++;
    printf("thing shi %d,count shi %d",thing,count);
}
```

### extern存储类

extern存储类用于提供一个全局变量的引用,全局变量对所有的程序文件都是可见的.当使用extern时,对于无法初始化的变量,会把变量指向一个之前定义过的存储位置.

当有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时,可以在其他文件中使用extern中来得到已定义的变量或函数的引用.

extern是用来在另一个文件中声明一个全局变量或函数.

extern修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候

main.c

```c
#include <stdio.h>
int count;
extern void write_extern();

int main()
{
    count =5;
    write_extern();
}
```

support.c

```c
#include <stdio.h>

extern int count;
void write_extern(){
    printf("count is %d\n",count);
}
```

## C运算符

### 算术运算符

```txt
+ - * / % ++ --
```

### 关系运算符

```txt
==  !=  >  <  >=  <=
```

### 逻辑运算符

```txt
&&  ||  !
```

### 位运算符

```txt
&   |   ^
```

### 赋值运算符

```txt
=   +=   -=   *=   /=   %=   <<=   >>=   &=  ^=  |=
```

### 杂项

| 运算符 | 描述           | 实例                    |
| ------ | -------------- | ----------------------- |
| sizeof | 返回变量的大小 | sizeof(a)返回4,a是整数  |
| &      | 返回变量的地址 | &a;将给出变量的实际地址 |
| *      | 指向一个变量   | *a;将指向一个变量       |
| ?:     | 条件表达式     | 三元表达式              |

```c
#include <stdio.h>

int main
{
	int a =4;
	short b;
	double c;
	int* ptr;
	
	ptr = &a;	//ptr现在包含'a'的地址
	*ptr		//又变成了a,值为4
}
```

## if

## for

### C函数

### 定义函数

- 返回类型:一个函数可以返回一个值.有些函数不返回值,在这种情况下,return void
- 函数名称:函数的实际名称.函数名和参数列表一起构成了函数签名
- 参数:参数就像是占位符.当函数被调用时,向参数传递一个值,这个值被称为实际参数.参数列表包括函数参数的类型,顺序,数量.参数是可选的,函数可能不包括参数
- 函数主体:函数主体包含一组定义函数指定任务的语句.

```c
int max(int num1,int num2)
{
    int result;
    if(num1 > num2){
        result = num1;
    }else{
        result = num2;
    }
    return result;
}
```

### 函数声明

函数声明会告诉编译器函数名称及如何调用函数.

在函数声明中,参数名称不重要,只有参数类型是必须的.

```c
int max(int num1,int num2);
int max(int ,int);
```

当你在一个源文件中定义函数且在另一个文件中调用函数时,函数声明时必须的.

在这种情况下,你应该在调用函数的文件顶部声明函数.

### 调用函数

### 函数参数

形参  引用

## C作用域规则

作用域是程序中定义的变量所存在的区域,超过该区域变量就不能被访问.c中有三个地方可以声明变量

- 在函数或块内部的局部变量
- 在所有函数外部的全局变量
- 在形式参数的函数参数定义中

### 局部变量

### 全局变量

###  形式参数

> 全局变量与局部变量在内存中的区别:
>
> - 全局变量保存在内存的全局存储区中,占用静态的存储单元
> - 局部变量保存在栈中,只有在所在函数被调用时才动态地为变量分配存储单元

### 变量初始化

| 数据类型 | 初始化默认值 |
| -------- | ------------ |
| int      | 0            |
| char     | '\0'         |
| float    | 0            |
| double   | 0            |
| pointer  | NULL         |

## C数组

### 声明数组

```c
double balance[10];
```

### 初始化数组

```c
double balance[5] = {1.1,2.2,3.3,4.4,5.5};
double balance[] = {1.1,2.2,3.3,4.4,5.5};
```

### 访问数组元素

```c
balance[4]
```

## C enum枚举

一个星期7天

```c
enum DAY
{
	MON=1,TUE,WED,TRU,FRI,SAT,SUN
}
```

- 第一个枚举成员默认值为整形0,后续枚举成员的值在前一个成员上加1

- 上述的值为  1,2,3,4,5,6,7

- ```c
  enum season
  {
  	spring,summer=3,autumn,winter
  }
  这里的四个值分别我为 0,3,4,5
  ```

### 枚举变量的定义

- 先定义类型,在定义变量

  ```c
  enum DAY
  {
  	MON,TUE..
  }
  enum DAY day;
  ```

- 定义类型同时定义变量

  ```c
  enum DAY
  {
  	MON,TUE...
  } day;
  ```

- 省略枚举名称,直接定义变量

  ```c
  enum{
      MON,TUE...
  } day;
  ```

- 在c语言中,枚举类型是被当做int类处理的.所以按照c语言规范是没有办法遍历枚举类型的.

### 将整数转换为枚举

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum Day
    {
        sat,
        sun,
        mon,
        ...
    } workday;
	int a = 1;
    enum Day weekend;
    weekend = (enum Day)a;	//类型转换
    
}
```

## C指针

每一个变量都有一个内存位置,每一个内存位置都定义了可使用连字号&运算符访问的地址,它表示了在内存中的一个地址.

```c
#include <stdio.h>

int main()
{
    int var1;
    char var2[10];
    
    printf("var1 变量地址 : %p \n",&var1);
    printf("var2 变量地址 : %p \n",&var2);
    
    return 0;
}
```

### 什么是指针

指针是一个变量,其值为另一个变量的地址.即,内存位置的直接地址...就像其他变量或常量一样,你必须在使用指针存储其他变量地址之前,对其进行声明.

```c
int *aa;	//一个整形的指针
double *dd;	//一个double型的指针
float *ff;	//一个float型的指针
char *ch;
```

所有指针的值的实际数据类型,不管是整型,浮点,字符还是其他数据类型,都是一样的,都是一个代表内存地址的长的十六进制数.不同数据类型指针唯一的区别是,指针所指向的变量或常量的数据类型不同.

### 如何使用指针

定义一个指针变量,把变量地址赋值给指针,访问指针变量可用地址的值.这些是通过使用一元运算符 * 来返回位于操作数所指定的变量的值

```c
#include <stdio.h>

int main()
{
    int var = 20;	//实际变量
    int *ip;		//指针变量
    ip = &var;		//在指针变量中村var的地址
    
    //使用指针访问值
    *ip  
    
}
```

### C中的NULL指针

在变量声明的时候,如果没有确切的地址可以赋值,为指针赋值一个NULL值是一个好习惯.赋值为NULL的指针被称为空指针.

NULL指针是一个定义在标准库中的值为零的常量.

```c
#include <stdio.h>

int main()
{
    int *ptr = NULL;
    printf("ptr 的地址是 %p \n",ptr);
    return 0;
}

//打印 0x0
```

如需检查一个空指针

```c
if(ptr)	//如果p非空,
```

### C函数指针

函数指针是指向函数的指针变量.

通常我们说的指针变量时指向一个整数,字符型,或数组等变量,而函数指针是指向函数.

函数指针可以向一般函数一样,用于函数调用,传递参数.

函数指针声明

```c
typedef int (*fun_ptr)(int ,int)	//声明一个指向同样参数,返回值的函数指针类型
```

```c
#include <stdio.h>

int max(int x,int y)
{
    return x>y?x:y;
}

int main()
{
    //p是函数指针
    int (*p)(int ,int) = &max;	//&可以省略
    int a,b,c,d;
    
    //与直接调用函数等价 d = max(max(a,b),b);
    d = p(p(a,b),c);
    
    return 0;
}
```

### 回调函数

#### 函数指针作为某个函数的参数

函数指针变量可以作为某个函数的参数来使用的,回调函数就是一个通过函数指针调用的函数.

简单讲:回调函数是由别人的函数执行时调用你实现的函数

#### 实例

实例中pop函数定义了三个参数,其中第三个参数是函数的指针,通过该函数类设置数组的值.

实例中我们定义了回调函数getNext,他返回一个随机值,他作为一个函数指针传递为pop函数

pop将调用10次,并将回调函数的返回值赋值给数组

```c
#include <stdio.h>
#include <stdlib.h>

//回调函数
void pop(int *array,size_t arraySize,int (*getNext)(void))
{
    for(size_t=0;i<arraySize;i++){
        array[i]=getNext();
    }
}

//获取随机值
int getNext(void){
    return rand();
}

int main(void)
{
    int myarray[10];
    pop(myarray,10,getNext);
    for(int i=0;i<10;i++)
    {
        printf("%d ",myarray[i]);
    }
    printf("\n");
    return 0;
}
```

## C字符串

在C语言中,字符串实际上是使用null字符'\0'终止的一维字符数组.因此一个以null结尾的字符串,包含了组成字符串的字符.

```c#
char geeeting[6] = {'H','E','E','L','a','\0'};
char geeeting[] = "HEEla";		//两个等效
```

编译器会在初始化数组时,自动把'\0'放在字符串的末尾.

```c
#include <stdio.h>

int main()
{
    char gett[6] = {'H','e','l','l','o','\0'};
    printf("gett message : %s\n",gett);
    return 0;
}
```

### 字符串的函数

| 函数          | 功能                                                  |
| ------------- | ----------------------------------------------------- |
| strcpy(s1,s2) | 复制字符串s2到字符串s1                                |
| strcat(s1,s2) | 连接字符串s2到字符串s1的结尾                          |
| strlen(s1)    | 返回字符串s1的长度                                    |
| strcmp(s1,s2) | 如果s1和s2相同,返回0,如果s1<s2,返回负数,反之返回正数  |
| strchr(s1,ch) | 返回一个指针,指向字符串s1中字符ch的第一次出现的位置   |
| strstr(s1,s2) | 返回一个指针,指向字符串s1中字符串s2的第一次出现的位置 |

## C结构体

c数组允许定义可存储相同类型数据项的变量,结构是c编程中另一种用户自定义的可用的数据类型,他允许你存储不同类型的数据项.

结构用于表示一条记录

### 定义结构

为了定义结构,必须使用struct语句,struct语句定义了一个包含多个成员的新的数据类型,struct语句的格式:

```c
struct Books{
    char title[30],
    char author[20],
    int book_id;
    ...
} book;
```

一般情况下,

```c
//此声明声明了拥有3个成员的结构体,分别为整型的a,字符型的b和双精度的c
//同时又声明了结构体变量s1
//这个结构体并没有表明其标签
struct 
{
    int a;
    char b;
    double c;
} s1;

//此声明声明了拥有3个成员的结构体,...
//结构体的标签被命名为SIMPLE,没有声明变量
struct SIMPLE
{
    int a;
    char b;
    double c;
};
//用SIMPLE标签的结构体
struct SIMPLE t1,t2[11],*t3;

//也可以用typedef创建新类型
typedef struct
{
    int a;
    char b;
    double c;
} Simple2;
//现在可以用Simple2作为类型声明新的结构体变量
Simple2 u1,u2[11],*u3;
```

在上面的声明中,第一个和第二个声明被编译器当做两个完全不同的类型,即时他们的成员列表是一样的.如果令t3=&s1,是非法的.

结构体的成员可以包含其他结构体,也可以包含指向自己结构体类型的指针,而通常这种指针的应用是为了实现一些更高级的数据结构如链表和树等.

```c
//此结构体的声明包含了其他结构体
struct COMPLEX
{
    char string[100];
    struct SIMPLE a;
}

//子结构体的声明包含了指向自己类型的指针 
struct NODE
{
    char string[100];
    struct NODE *next_node;
}
```

如果两个结构体互相包含，则需要对其中一个结构体进行不完整声明。

```c
struct B;	//对结构体B进行不完整声明

//结构体A中包含之指向结构体B的指针
struct A
{
    struct B *partner;
    //sss
}

//结构体B中包含结构体A的指针，在A声明完后，B也随之进行声明
struct B
{
    struct A *partner;
    //sss
}
```

### 结构体变量的初始化

和其他类型变量一样，对结构体变量可以在定义时指定初始值

```c
#include <stdio.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} book = {"cyuyan","zhouleisn","bianchengyuyan",123};

int main()
{
    printf("title:%s\nauthor:%s\nsubject:%s\nbook_id:%d\n",book.title,
          book.author,book.subject,book.book_id);
}
```

### 访问结构成员

为了访问结构的成员，我们使用成员访问运算符 .    , 成员访问运算符是结构变量名称和我们要访问的结构成员之间的一个句号。你可以使用struct关键字来定义结构类型的变量

```c
#include <stdio.h>
#include <string.h>

struct Book
{
  	char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main()
{
 	struct Book book1;
    struct Book book2;
    
    strcpy(book1.title,"title1");
    strcpy(book1.author,"author1");
    strcpy(book1.subject,"subject1");
    book1.book_id = 123;
    
    strcpy(book2.title,"title2");
    strcpy(book2.author,"author2");
    strcpy(book2.subject,"subject2");
    book2.book_id = 456;
}
```

### 结构作为函数参数

你可以把结构作为函数参数，传参方式与其他类型的变量或指针类似。

```c
#include <stdio.h>
#include <string.h>

struct Book
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
}

//函数声明
void printBook(struct Book book);

int main(){
    struct Book book1;
    struct Book book2;
    
    strcpy(book1.title,"title1");
    strcpy(book1.author,"author1");
    strcpy(book1.subject,"subject1");
    book1.book_id = 123;
    
    strcpy(book2.title,"title2");
    strcpy(book2.author,"author2");
    strcpy(book2.subject,"subject2");
    book2.book_id = 456;
    
    printBook(book1);
    printBook(book2);
    
    return 0;
    
}

void printBook(struct Book book)
{
    printf("book title : %s \n",book.title);
    printf("book author : %s \n",book.author);
    printf("book subject : %s \n",book.subject);
    printf("book book_id : %d \n",book.book_id);
}
```

### 指向结构的指针

你可以定义指向结构的指针，方式与定义指向其他类型的指针相似。

```c
struct Book *pointer;
```

你可以在上述定义的指针变量中存储结构变量的地址。为了查找结构变量的地址

```c
pointer = &book1;
```

为了使用指向该结构的指针访问结构的成员，你必须使用 -> 运算符

```c
pointer -> title
```

```c
#include <stdio.h>
#include <string.h>

struct Book
{
    char title[50];
    char author[50];
    char subject[100];
    int book_Id;
}

void printBook(struct Book * book);

int main()
{
    struct Book book1;
    struct Book book2;
    
    strcpy(book1.title,"title1");
    strcpy(book1.author,"author1");
    strcpy(book1.subject,"subject1");
    book1.book_id =123;
    strcpy(book2.title,"title2");
    strcpy(book2.author,"author2");
    strcpy(book2.subject,"subject2");
    book2.book_id =465;
    
    printBook(&book1);
    printBook(&book2);
    
    return 0;
}

void printBook(struct Book *book)
{
    printf("book title is %s \n",book -> title);
       printf("book author is %s \n",book -> author);
       printf("book subjcet is %s \n",book -> subjcet);
       printf("book book_id is %d \n",book -> book_id);
}
```

### 位域

有些信息在存储时，并不需要占用一个完整的字节，而只需占几个或一个二进制位。例如在存放一个开关量时，只有0和1两种状态，用1位二进制即可。为了节省存储空间，并使处理简单，c语言提供了一种数据结构，成为位域或位段。

所谓位域是把一个字节中的二进位划分为几个不同的区域，并说明每个区域的位数。每个域有一个域名，允许在程序中按域名进行操作。这样就可以把几个不同的对象用一个字节的二进制位域来表示。

- 用1位而今为存放一个开关量，只有0和1两种状态
- 读取外部文件格式----可以读取非标准的文件格式，例如：9位的整数。

#### 位域的定义和位域变量的说明

位域定义与结构定义相仿，其形式为：

```c
struct 位域结构名
{
    位域列表
}；
```

其中位域列表的形式为

```c
类型说明符 位域名： 位域长度
```

```c
struct bs
{
    int a:8;
    int b:2;
    int c:6;
} data;
```

说明data为bs变量，共占两个字节。其中位域a占8位，位域b占2位，位域c占6位。

```c
struct packed_struct
{
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int f4:1;
    unsigned int type:4;
    unsigned int my_int:9;
} pack;
```

在这里，packed_struct包含了６个成员，四个１位的标识符，一个４位的type，和一个９位的my_int。

#### 对于位域的定义尚有以下几点说明

- 一个位域存储在同一个字节中，如一个字节所剩空间不够存放另一个位域时，则会从下一单元起存放该位域。也可以有意使某位域从下一单元开始

  ```c
  struct bs
  {
      unsigned a:4;
      unsigned  :4;	//空域
      unsigned b:4;	//从下一单元开始存放
      unsigned c:4;
  }
  ```

  在这个位域定义中,a占第一个字节的4位,后4位填0表示不使用,b从第二字节开始,占用4位,c占用4位.

- 由于位域不允许垮两个字节,因此位域的长度不能大于一个字节的长度,也就是说不能超过8位二进位.如果最大长度大于计算机的整数字长,一些编辑器可能会允许域的内存重叠,另外一些编译器可能会把大于一个域的部分存储在下一个字节中.

- 位域可以是无名位域,这是它只用来作填充活调整位置,无名的位域是不能使用的.

  ```c
  struct k
  {
      int a:1;
      int  :2;
      int b:3;
      int c:2;
  }
  ```

  从以上分析看,位域在本质上就是一种结构类型,不过其成员是按二进制位分配的.

#### 位域的使用

位域的使用和结构成员的使用相同

位域允许用各种格式输出

```c
main()
{
    struct bs
    {
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
        
    } bit ,*pbit;
    
    bit.a = 1;
    bit.b = 7;
    bit.c = 15;
    
    pbit = &bit;
    pbit -> a = 0;
    pbit -> b &= 3;
    pbit -> c |= 1;
    
}
```

## C共用体

共用体是一种特殊的数据类型,允许你在相同的内存位置存储不同的数据类型.你可以定义一个带有多成员的共同体,但是任何时候只能有一个成员带有值.共同体提供了一种使用相同的内存位置的有效方式.

### 定义共同体

为了定义共同体,你必须使用union语句,方式与定义结构类似.union语句定义了一个新的数据类型,带有多个成员,

```c
union Data
{
	int i;
	float f;
	char str[20];
} data;
```

Data类型的变量可以存储一个整数,一个浮点数或者一个字符串,这意味着一个变量(相同的内存位置)可以存储多种类型的数据.你可以根据需要在一个共同体内使用任何内置的或者用户自定义的数据类型

共同体占用的内存应足够存储共同体中最大的成员.如上,Data讲占用20个字节的内存空间,因为在各个成员中,字符串所占用的空间是最大的.

```c
#include <stdio.h>
#include <string.h>

union Data
{
	int i;
	float f;
	char str[20];
};

int main
{
	union Data data;
	printf("memory size by data :%d\n",sizeof(data));
	
	return 0;
}
```

访问共同体成员

```c
#include <stdio.h>
#include <string.h>

union Data
{
int i;
float f;
char str[20];
};

int main{
  union Data data;
    data.i=10;
    data.f=220.5;
    strcpy(data.str,"C programming");
 	
    printf("data.i:%d\n",data.i);
    printf("data.f:%d\n",data.f);
    printf("data.str:%s\n",data.str);
    
    return 0;
}
```

这里打印i和f的值会出现错误,因为最后赋值的变量占用了内存位置,只有str能够完整输出

```c
#include <stdio.h>
#include <string.h>

union Data
{
int i;
float f;
char str[20];
};

int main{
  union Data data;
    data.i=10;
     printf("data.i:%d\n",data.i);
    
    data.f=220.5;
     printf("data.f:%d\n",data.f);
    
    strcpy(data.str,"C programming");
 	printf("data.str:%s\n",data.str);
    
    return 0;
}
```

这里打印的都是正确的,因为同一时间只用到一个成员.

## C typedef

c语言提供了typedef关键字,你可以使用它来为类型取一个新的名字,

```c
typedef unsigned char AAD;
```

在这个定义之后,标识符AAD可作为类型unsigned char 的缩写

```c
AAD b1,b2;
```

按照惯例,定义时会大写字母,以便提醒用户类型名称是一个象征性的缩写.你可以用typedef来Wie用户自定义的数据类型取一个新的名字.

```c
#include <stdio.h>
#include <string.h>

typedef struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} Book;

int main()
{
    Book book;
    
    strcpy(book.title,"title1");
    strcpy(book.author,"author1");
    strcpy(book.subjcet,"subjcet1");
    book.book_id = 123;
    
    return 0;
}
```

### typedef VS #define

#define是c指令,用于为各种数据类型定义别名,与typedef类似,但是他们有几个不同点

- typedef仅限于为类型定义符号名称,#define不仅可以为类型定义别名,也能为数值定义别名,比如定义1为ONE
- typedef是由编译器执行解释的,#define语句是由预编译器进行处理的

```c
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(){
    printf("TRUE 值为 %d\n",TRUE);
    printf("FALSE 值为 %d\n",FALSE);
    return 0;
}
```

