
## header file
- 编译程序的时候，每个CPP文件独立编译成一个编译单元, 编译器对声明在其他编译单元中的名字并不知情。
- 为了最小化错误，C++使用了header files来包含声明。
- C++20中使用了module.
- #Praggma once

## ODR: one definition rule.
- declaration vs definition
- declaration: name
- definition: creates storage and initilize

### external vs internal linkage
- Non-const gloable variables and free functions: external linkage.
- 全局变量: 使用static来变成internal linkage.
- internal linkage/no linkage:只在本translation unit可见。

## main 函数及入口
- 进入main函数前:static class members without explicit initializers are set to zero.

### 退出程序
- exit, abort, return from main.

## 循环
while, do, for, range-based for
```C++
vector<int> vec{ 0,1,2,3,4 };
for (auto it = begin(vec); it != end(vec); it++)
{
    // Access element using dereference operator
    cout << *it << " ";
}
for (auto num : vec)
{
    // no dereference operator
    cout << num << " ";
}
```
### iterable objects


## 运算符overloading
`type operator operator-symbol(parameterlist)`

## classes and structs
两个结构在C++中是一样的，structs: 可访问性 缺省public. class: 缺省private.
C++ style structure declaration VS C style structure declaration.


```C++
#include <iostream>
using namespace std;

struct PERSON {   // Declare PERSON struct type
    int age;   // Declare member types
    long ss;
    float weight;
    char name[25];
} family_member;   // Define object of type PERSON

struct CELL {   // Declare CELL bit field
    unsigned short character  : 8;  // 00000000 ????????
    unsigned short foreground : 3;  // 00000??? 00000000
    unsigned short intensity  : 1;  // 0000?000 00000000
    unsigned short background : 3;  // 0???0000 00000000
    unsigned short blink      : 1;  // ?0000000 00000000
} screen[25][80];       // Array of bit fields

int main() {
    struct PERSON sister;   // C style structure declaration
    PERSON brother;   // C++ style structure declaration
    sister.age = 13;   // assign values to members
    brother.age = 7;
    cout << "sister.age = " << sister.age << '\n';
    cout << "brother.age = " << brother.age << '\n';

    CELL my_cell;
    my_cell.character = 1;
    cout << "my_cell.character = " << my_cell.character;
}
// Output:
// sister.age = 13
// brother.age = 7
// my_cell.character = 1
```

#### example class
```C++
// TestRun.h

class TestRun
{
    // Start member list.

    // The class interface accessible to all callers.
public:
    // Use compiler-generated default constructor:
    TestRun() = default;
    // Don't generate a copy constructor:
    TestRun(const TestRun&) = delete;
    TestRun(std::string name);
    void DoSomething();
    int Calculate(int a, double d);
    virtual ~TestRun();
    enum class State { Active, Suspended };

    // Accessible to this class and derived classes only.
protected:
    virtual void Initialize();
    virtual void Suspend();
    State GetState();

    // Accessible to this class only.
private:
    // Default brace-initialization of instance members:
    State _state{ State::Suspended };
    std::string _testName{ "" };
    int _index{ 0 };

    // Non-const static member:
    static int _instances;
    // End member list.
};

// Define and initialize static member.
int TestRun::_instances{ 0 };
```

## Class
### 构造函数
- default constructor, copy constructor, 
- member initializer list.
- prefer member initializer lists over assigning values in the body.
- 使用initializer list之前调用基类的参数构造函数
```C++
class Box {
public:
    // Default constructor
    Box() {}

    // Initialize a Box with equal dimensions (i.e. a cube)
    explicit Box(int i) : m_width(i), m_length(i), m_height(i) // member init list
    {}

    // Initialize a Box with custom dimensions
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}

    int Volume() { return m_width * m_length * m_height; }

private:
    // Will have value of 0 when default constructor is called.
    // If we didn't zero-init here, default constructor would
    // leave them uninitialized with garbage values.
    int m_width{ 0 };
    int m_length{ 0 };
    int m_height{ 0 };
};


int main()
{
    Box b; // Calls Box()

    // Using uniform initialization (preferred):
    Box b2 {5}; // Calls Box(int)
    Box b3 {5, 8, 12}; // Calls Box(int, int, int)

    // Using function-style notation:
    Box b4(2, 4, 6); // Calls Box(int, int, int)
}
```

