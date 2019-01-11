## C输入&输出

当我们提到输入时,这意味着要向程序填充一些数据.输入可以是以文件的形式或从命令行中进行.C语言提供了一系列内置的函数来读取给定的输入,并根据需要填充到程序中.

当我们提到输出时,这意味着要在屏幕上,打印机上火任意文件中显示一些数据.C语言提供了一系列内置的函数来输出数据到计算机屏幕上和保存数据到文本文件或二进制文件中.

### 标准文件

C语言吧所有的设备都当做文件.所以设备被处理的方式与文件相同.以下三个文件会在程序执行时自动打开,以便访问键盘和屏幕

| 标准文件 | 文件指针 | 设备     |
| -------- | -------- | -------- |
| 标准输入 | stdin    | 键盘     |
| 标准输出 | stdout   | 屏幕     |
| 标准错误 | stderr   | 你的屏幕 |

文件指针是访问文件的方式,

C语言中的I/O通常使用printf和scanf两个函数

scanf函数用于从标准输入读取并格式化,printf函数发送格式化输出到标准输出

```c
#include <stdio.h>
int main()
{
    printf("asda");
    return 0;
}
```

解析:

- 所有的C语言程序都需要包含main函数,代码从main函数开始执行
- printf用于格式化输出到屏幕,printf函数在stdio.h头文件中声明
- stdio.h是一个头文件and #include是一个预处理命令.用来引入头文件.当编译器遇到printf函数时,如果没有找到stdio.h,会发生编译错误
- return 0,语句用于表示退出程序

### %d格式化输出整数

```c
#include <stdio.h>

int main()
{
    int testInt = 5;
    printf("number = %d\n",testInt);
    return 0;
}
```

### %f格式化输出浮点型数据

```c
#include <stdio.h>

int main()
{
    float f;
    printf("Enter a number:");
    scanf("%f",&f);
    printf("Value = %f",f);
    return 0;
}
```

### getChar 和 putChar 函数

getchar函数从屏幕读取下一个可用的字符,并把它返回为一个整数.这个函数在同一个时间内只会读取单一的字符.你可以在循环内使用这个方法,以便从屏幕上读取多个字符.

putChar函数把字符输出到屏幕上,并返回相同的字符.这个函数在同一个时间内只会输出一个单一的字符.你可以在循环内使用这个方法,以便在屏幕上输出多个字符.

### gets 和 puts 函数

char *gets(char *s) 函数从stdin读取一行到s所指向的缓冲区,知道一个终止符或EOF.

int puts(const char *s)函数把字符串s和一个尾随的换行符写到stdout

```c
#include <stdio.h>

int main()
{
    char str[100];
    
    printf("Enter a value :");
    gets(str);
    
    printf("\nyou entered:");
    puts(str);
    
    return 0;
}
```

### scanf 和 printf 函数

int scanf(const char *format,...)函数从标准输入流stdin读取输入,并根据提供的format来浏览输入

int printf(const char *format,...)函数把输出写入标准输出流stdout,并根据提供的格式产生输出.

format可以是一个简单的常量字符串,但你可以指定%s,%d,%c,%f等来输出或读取字符串,整数,字符或浮点数.

```c
#include <stdio.h>

int main()
{
    char str[100];
    int i;
    
    printf("Enter a value:");
    scanf("%s %d",str,&i);
    
    printf("\n You entered:%s %d ",str,i);
    printf("\n");
    
    return 0;
}
```

## C文件读写

如何创建,打开,关闭文本文件或二进制文件

一个文件,无论他是文本文件还是二进制文件,都是代表了一系列的字节.c语言不仅提供了访问顶层的函数,也提供了底层调用来处理存储设备上的文件.

### 打开文件

你可使用fopen函数来创建一个新的文件或者打开一个已有的文件,这个调用会初始化类型FILE的一个对象,类型FILE包含了所有用来控制流的必要的信息.

```c
FILE *fopen (const char * filename,const char * mode);
```

在这里filename是字符串,用来命名文件,访问模式mode的值可以是下列值中的一个:

| 模式 | 描述                                                         |
| ---- | ------------------------------------------------------------ |
| r    | 打开一个已有的文本文件,允许读取文件                          |
| w    | 打开一个文本文件,允许写入文件.如果文件不存在,则会创建一个新文件.在这里,你的程序会从文件的开头写入内容.如果文件存在,则会被截断为零长度,重新写入 |
| a    | 打开一个文本文件,已追加模式写入文件.如果文件不存在,则会创建一个新文件.在这里,你的程序会在已有的文件内容中追加内容 |
| r+   | 打开一个文件,允许读写                                        |
| w+   | 打开文件,允许读写.如果文件存在,先清空.如果不存在,会创建新文件 |
| a+   | 打开文本文件,允许读写.如果文件不存在,创建新文件.如果文件已存在,写入是追加模式. |

如果是二进制文件,则需使用下面的访问模式

```c
"rb" "wb" "ab" "rb+" "r+b" "wb+" "w+b" "ab+" "a+b"
```

### 关闭文件

为了关闭文件,使用fclose函数

```c
int fclose(FILE *fp)
```

如果成功关闭文件,fclose返回0,如果关闭发生错误,函数返回EOF..这个函数实际上,会清空缓冲区中的数据,关闭文件,并释放用于该文件的所有内存.EOF是一个定义在头文件stdio.h中的常量

C标准库提供了各种函数来按字符或者以固定长度字符串的形式读写文件

### 写入文件

下面是吧字符写入到流中的最简单的函数

```c
int fputc(int c,FILE *fp);
```

函数fput把参数c的字符值写入到fp所指向的输出流中.如果写入成功,他会返回写入的字符,如果发生错误,则会返回EOF.你可以使用下面的函数把一个以null结尾的字符串写入到流中:

```c
int fputs(const char *s,FILE *fp);
```

函数fputs把字符串s写入到fp所指向的输出流中.如果写入成功,他会返回一个非负值,如果发生错误,则会返回EOF.你可以使用int fprintf(FILE *fp,const char *format,...)函数来写把一个字符串写入到文件中

```c
#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    
    fp = fopen("D:/tmp/test.txt","w+");
    fprintf(fp,"this is testing for printf...\n");
    fputs("this is testing for fputs...\n",fp);
    fclose(fp);
}
```

### 读取文件

下面是从文件读取单个字符

```c
int fgetc(FILE * fp);
```

fgetc函数从fp所指向的输入文件中读取一个字符 .返回值是读取的字符,如果发生错误,返回EOF.

下面是读取一个字符串

```
char *fgets(char *buf,int n,FILE *fp)'
```

函数fgets从fp所指向的输入流中读取n-1个字符.他会把读取的字符串赋值到缓冲区buf,并在最后追加一个null字符来终止字符串

如果这个函数在读取最后一个字符之前就遇到一个换行符'\n'或文件的末尾EOF,则只会返回读取到的字符,包括换行符.

你可以使用int fscanf(FILE * fp,const char *format,...)函数来从文件中读取字符串,但是遇到第一个空格字符时,他会停止读取.

```c
#include <stdio.h>
int main()
{
    FILE *fp = NULL;
    char buff[255];
    
    fp = fopen("D:/test/test.txt","r");
    fscanf(fp,"%s",buff);
    printf("1:%s\n",buff);
    
    fgets(buff,255,fp);
    printf("2:%s\n",buff);
    
    fgets(buff,255,fp);
    printf("3:%s\n",buff);
    
    fclose(fp);
    
    return 0;
}
```

上面代码执行时

```c
1:This
2:is testing for fprintf

3:this is testing for fputs

```

首先,fscanf方法只读取了this,因为他在后边遇到一个空格,其次小勇fgets读取剩余部分,知道行尾,最后调用fgets完整读取第二行

### 二进制IO函数

```c
size_t fread(void *ptr,size_t size_of_elements,
            size_t number_of_elements,FILE *a_file);

size_t fwrite(const void *ptr,size_t size_of_elements,
            size_t number_of_elements,FILE *a_file);
```

这两个函数都是用于存储快的读写 - 通常是数组或结构体.

## C预处理器

C预处理器不是编译器的组成部分,但是它是编译过程中一个单独的步骤.c预处理器只不过是一个文本替换工具而已,他们会指示编译器在实际编译之前完成所需的预处理.我们将把c预处理器简写为cpp

所有的预处理器命令都是以#开头,他必须是第一个非空字符,为了增强可读性,预处理器指令应从第一列开始.

