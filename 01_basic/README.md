# 基本类型/built-in types
C++语言标准指定，并且编译器内建支持。不定义在任何头文件中。
- 3类: integral, floating-point, void
- bool char int float double void wchar_t
- nullptr: 内置
- 使用类型修饰符: signed, unsigned, short, long修饰基本类型
## char类型
- char类型: char, wchar_t, char8_t, char16_t, char32_t
- wchar_t: `typedef short int wchar_t`
- unsigned char 常用来表示byte. 
```C++
char     ch1{ 'a' };  // or { u8'a' }
wchar_t  ch2{ L'a' };
char16_t ch3{ u'a' };
char32_t ch4{ U'a' };
```



## tokens
- keywords
- identifiers
- Numeric, Boolean, Pointer, string, character字面量
- 操作符，标点符号。

### 字面量
```C++
int i = 157;        // Decimal literal
int j = 0198;       // Not a decimal number; erroneous octal literal
int k = 0365;       // Leading zero specifies octal literal, not decimal
int m = 36'000'000  // digit separators make large values more readable
int i = 0x3fff;   // Hexadecimal literal
int j = 0X3FFF;   // Equal to i
unsigned val_1 = 328u;                  // Unsigned value
long val_2 = 0x7FFFFFL;                 // Long value specified
                                        //  as hex literal
unsigned long val_3 = 0776745ul;        // Unsigned long value
auto val_4 = 108LL;                           // signed long long
auto val_4 = 0x8000000000000000ULL << 16;     // unsigned long long
long long i = 24'847'458'121; //digit separators
```

floating-point literals default to type double.
```C++
18.46
38.
18.46e0      // 18.46
18.46e1      // 184.6
```

pointer literal: 使用nullptr 而非NULL.

Binary litera:
```C++
auto x = 0B001101 ; // int
auto y = 0b000001 ; // int
```

string literals:
```C++
#include <string>
using namespace std::string_literals; // enables s-suffix for std::string literals

int main()
{
    // Character literals
    auto c0 =   'A'; // char
    auto c1 = u8'A'; // char
    auto c2 =  L'A'; // wchar_t
    auto c3 =  u'A'; // char16_t
    auto c4 =  U'A'; // char32_t

    // Multicharacter literals
    auto m0 = 'abcd'; // int, value 0x61626364

    // String literals
    auto s0 =   "hello"; // const char*
    auto s1 = u8"hello"; // const char* before C++20, encoded as UTF-8,
                         // const char8_t* in C++20
    auto s2 =  L"hello"; // const wchar_t*
    auto s3 =  u"hello"; // const char16_t*, encoded as UTF-16
    auto s4 =  U"hello"; // const char32_t*, encoded as UTF-32

    // Raw string literals containing unescaped \ and "
    auto R0 =   R"("Hello \ world")"; // const char*
    auto R1 = u8R"("Hello \ world")"; // const char* before C++20, encoded as UTF-8,
                                      // const char8_t* in C++20
    auto R2 =  LR"("Hello \ world")"; // const wchar_t*
    auto R3 =  uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16
    auto R4 =  UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32

    // Combining string literals with standard s-suffix
    auto S0 =   "hello"s; // std::string
    auto S1 = u8"hello"s; // std::string before C++20, std::u8string in C++20
    auto S2 =  L"hello"s; // std::wstring
    auto S3 =  u"hello"s; // std::u16string
    auto S4 =  U"hello"s; // std::u32string

    // Combining raw string literals with standard s-suffix
    auto S5 =   R"("Hello \ world")"s; // std::string from a raw const char*
    auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char* before C++20, encoded as UTF-8,
                                       // std::u8string in C++20
    auto S7 =  LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
    auto S8 =  uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
    auto S9 =  UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32
}
```

