## C++重载运算符和重载函数

c++允许在同一作用域中的某个函数和运算符指定多个定义,分别为函数重载和运算符重载.

重载声明是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明,但是它们的参数列表和定义不相同.

当你调用一个重载函数或重载运算符时,编译器通过把你所使用的参数类型与定义中的参数类型进行比较,决定选用最合适的定义.选择最合适的重载函数或重载运算符的过程,成为重载决策.

### c++中的函数重载

在同一个作用域内,可以声明几个功能类似的同名函数,但是这些同名函数的形式参数必须不同.你不能仅通过返回类型的不同来重载函数.

```c++
#include <iostream>
using namespace std;

class printData
{
    public:
    void print(int i){
        cout << "整数为:" << i << endl;
    }
    void print(double d){
        cout << "浮点数:" << d << endl;
    }
    void print(char c[]){
        cout << "字符串:" << c << endl;
    }
}

int main()
{
    printData pd;
    
    pd.print(5);
    pd.print(2.5);
    char c[] = "dfssfdf";
    pd.print(c);
    
    return 0;
}

```

### C++中的运算符重载

你可以重定义或重载大部分c++内置的运算符.这样你就能使用自定义类型的运算符.

重载的运算符是带有特殊名称的函数,函数名是由关键字operator和其后要重载的运算符符号构成的.与其他函数一样,重载运算符有一个返回类型和一个参数列表.

```c++
Box operator+(const Box&,const Box&);
```

下面实例使用成员函数演示了运算符重载的概念.对象作为参数进行传递,对象的属性使用this运算符进行访问.

```c++
#include <iostream>
using namespace std;

class Box{
    public :
    double getVolume(){
        return length*breadth*height;
    }   
    void setLength(double len){
        length = len;
    }
    void setBreadth(double bre){
        breadth = bre;
    }
    void setHeight(double hei){
        height = hei;
    }
    //重载 + 运算符,用于把两个box对象相加
    Box operator+(const Box& b){
        Box box;
        box.length = this -> length + b.length;
        box.height = this -> height + b.height;
        box.breadth = this -> breadth + b.breadth;
        return box;
    }
    
    private :
    double length;
    double breadth;
    double height;
}

int main()
{
    Box box1;
    Box box2;
    Box box3;
    
    double volume = 0.0;
    
    box1.setLength(6.0);
    box1.setBreadth(7.0);
    box1.setHeight(5.0);
    
     box1.setLength(11.0);
    box1.setBreadth(12.0);
    box1.setHeight(13.0);
    
    volume = box1.getVolume();
    cout << "volume of box1:" << volume << endl;
    
    volume = box2.getVolume();
    cout << "volume of box2 :" << volume << endl;
    
    box3 = box1 + box2;
    
    volume = box3.getVolume();
    cout << "volume of box3:" << volume << endl;
    
    return 0;
}
```

## C++多态

多态按字面的意思就是多种形态.当类之间存在层次结构,并且类之间是通过继承关联时,就会用到多态.

C++多态意味着调用成员函数时,会根据调用函数的对象的类型来执行不同的函数.

```c++
#include <iostream>
using namespace std;

class Shape{
    protected:
    int width,height;
    public:
    Shape(int a=0,int b=0){
        width =a ;
        height = b;
    }
    int area(){
        cout << "parent class area:" << endl;
        return 0;
    }
}

class Rectangle : public Shape{
        public :
        Rectangle(int a=0,int b=0):Shape(a,b){
            
        }
        int area()
        {
            cout << "rectangle class area:" << endl;
            return width*height;
        }
    }
    
class Triangle :public Shape{
    public:
    Triangle(int a=0,int b=0):Shape(a,b){

    }
    int area()
    {
        cout << "Triangle class area:" << endl;
        return width*height/2;
    }
}

int main(){
    Shape *shape;
    Rectangle rec(10,7);
    Triangle tri(10,5);
    
    shape = &rec;
    shape -> area();
    
    shape = &tri;
    shape -> area();
    
    return 0;
}
```

当上面代码编译执行时,会产生下列结果

```c++
parent class area
parent class area
```