| 指令     | 描述                                            |
| -------- | ----------------------------------------------- |
| #define  | 定义宏                                          |
| #include | 包含一个源代码文件                              |
| #undef   | 取消已定义的宏                                  |
| #ifdef   | 如果宏已经定义,则返回真                         |
| #ifndef  | 如果宏没有定义,则返回真                         |
| #if      | 如果给定条件为真,则编译下面代码                 |
| #else    | #if的替代方案                                   |
| #endif   | 结束一个#if...#else条件编译块                   |
| #error   | 当遇到标准错误时,输出错误消息                   |
| #pragma  | 使用标准化方法,向编译器发布特殊的命令道编译器中 |

### 预处理器实例

分析下面的实例来理解不同的指令

```c
#define MAX_ARRAY_LENGTH 20
```

这个指令告诉CPP把所有的MAX_ARRAY_LENGTH替换为20.使用#define定义常量来增强可读性

```c
#include <stdio.h>
#include "myheader.h"
```

这些指令告诉cpp从系统库中获取stdio.h,并添加文本到当前源文件中.下一行告诉cpp从本地目录中获取myheader.h,并添加内容到当前的源文件中

```c
#undef FILE_SIZE
#define FILE_SIZE 42
```

这个指令告诉cpp取消已定义的FILE_SIZE,并定义它位42

```c
#ifndef MESSAGE
	#define MESSAGE "ads"
#endif
```

这个指令告诉cpp只有当MESSAGE为定义时,才定义MESSAGE

```c
#ifdef DEBUG
	..sdfdf
#endif
```

这个指令告诉cpp,如果定义了DEBUG,则执行处理语句.在编译时,如果你向gcc编译器传递了 --DEBUG 开关量,这个指令就非常有用.它定义了DEBUG,你可以在编译期间随时开启或关闭调试.

### 预定义宏

ANSI C 定义了许多宏.你可以使用这些宏,但不能修改这些预定义的宏.

| 宏        | 描述                                     |
| --------- | ---------------------------------------- |
| \__DATA__ | 当前日期,以MMM DD YYYY格式表示的字符常量 |
| \__TIME__ | 当前时间,以HH:MM:SS格式                  |
| \__FILE__ | 包含当前文件名.                          |
| \__LINE__ | 包含当前行号,一个十进制常量              |
| \__STDC__ | 当编译器以ANSI标准编译时,则为1           |

### 预处理运算符

C预处理提供了下列的运算符来帮助你创建宏

#### 宏延续运算符

一个宏通常写在一个单行上,但是如果宏太长,一个单行容纳不下,则使用宏延续运算符 \

```c
#define message_for(a,b) \
	printf(#a " and " #b ":We love you!|n")
```

#### 字符串长两化运算符 #

在宏定义中,当需要把一个宏的参数转换为字符串常量时,则使用字符串常量化运算符 #,在宏中使用的该运算符有一个特定的参数或参数列表

```c
#include <stdio.h>

#define message_for(a,b) \
	printf(#a "and " #b ":fsdfdfdf");

int main()
{
    message_for(CAsds,fdfdf);
    return 0;
}
```

#### 标记粘贴运算符 ##

宏定义内的标记粘贴运算符 ##  会合并两个参数.它允许在宏定义中两个独立的标记被合并为一个标记.

```c
#include <stdio.h>

#define tokenpaster(n) printf ("token" #n " =%d",token##n);

int main(){
    int token23 = 22;
    tokenpaster(23);
    
    return 0;
}
```

当上面的代码编译执行

```
token23 = 22
```

这个实例会从编译器产生下列的实际输出

```c
printf("token23 = %d",token23);
```

这个实例演示了token##n会连接到token23中,在这里我们使用了字符串长两化运算符#和标记粘贴运算符##.

#### defined运算符,

预处理器defined运算符是用在常量表达式中的,用来确定一个标识符是否已经使用过#define定义过.如果指定的标识符已定义,则值为真.如果指定的标识符为定义,则值为假.

```c
#include <stdio.h>

#if !defined(MESSAGE)
	#define MESSAGE "sdfs"
#endif

int main(){
    printf("Herer is the message : %s\n",MESSAGE);
    
    return 0;
}
```

### 参数化的宏

