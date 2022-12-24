# templates

## template paramters

用户提供模板参数，编译器生成普通类型或者函数.
```C++
//T: temlate parameter
template <typename T> 
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}

int a = get_a();
int b = get_b();
int i = minimum<int>(a, b);
//函数模板编译器能推断T类型: 也可以 int i = minimum(a, b);

```
## type paramters
```C++
template <typename T, typename U, typename V> class Foo{};


//ellipsis operator to define arbitrary number of zero or type parameters.
template<typename... Arguments> class vtclass;
vtclass< > vtinstance1;
vtclass<int> vtinstance2;
vtclass<float, bool> vtinstance3;
```

对类型参数并无故有要求，结合OOB技术，可以在vector<Base*>中使用Derived*:
The basic requirements that std::vector and other standard library containers impose on elements of T is that T be copy-assignable and copy-constructible.

```C++
vector<MyClass*> vec;
   MyDerived d(3, L"back again", time(0));
   vec.push_back(&d);

   // or more realistically:
   vector<shared_ptr<MyClass>> vec2;
   vec2.push_back(make_shared<MyDerived>());
```

使用非类型参数: 
```C++
template<typename T, size_t L>
class MyArray
{
    T arr[L];
public:
    MyArray() { ... }
};
```

### decltype + auto
type specifier yiels the type of specified expression.
auto + decltype

语法: decltype(expression): 返回expression参数的类型.
decltype(auto): 

### class typename keyword
typename: 指示编译器后面的参数是类型.
```C++
template<class T1, class T2>...
template<typename T1, typename T2>...
```


```C++
//使用了缺省参数.
template <class T, class Allocator = allocator<T>> class vector;
//大部分时候，缺省std::allocator is ok.
vector<int> myInts;
//对于全部缺省参数，直接使用<>
```

### Template specialization--for particular type.

### class template:
```C++
// member_function_templates1.cpp
template<class T, int i> class MyStack
{
    T*  pStack;
    T StackBuffer[i];
    static const int cItems = i * sizeof(T);
public:
    MyStack( void );
    void push( const T item );
    T& pop( void );
};

template< class T, int i > MyStack< T, i >::MyStack( void )
{
};

template< class T, int i > void MyStack< T, i >::push( const T item )
{
};

template< class T, int i > T& MyStack< T, i >::pop( void )
{
};

int main()
{
}
```