导致输出错误的原因是,调用函数area被编译器设置为基类中的版本,这就是所谓的静态多态,或静态链接-函数调用在程序执行前就准备好了..有时候这也被称为早绑定.因为area函数在程序编译期间就已经设置好了.

```c++
class Shape{
    protected:
    int width,height;
    public :
    Shape(int a=0,int b=0){
        width =a ;
        height = b;
    }
    virtual int area(){
        cout << "parent class area:" << endl;
        return 0;
    }
}
```

修改后会产生以下结果

```c++
rectangle class area
triangle class area
```

此时,编译器看的是指针的内容,而不是他的类型.因此,由于tri和rec类的对象的地址存储在*shape中,所以会调用各自的area函数.

正如你看到的,每个子类都有一个函数area的独立实现.这就是多态的一般使用方式.有了多态,你可以有多个不同的类,都带有同一个名称但具有不同实现的函数,函数的参数甚至可以是相同的.

### 虚函数

虚函数 是在基类中使用关键字virtual声明的函数.在派生类中重新定义基类中定义的虚函数时,会告诉编译器不要静态链接到该函数.

我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数,这种操作被称为动态链接或后期绑定.

### 纯虚函数

你可能想要在基类中定义虚函数,以便在派生类中重新定义该函数更好地适用于对象,但是你在基类中又不能对虚函数给出有意义的实现,这时候就用纯虚函数

```c++
class Shape{
    protected:
    int width,height;
    public :
    Shape(int a=0,int b=0){
        width=a;
        height = b;
    }
    
    virtuel int area() =0;
    //=0告诉编译器,函数没有主题,上面的虚函数是纯虚函数
}
```

## C++数据抽象

数据抽象是指,只向外界提供关键信息,并隐藏其后台的实现细节,即只表现要表现的信息而不呈现细节.

数据抽象是一种依赖于接口和实现分离的变成技术.

就c++变成而言,C++类为数据抽象提供了可能性.他们向外界提供了大量用于操作对象数据的公共方法,也就是说,外界实际上并不清楚类的内部实现.

在c++中,我们使用类来定义我们自己的抽象数据类型,你可以使用iostream的cout对象来输出数据到标准输出

```c++
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello C++" << endl;
    return 0;
}
```

在这里,你不需要理解cout是如何在用户的屏幕上显示文本.只需要知道公共接口即可

### 访问标签强制抽象

在C++中,我们使用访问标签来定义类的抽象接口.一个类可以包含零个或多个访问标签.

- 使用公共标签定义的成员都可以访问该程序的所有部分.一个类型的数据抽象视图是由它的公共成员来定义的.
- 使用私有标签定义的成员无法访问到使用类的代码.私有部分对使用类型的代码隐藏了实现细节

访问标签出现的频率没有限制.每个访问标签指定了紧随其后的成员定义的访问级别.指定的访问级别会一直有效,直到遇到下一个访问标签或者遇到类主体的关闭右括号为止.

### 数据抽象的好处

数据抽象有两个重要的优势:

- 类的内部受到保护,不会因无意的用户级错误导致对象状态受损
- 类实现可能随着时间的推移而发生变化,以便应对不断变化的需求,或者应对那些要求不改变用户级代码的错误报告.

如果只在类的私有部分定义数据成员,编写该类的作者就可以随意更改数据.如果实现发生改变,则只需要检查类的的代码,看看这个改变会导致那些影响.如果数据时公有的,则任何直接访问旧表示形式的数据成员的函数都可能收到影响

### 数据抽象的实例

```c++
#include <iostream>
using namespace std;

class Adder{
    public :
    Adder(int i=0){
        total = i;
    }
    void addNum(int num){
        total += num;
    }
    int getTotal(){
        return total;
    }
    private :
    int total;
}

int main()
{
    Adder a;
    a.addNum(10);
    a.addNum(20);
    
    cout << "Total " << a.getTotal() << endl;
    return 0;
}
```

### 设计策略

抽象把代码分离为接口和实现.所以在设计组件时,必须保持接口独立于实现,这样,如果改变底层实现,接口也将保持不变.

在这种情况下,不管任何程序使用接口,接口都不会受到