CPP一个强大的功能是可以使用参数化的宏来模拟函数.

```c
int suqare(int x)
{
    return x*x;
}
```

我们可以使用宏重写上面的代码

```c
#define square(x)((x)*(x))
```

在使用带有参数的宏之前,必须使用#define指令定义.参数列表是在括号内,且必须金粉在宏名称的后边.宏名称和参数间不能有空格

```c
#include <stdio.h>

#define MAX(x,y) ((x)>(y)?(x):(y))

int main(){
    printf("max bewrfsd %d\n",MAX(10,20));
    return 0;
}
```

## C头文件

头文件是扩展名.h的文件,包含了c函数声明和宏定义,被多个源文件中引用共享.有两种类型的头文件:程序员编写的头文件和编译器子代的头文件.

在程序中要使用头文件,需要使用c预处理指令#include来引用它.前面我们已经看过stdio.h头文件,它是编译器子代的头文件

引用头文件相当于复制头文件中的内容,但是我们不会直接在源文件中复制头文件的内容,因为这么做容易出错,特别在程序是由多个源文件组成的时候

建议吧所有的常量,宏,系统全局变量,和函数原型写在头文件中,在需要的时候随时引用这些头文件

### 引用头文件的语法

```c
#include <file>
```

这种形式用于引用系统头文件,

```c
#include "file"
```

这种形式用于引用用户头文件.

### 引用头文件的操作

\#include 指令会指示c预处理器浏览指定的文件作为输入.预处理器的输出包含了已经生成的输出,被引用文件生成的输出以及#include指令之后的文本输出.

header.h

```c
char *test(void);
```

和一个使用了头文件的程序 program.c

```c
int x;
#include "header.h";

int main()
{
    puts(test());
}
```

编译器会看到如下代码信息

```c
int x;
char *test();

int main(){
    puts(test());
}
```

### 只引用一次头文件

如果一个头文件被引用两次,编译器会处理两次头文件的内容,这将产生错误.

```
#ifndef HEADER_FILE
#define HEADER_FILE
	..,
#endif
```

这种结构就是通常所说的包装器#ifdef,当再次引用头文件时,条件为假,

#### 有条件引用

有时需要从多个不同的头文件中选择一个引用到程序中.需要制定在不同操作系统上的配置参数.

```
#if SYSTEM_1
	#include "system1.h"
#elif SYSTEM_2
	#include "system2.h"
#elif ...
	...
#endif
```

但是头文件比较多的时候,这么做是很不妥当的,预处理器使用宏来定义头文件的名称.这就是所谓的有条件引用.

他不是用头文件的名称作为\#include的直接参数,你只需要使用宏名称代替即可

```c
#define SYSTEM_H "system1.h"
...
#include SYSTEM_H
```

## C强制类型转换

强制类型转换是把变量从一种类型转换为另一种数据类型.如果你向存储一个long类型的值到一个简单整型中,你需要把long,类型强制转换为int类型.你可以使用强制类型转换运算符来吧值显式的从一种类型转换为另一种类型.

```c
#include <stdio.h>

int main()
{
    int sum = 17,count = 5;
    double mean;
    
    mean = (double) sum /count;
    
    printf("value : %f\n",mean);
}
```

这里要注意的是强制类型转换运算符的优先级大于除法,因此sum的值首先被转为double,然后除以count,得到double

类型转换可以是隐式的,由编译器自动执行.

### 整数提升

整数提升是把小于int或unsigned int的整型类型转换为int或unsigned

```c
#include <stdio.h>

int main()
{
    int i =17;
    char c = 'c';		//ascii  --99
    int sum;
    
    sum = i+c;
    printf("value of sum : %d\n",sum);
}
```

## c错误处理

C语言不提供对错误处理的直接支持,但是作为一种编程语言,它以返回值的形式允许你访问底层数据.在发生错误时,大多数的c或unix函数调用返回1或NULL,同时会设置一个错误代码errno,该错误代码是全局变量,表示在函数调用期间发生了额错误.你可以在errno.h头文件中找到各种各样的错误码

所以,c程序员可以通过检查返回值,然后根据返回值决定采取哪种适当的动作.开发人员应该在程序初始化时,把errno设置为0,0表示程序中没有错误

### errno,perror,strerrpr