#### escape
```C++
#include <iostream>
using namespace std;

int main() {
    char newline = '\n';
    char tab = '\t';
    char backspace = '\b';
    char backslash = '\\';
    char nullChar = '\0';

    cout << "Newline character: " << newline << "ending" << endl;
    cout << "Tab character: " << tab << "ending" << endl;
    cout << "Backspace character: " << backspace << "ending" << endl;
    cout << "Backslash character: " << backslash << "ending" << endl;
    cout << "Null character: " << nullChar << "ending" << endl;
}
/* Output:
Newline character:
ending
Tab character:  ending
Backspace character:ending
Backslash character: \ending
Null character:  ending
*/
```

### string literals
- 以null-terminated characters
- narrow string literals, const char[n]
- utf-8 encoded strings: const char[n], c++20 introduced char8_t for utf-8 encoded 8-bit unicode
- wide string literals: const wchar_t[n]
- unicode: char16_t, char32_t
- Raw string literals: 通常使用在正则表达式 html, xml
```C++
const char *narrow = "abcd";

// represents the string: yes\no
const char *escaped = "yes\\no";

//UTF-8
// Before C++20
const char* str1 = u8"Hello World";
const char* str2 = u8"\U0001F607 is O:-)";
// C++20 and later
const char8_t* u8str1 = u8"Hello World";
const char8_t* u8str2 = u8"\U0001F607 is O:-)";

//wide string literal
const wchar_t* wide = L"zyxw";
const wchar_t* newline = L"hello\ngoodbye";


// represents the string: An unescaped \ character
const char* raw_narrow = R"(An unescaped \ character)";
const wchar_t*  raw_wide  = LR"(An unescaped \ character)";
const char*     raw_utf8a = u8R"(An unescaped \ character)"; // Before C++20
const char8_t*  raw_utf8b = u8R"(An unescaped \ character)"; // C++20
const char16_t* raw_utf16 = uR"(An unescaped \ character)";
const char32_t* raw_utf32 = UR"(An unescaped \ character)";

```

#### std::string literals(c++14)
std::string :  标准库实现的:还有std:wstring, std::u16string, 根据其前缀:
```C++
//#include <string>
//using namespace std::string_literals;
string str{ "hello"s };
string str2{ u8"Hello World" };     // Before C++20
u8string u8str2{ u8"Hello World" }; // C++20
wstring str3{ L"hello"s };
u16string str4{ u"hello"s };
u32string str5{ U"hello"s };
```

#### size of string literals
- ANSI char* : single byte-encoding
- UTF-8: 1 to 4 bytes for 1 code units.
- char16_t to wchar_t encoded as UTF-16 may uses 2 elements for encode a single code unit.

连接:

## 基本概念
### scope
- visibility
6种scope:
- Global scope
- namespace scope
- local scope
- class scope
- statement scope
- function scope: label. goto cleanup

### C++的类型系统.
强类型和静态类型语言: 指明类型后者使用auto keyword来引导编译器推导。
- scalar type: integral / floating-point, pointer, pointer-to-member, std::nullptr_t
- compound: array, function types, class/struct, enumerations, references, pointersto non-static class members.
- Variable/Objects
- object: class or structure的实例
- POD type: plain old data. 或者POD class.(没有自定义构造函数)
### storage 存储类
- automatic, extern, static, thread_local
- static: 从程序开始到程序结束. 
    - 用来使全局变量或者函数文件scope.
    - 在函数中保持其值到下一次调用.
    - 用在class中 所有实例共享, 没有this
- extern: 其他文件可见.
- thread_local: 只有创建其的thread内可见.
    - 只能用于static storage duration, local static object, local static data members.
- auto: 推荐尽量使用 auto.
    - 声明变量并且初始化
    - simplicity

#### auto 初始化
可以使用specifiers例如const, volatile, pointer, reference, rvalue reference(&&)
- 通用初始化语法 `auto a {42};`
- 赋值语法: `auto b = 0;`
- 通用赋值语法+ 赋值: `auto c = {3.14159};`
- 直接初始化或者构造器形式: `auto d(1.1421f);`
- 循环: `for (auto& i : iterable) do_action(i)`
#### auto + decltype
可以帮助写模板库:

```C++
#include <initializer_list>

int main()
{
    // std::initializer_list<int>
    auto A = { 1, 2 };

    // std::initializer_list<int>
    auto B = { 3 };

    // int
    auto C{ 4 };

    // C3535: cannot deduce type for 'auto' from initializer list'
    auto D = { 5, 6.7 };

    // C3518 in a direct-list-initialization context the type for 'auto'
    // can only be deduced from a single initializer expression
    auto E{ 8, 9 };

    return 0;
}

```

```C++
// cl /EHsc /nologo /W4
#include <deque>
using namespace std;

int main()
{
    deque<double> dqDoubleData(10, 0.1);

    for (auto iter = dqDoubleData.begin(); iter != dqDoubleData.end(); ++iter)
    { /* ... */ }

    // prefer range-for loops with the following information in mind
    // (this applies to any range-for with auto, not just deque)

    for (auto elem : dqDoubleData) // COPIES elements, not much better than the previous examples
    { /* ... */ }

    for (auto& elem : dqDoubleData) // observes and/or modifies elements IN-PLACE
    { /* ... */ }

    for (const auto& elem : dqDoubleData) // observes elements IN-PLACE
    { /* ... */ }
}

```
#### const
- C++可以用const来指定数组长度， C不行.
- C++中const 缺省为internal linkage. 可以放在头文件中。 C中则是缺省为external linkage, 只能放在源文件中.
- const对象， const成员函数: const对象只能调用constant member functions. 
- const成员函数: 这是只读函数. 不能修改对象。把const 放在参数括号后面。
```C++
// constant_values3.cpp
int main() {
   char this_char{'a'}, that_char{'b'};
   char *mybuf = &this_char, *yourbuf = &that_char;
   char *const aptr = mybuf;
   *aptr = 'c';   // OK
   aptr = yourbuf;   // C3892
}

// constant_values4.cpp
#include <stdio.h>
int main() {
   const char *mybuf = "test";
   char *yourbuf = "test2";
   printf_s("%s\n", mybuf);

   const char *bptr = mybuf;   // Pointer to constant data
   printf_s("%s\n", bptr);

   // *bptr = 'a';   // Error
}
```

### constexpr
- C++11 C++14
- constexpr可以用于函数和类构造器: 用来指示返回值是不变的，可以在编译时计算。而const可以在run time时计算。
- C++14要求constant expression中的类型为字面量。必须返回字面量。
- constexpr函数
    - 编译时计算.或者一个
    - impoicitly inline

```C++
constexpr float x = 42.0;
constexpr float y{108};
constexpr float z = exp(5, 3);
constexpr int i; // Error! Not initialized
int j = 0;
constexpr int k = j + 1; //Error! j not a constant expression

```




### 使用
先初始化再使用。
```C++
int result = 0;              // Declare and initialize an integer.
double coefficient = 10.8;   // Declare and initialize a floating
                             // point value.
auto name = "Lady G.";       // Declare a variable and let compiler
                             // deduce the type.
auto address;                // error. Compiler cannot deduce a type
                             // without an intializing value.
age = 12;                    // error. Variable declaration must
                             // specify a type or use auto!
result = "Kenny G.";         // error. Can't assign text to an int.
string result = "zero";      // error. Can't redefine a variable with
                             // new type.
int maxValue;                // Not recommended! maxValue contains
                             // garbage bits until it is initialized.
```



### 基本类型
- C++不像其他语言，有一个通用的基类派生所有其他类型。
numeric:
- int, float, double, long, long long, long double, bool
- char(ascII), wchar_t(unicode), 