### default constructor
- 一般没有参数或者使用缺省参数.
- 可以初始化member避免编译器生成的缺省构造函数产生的对象里面的成员值untermined.
- 定义delete 可以阻止编译器产生缺省构造函数.
- 所有的成员都要有default member initializer.
- 如果声明了non-default constructors, 编译器不再提供default constructors
- 如果没有default cosntructors, 则编译器不能构造类似于 array of objects. 只能通过
```C++
class Box {
public:
    Box() { /*perform any required default initialization steps*/}

    // All params have default values
    Box (int w = 1, int l = 1, int h = 1): m_width(w), m_height(h), m_length(l){}
...
}



//default constructor: but with initialize the member or the members will be uninitialized and member's will be gabage value.
#include <iostream>
using namespace std;

class Box {
public:
    int Volume() {return m_width * m_height * m_length;}
private:
    int m_width { 0 };
    int m_height { 0 };
    int m_length { 0 };
};

int main() {
    Box box1; // Invoke compiler-generated constructor
    cout << "box1.Volume: " << box1.Volume() << endl; // Outputs 0
}
```

no default constructor:
```C++
Box boxes[3]; // C2512: no appropriate default constructor available
Box boxes[3]{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
```

#### copy constructors

#### explicit constructors


## order of construction
1. base class / member constructors
2. 如果从虚基类继承，初始化对象的virtual base pointers.
3. 如果对象有虚函数，初始化对象的虚函数指针，虚函数指针指向类的virtual table.
```C++
#include <iostream>

using namespace std;

class Contained1 {
public:
    Contained1() { cout << "Contained1 ctor\n"; }
};

class Contained2 {
public:
    Contained2() { cout << "Contained2 ctor\n"; }
};

class Contained3 {
public:
    Contained3() { cout << "Contained3 ctor\n"; }
};

class BaseContainer {
public:
    BaseContainer() { cout << "BaseContainer ctor\n"; }
private:
    Contained1 c1;
    Contained2 c2;
};

class DerivedContainer : public BaseContainer {
public:
    DerivedContainer() : BaseContainer() { cout << "DerivedContainer ctor\n"; }
private:
    Contained3 c3;
};

int main() {
    DerivedContainer dc;
}
```

## 成员函数--overview.
- static member function: has no implicit this argument.
- inline function: 定义在类声明中的函数.定义在类声明外部的函数，只能显示的声明为inline.而且函数名字必须classname::functionname.
- override 关键字：用来指明函数重载了基类中的virtual function. context-sensitive only when function declaration. 使用override关键字，编译器会检查函数是否重载了基类中的成员函数。
- final:derived class 中不能重载次函数.或者这个类不能被继承。

## inheritance
- base class , drived class

```C++
//access-specifier: public, protected, private: 缺省为private
class Derived : [virtual] [access-specifier] Base
{
   // member list
};
class Derived : [virtual] [access-specifier] Base1,
   [virtual] [access-specifier] Base2, . . .
{
   // member list
};
```

### virtual function
- 虚函数表示基类期望你在派生类中重新定义它。virtual/override配对使用.
- 当使用指针或者引用到基类对象而实际refer to派生类对象的时候， 可以调用这个对象的虚函数，而实际执行的是派生类的函数。如果派生类没有重载，则直接调用基类的函数. 对于非虚函数，则直接调用指针类型的函数.
- virtual keyword可以用在派生类的重载函数中，但是没必要。虚函数重载始终是虚函数.
- 基类中的虚函数必须定义，除非pure-specifier.
- 可以使用scope-resolution operator :: 指定调用基类的虚函数.


## preprocessor directives

#define, #ifdef #if defined #undef
#if, #elif #else #endif 
preprocessor operators:
- defined()
- __has_include

#ifdef, ifndef
相当于: #if defined()

```C++
#if !defined(__cplusplus)
#error C++ compiler required.
#endif

#if defined(CREDIT)
    credit();
#elif defined(DEBIT)
    debit();
#else
    printerror();
#endif

#if DLEVEL > 5
    #define SIGNAL  1
    #if STACKUSE == 1
        #define STACK   200
    #else
        #define STACK   100
    #endif
#else
    #define SIGNAL  0
    #if STACKUSE == 1
        #define STACK   100
    #else
        #define STACK   50
    #endif
#endif
#if DLEVEL == 0
    #define STACK 0
#elif DLEVEL == 1
    #define STACK 100
#elif DLEVEL > 5
    display( debugptr );
#else
    #define STACK 200
#endif


/*  EXAMPLE.H - Example header file  */
#if !defined( EXAMPLE_H )
#define EXAMPLE_H

class Example
{
    //...
};

#endif // !defined( EXAMPLE_H )

// ifdef_ifndef.CPP
// compile with: /Dtest /c
#ifndef test
#define final
#endif
```

## lambda
[capture clause](parameter list) [mutable] [throw]() -> returntype {
    function body.
}

capture clause: reference capture / value capture for external variable
```C++
[&total, factor]: 
[factor, &total]
[&, factor] //capture default
[=, &total]
```

### lambdas vs function objects vs function pointers
function objects: 可以保留对象 但不够简洁，需要类定义；
function pointers: 不能保留状态.
lambda: 两个优点， 简洁 并且可以保留状态。