c语言提供了perror,strerror函数来显示与errno相关的文本信息

- perror函数显示你传给他的字符串,后跟一个冒号,一个空格和当前errno值的文本表示形式
- strerrpr函数,返回一个指针,支撑指向当前errno值文本表示的形式

让我们来模拟一种错误情况,尝试打开一个不存在的文件.你可以使用多种方式来输出错误消息,在这里我们使用函数来演示用法,另外有一点需要注意,你应该使用stderr文件流来输出所有的错误

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;
int main()
{
    FILE *fp;
    int errnum;
    fp = fopen("D:/test/ee.txt","rb");
    if(fp == NULL){
        errnum = errno;
        fprintf(stderr,"错误号%d\n",errno);
        perror("通过perror输出错误");
        fprintf(stderr,"打开文件错误:%s\n",strerror(errnum));
    }else{
        fclose(fp);
    }
    
    return 0;
}
```

### 被零除的错误

在进行除法运算时,如果不检查除数是否为零,则会导致一个运行时错误.

为了避免这种情况发生

```c
#include <stdio.h>
#include <stdlib.h>

main()
{
    int divider = 20;
    int divisor = 0;
    int quotient;
    if(divisor == 0)
    {
        fprintf(strerr,"除数为0退出运行\n");
        exit(-1);
    }else{
        quotient = divider /divisor;
        fprintf(strerr,"quotient 变量值为: %d\n",quotient);
        exit(0);
    }
}
```

### 程序退出状态

通常情况下,程序成功执行完一个操作正常退出的时候带有EXIT_SUCCESS.在这里,EXIT_SUCCESS是宏,它被定义为0.

如果程序中存在一种错误情况,当你退出程序时,会带有状态值,EXIT_FAILURE,被定义为-1,

```c
#include <stdio.h>
#include <stdlib.h>

main()
{
    int dividend = 20;
    int divisor = 5;
    int quotient;
    if(divisor == 0)
    {
        fprintf(stderr,"除数为0,退出..\n");
        exit(EXIT_FAILURE);
    }
    quotient = dividend / divisor;
    fprintf(stderr,"quotient 变量值为: %d\n",quotient);
    exit(EXIT_SUCCESS);
}
```

## C递归

递归值的是函数在定义中使用函数自身的方法

```c
void recursion()
{
    statements;
    ......
    recursion();
    ......
}

int main()
{
    recursion();
}
```

c语言支持递归,即一个函数可以调用其自身.但在使用递归的时候,你需要注意定义一个从函数退出的条件,负责会进入死循环.

递归函数在解决很多问题上起了至关重要的作用,阶乘,斐波那契数列.

### 数的阶乘

```c
#include <stdio.h>

double factorial(unsigned int i)
{
    if(i <= 1){
        return 1;
    }
    return i * factorial(i-1);
}

int main
{
int i = 15;
printf("%d 的阶乘为 %f \n",i,factorial(i));
return 0;
}
```

### 斐波那契数列

```c
#include <stdio.h>

int fibonaci(int i)
{
    if(i== 0){
        return 0;
        
    }
    if(i == 1){
        return 0;
           
    }
    return fibonaci(i-1) + fibonaci(i-2);
}

int main()
{
    int i;
    for(i = 0;i < 10;i ++){
        printf("%d\t\n",fibonaci(i));
    }
    
    return 0;
}
```

## C可变参数

有时,你可能碰到这种情况,你希望函数带有可变数量的参数,而不是预定义数量的参数,

c提供了解决方案,他允许你定义一个函数,能根据具体需求接收可变数量的参数

```c
int func(int ,...)
{
    .
        .
        .
}

int main()
{
    func(2,2,2);		//第一位表示参数的总数
    func(3,6,2,1);
}
```

注意:函数func最后一个参数写成省略号... , 省略号之前那个参数是int,代表了要传递的可变参数的总数.

使用这个功能,需要使用stdarg.h头文件,该文件提供了实现可变参数功能的函数和宏.

- 定义一个函数,最后一个参数为省略号,省略号前面可以设置自定义参数
- 在函数定义中创建一个va_list类型变量,该类型是在stdarg.h头文件中定义的
- 使用int参数和va_start宏来初始化va_list变量为一个参数列表.宏va_start是在stdarg.h头文件中定义的
- 使用va_arg宏和va_list变量来访问参数列表中的每个项
- 使用宏va_end来清理赋予va_list变量的内存

```c
#include <stdio.h>
#include <stdarg.h>