|Type	|Size	    |                                         Comment                                      |
|-------|---------- |--------------------------------------------------------------------------------------|
|int	|4 bytes    |	The default choice for integral values.                                            |
|double	|8 bytes    |	The default choice for floating point values.                                      |
|bool	|1 byte	    |Represents values that can be either true or false.                                   |
|char	|1 byte	    |Use for ASCII characters in older C-style strings or std::string objects that will never have to be converted to UNICODE.                                                                                      |
|wchar_t|2 bytes    |	Represents "wide" character values that may be encoded in UNICODE format (UTF-16 on Windows, other operating systems may differ). wchar_t is the character type that's used in strings of type std::wstring.  |
|unsigned char      |	1 byte |C++ has no built-in byte type. Use unsigned char to represent a byte value. |
|unsigned int       |4 bytes|Default choice for bit flags.                                                 |
|long long |8 bytes |	Represents a much larger range of integer valu                                     |


#### const type
- const correctness
#### string types

严格而言，C++没有内置string type. 使用char, wchar_T, 声明一个数组来approximate一个string, 加一个null-terminator
现代C++使用了std::string(char), std::wstring(wchar_t), 使用include <string>
## 复合类型/用户自定义类型
class, struct, union, enum

#### 指针类型.
- 原始指针类型，现代C++的smart pointer
- 原始指针类型只是保存一个地址.
```C++
//错误的用法:
int* pNumber;       // Declare a pointer-to-int variable.
*pNumber = 10;      // error. Although this may compile, it is
                    // a serious error. We are dereferencing an
                    // uninitialized pointer variable with no
                    // allocated memory to point to.
//正确的用法.
int number = 10;          // Declare and initialize a local integer
                              // variable for data backing store.
int* pNumber = &number;   // Declare and initialize a local integer
                              // pointer variable to a valid memory
                              // address to that backing store.
*pNumber = 41;            // Dereference and store a new value in
                              // the memory pointed to by
                              // pNumber, the integer variable called
                              // "number". Note "number" was changed, not
                              // "pNumber".
```


```c++
enum color {red, green, blue} c;
c = blue;
```

## initializer
- 变量定义时使用:
- 函数参数
- 返回值

### 样式
```C++
Point p1(1, 2);
string s = "hello"; //copy initialization

struct Point{
    int x;
    int y;
};
class PointConsumer{
public:
    void set_point(Point p){}; //braced initializer
    void set_points(initializer_list<Point> my_list){};
};
int main() {
    PointConsumer pc{}; //value initialization
    pc.set_point({});
    pc.set_point({ 3, 4 });
    pc.set_points({ { 3, 4 }, { 5, 6 } });
}

```
### zero initialization
```C++
struct my_struct{
    int i;
    char c;
};

int i0;              // zero-initialized to 0
int main() {
    static float f1;  // zero-initialized to 0.000000000
    double d{};     // zero-initialized to 0.00000000000000000
    int* ptr{};     // initialized to nullptr
    char s_array[3]{'a', 'b'};  // the third char is initialized to '\0'
    int int_array[5] = { 8, 9, 10 };  // the fourth and fifth ints are initialized to 0
    my_struct a_struct{};   // i = 0, c = '\0'
}
```
#### default initialization
```C++
MyClass mc1;
MyClass *mc3 = new MyClass;
```

