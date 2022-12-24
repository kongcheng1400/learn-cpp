## Modern C++

### the princple of resource acquisition is initialization(RAII)
- 资源(heap memory, file handle, sockets and so on)必须被对象所有。对象在constructor中创建/接受新分配的资源, 在destructor中释放。
- samrt pointer: std::unique_ptr, std::shared_ptr, std::weak_ptr

### std::string , std::string_view
- 受益于高性能的方法: 

### std::vector
- 标准库容器遵循了RAII原则.
- iterators

### 标准库算法.
- searching, sorting, filtering, randomizing.

一些重要的例子:
- for_each
- transform
- find_if
- sort, lower_bound

### auto instead of explicit type names
```C++
map<int,list<string>>::iterator i = m.begin(); // C-style
auto i = m.begin(); // modern C++
```

### rangebased for loops
```C++
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v {1,2,3};

    // C-style
    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i];
    }

    // Modern C++:
    for(auto& num : v)
    {
        std::cout << num;
    }
}
```

### 使用constexpr 而不是macro

### uniform initialization-braces initialization
- 特别适用于初始化array, vectors, 和其他容器.
```c++
#include <vector>

struct S
{
    std::string name;
    float num;
    S(std::string s, float f) : name(s), num(f) {}
};

int main()
{
    // C-style initialization
    std::vector<S> v;
    S s1("Norah", 2.7);
    S s2("Frank", 3.5);
    S s3("Jeri", 85.9);

    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);

    // Modern C++:
    std::vector<S> v2 {s1, s2, s3};

    int i{42};

    // or...
    std::vector<S> v3{ {"Norah", 2.7}, {"Frank", 3.5}, {"Jeri", 85.9} };

}
```

### Move semantics
- move语义: 将资源的ownership从一个对象转移到另外一个对象: 而不用copy.

### lambda表达式
- C-style:函数指针。难以维护与理解。
- 函数对象/类重载operator(). 最方便的是使用lambda expressions:
```c++
std::vector<int> v {1,2,3,4,5};
    int x = 2;
    int y = 4;
    auto result = find_if(begin(v), end(v), [=](int i) { return i > x && i < y; });
```

### Exceptions VS error codes.

### 多线程通信: std::atomic

### std::variant VS union:
- std::visit保证类型安全.


### pimpl: point to implimentation.
- 最小化依赖
- 分离接口与实现
- 移植性。
```C++
// my_class.h
class my_class {
   //  ... all public and protected stuff goes here ...
private:
   class impl; unique_ptr<impl> pimpl; // opaque type here
};

// my_class.cpp
class my_class::impl {  // defined privately here
  // ... all private data and functions: all of these
  //     can now change without recompiling callers ...
};
my_class::my_class(): pimpl( new impl )
{
  // ... set impl values ...
}
```