double average(int num,...){
    va_list valist;
    double sum = 0.0;
    int i;
    
    //初始化参数
    va_start(valise,num);
    //访问每个参数
    for(i=0;i<num;i++){
        sum += va_arg(va_list,int);
    }
    //清理内存
    va_end(valist);
    
    return sum/num;
}

int main(){
    printf("2,3,4,5 = %f\n",average(4,2,3,4,5));
    printf("5 10 15 = %f\n",average(3,5,10,15));
    return 0;
}
```

## C内存管理

c语言为内存的分配和管理提供了几个函数,stdlib.h

| 函数                                     | 描述                                                         |
| ---------------------------------------- | ------------------------------------------------------------ |
| void *calloc(int num,int size)           | 在内存中动态地分配num个长度为size的连续空间,并将每一个字节都初始化为0,所以它的结果是分配了num*size个字节长度的内存空间,并且每个字节的值都是0 |
| void free(void *address)                 | 该函数释放address所指向的内存块,释放的是动态分配的内存空间   |
| void *malloc(int num)                    | 在堆区分配一块指定大小的内存空间,用来存放数据.这块内存空间在函数执行完后不会被初始化,他们的值是未知的. |
| void *realloc(void *address,int newsize) | 该函数重新分配内存,把内存扩展到newsize                       |

注意:void *类型表示未确定类型的指针.void *类型可以通过类型转换强制转换为任何其他类型的指针

### 动态分配内存

如果你预先知道数组的大小,那么定义数组时就比较容易

```c
char name[100]
```

但是如果你预先不知道需要存储文本长度,这里我们需要定义一个指针,该指针指向未定义所需内存大小的字符,后续再根据需求来分配内存

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[100];
    char *description;
    
    strcpy(name,"asdasd");
    
    //动态分配内存
    description = (char *)malloc(200*sizeof(char));
    if(description == NULL)
    {
        fprintf(srderr,"ERROR unable to allocate required memory\n");
    }else{
        strcpy(description,"asdassdadsd");
    }
    printf("anne = %s\n",name);
    printf("des  : %s\n",description);
    
    return 0;
}
```

上面的程序也可以使用calloc

当动态分配内存时,你有完全控制权,可以传递任何大小的值.而那些预定义大小的数组,一旦定义无法改变大小

### 重新调整内存的大小和释放内存

当程序退出时,操作系统会自动释放所有分配给程序的内存,但是建议你在不需要内存时,应该调用free来释放内存.或者,你可以通过调用realloc来增加或减少已分配内存块的大喜爱哦.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[100];
    char * desc;
    
    strcpy(name,"sdfsdf");
    desc = (char *)malloc(20*sizeof(char));
    
    if(desc == NULL)
    {
        fprintf(stderr,"err");
    }else
    {
        strcpy(desc,"fsdfsfdf");
    }
    
    //如果要存储更大的描述信息
    desc = realloc(desc,100,sizeof(char));
    if(desc == NULL)
    {
        fprintf(stderr,"err");
    }else{
        strcat(desc,"zhuijia");
    }
    
    printf("name=%s\n",name);
    printf("desc=%s\n",desc);
    
    //释放内存
    free(desc);
    
    system("pause");
    
    return 0;
}
```

## C命令行参数

执行程序时,可以从命令行传值给c程序..这些值被称为命令行参数,他们对程序很重要.

命令行参数是使用main 函数参数来处理的,其中argc是指传入参数的个数,argv[]是一个指针数组,指向传递给程序的每个参数

```c
#include <stdio.h>

int main(int argc,char *argv[])
{
    //默认不传参数的值是1,argv[0]存储程序的名称
    if(argc == 2){
        printf("the argument supplied is %s\n",argv[1]);
    }else if(argc > 2){
        printf("too many arguments supplied.\n");
    }else{
        printf("one argument expected.\n");
    }
}
```

argv[0]存储程序的名称,argv[1]是一个指向第一个命令行参数的指针,

多个命令行参数之间用空格分隔.但是如果参数本身带有空格,那么传递参数的时候应把参数防止在双引号""或者单引号''内部.