### static initialization(default )
```C++
class MyClass {
private:
    int m_int;
    char m_char;
};

int main() {
    static int int1;       // 0
    static char char1;     // '\0'
    static bool bool1;   // false
    static MyClass mc1;     // {0, '\0'}
}
```
### value initialization
```C++
class BaseClass {
private:
    int m_int;
};

int main() {
    BaseClass bc{};     // class is initialized
    BaseClass*  bc2 = new BaseClass();  // class is initialized, m_int value is 0
    int int_arr[3]{};  // value of all members is 0
    int a{};     // value of a is 0
    double b{};  // value of b is 0.00000000000000000
}
```
### copy initialization
- 通过一个对象初始化另一个:
- 初始化的时候使用 =
- 函数参数传递
- 函数返回值传递
- exeption thrown or caught.
- non-static data members 使用= 初始化.
- Aggregate initialization 中class,struct, union members
```C++
#include <iostream>
using namespace std;

class MyClass{
public:
    MyClass(int myInt) {}
    void set_int(int myInt) { m_int = myInt; }
    int get_int() const { return m_int; }
private:
    int m_int = 7; // copy initialization of m_int

};
class MyException : public exception{};
int main() {
    int i = 5;              // copy initialization of i
    MyClass mc1{ i };
    MyClass mc2 = mc1;      // copy initialization of mc2 from mc1
    MyClass mc1.set_int(i);    // copy initialization of parameter from i
    int i2 = mc2.get_int(); // copy initialization of i2 from return value of get_int()

    try{
        throw MyException();
    }
    catch (MyException ex){ // copy initialization of ex
        cout << ex.what();
    }
}
```

### direct initialization
- 非空括号初始化.
```C++
class BaseClass{
public:
    BaseClass(int n) :m_int(n){} // m_int is direct initialized
private:
    int m_int;
};

class DerivedClass : public BaseClass{
public:
    // BaseClass and m_char are direct initialized
    DerivedClass(int n, char c) : BaseClass(n), m_char(c) {}
private:
    char m_char;
};
int main(){
    BaseClass bc1(5);
    DerivedClass dc1{ 1, 'c' };
    BaseClass* bc2 = new BaseClass(7);
    BaseClass bc3 = static_cast<BaseClass>(dc1);

    int a = 1;
    function<int()> func = [a](){  return a + 1; }; // a is direct initialized
    int n = func();
}
```

#### list initialization


## using vs typedef
`using identifier = type;`
可读性using 更好.
```C++
// C++11
using func = void(*)(int);

// C++03 equivalent:
// typedef void (*func)(int);

// func can be assigned to a function pointer value
void actual_function(int arg) { /* some code */ }
func fptr = &actual_function;
```


typedef不能用于模板:
```C++
template<typename T> using ptr = T*;

// the name 'ptr<T>' is now an alias for pointer to T
ptr<int> ptr_int;
```

example:
```C++
#include <stdlib.h>
#include <new>

template <typename T> struct MyAlloc {
    typedef T value_type;

    MyAlloc() { }
    template <typename U> MyAlloc(const MyAlloc<U>&) { }

    bool operator==(const MyAlloc&) const { return true; }
    bool operator!=(const MyAlloc&) const { return false; }

    T * allocate(const size_t n) const {
        if (n == 0) {
            return nullptr;
        }

        if (n > static_cast<size_t>(-1) / sizeof(T)) {
            throw std::bad_array_new_length();
        }

        void * const pv = malloc(n * sizeof(T));

        if (!pv) {
            throw std::bad_alloc();
        }

        return static_cast<T *>(pv);
    }

    void deallocate(T * const p, size_t) const {
        free(p);
    }
};

#include <vector>
using MyIntVector = std::vector<int, MyAlloc<int>>;

#include <iostream>

int main ()
{
    MyIntVector foov = { 1701, 1764, 1664 };

    for (auto a: foov) std::cout << a << " ";
    std::cout << "\n";

    return 0;
}

```

## OPerators
- alignof()
- sizeof()
## casting
- dynamic_cast 多态类型
- static_cast 非多态类型
- const_cast: remove const volatile, __unaligned特性.
- reinterpret_cast: simple reinterpreation of bits
const_cast, reinterpret_cast: 最后采用。

`dynamic_cast <type-id> (expression)`:
- upcast: implicit conversion
- runtime check
- works only on pointers or referneces.

`static_cast <type-id> (expression)`: 
- no runtime check.
- 数值类型转换。int -> char

### Ellipsis and variadic templates.
```C++
template <typename... Arguments> returntype functionname(Arguments... args);
template <typename First, typename... Rest> class classname; //at least one parameter
```

