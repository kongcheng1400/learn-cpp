# STL

## Overview
- iostreams conventions
- c++ STL reference conventions

调用std::abort, 包含<cstdlib>; 直接使用abort, 包含<stdlib.h>


## containers
- sequnce containers(vector, array, deque, list, forward_list), 
- associative containers(map, unorder_map_class), container adapaters.
- container adaptaters: not support iterators for simplicity and clarity.(queue, priority_que, stack)

### vecotr
基本操作:
分类为: 随机访问(遍历，读取，插入修改), 测试, 属性(长度，capacity), 类型
- assign
- 随机访问: at(), back(), begin(), cbegin(),end(), cend(), data()
- 属性:capacity(), get_allocator(),empty(), max_size(), reserve(), resize(),size(),
- 编辑: emplace(), emplace_back(), erase(), insert(), push_back(), pop_back()
- 
- 操作符:[], 赋值.
类型:
iterator, pointer(用于修改元素)
- typedef typename Allocator::reference reference;

```C++
vector();
explicit vector(const Allocator& allocator);
explicit vector(size_type count);
vector(size_type count, const Type& value);
vector(size_type count, const Type& value, const Allocator& allocator);

vector(const vector& source);
vector(vector&& source);
vector(initializer_list<Type> init_list, const Allocator& allocator);

template <class InputIterator>
vector(InputIterator first, InputIterator last);
template <class InputIterator>
vector(InputIterator first, InputIterator last, const Allocator& allocator);
```

### array. <array>
包括两个非成员函数: get, swap
get: 返回元素的引用:
```C++
template <int Index, class T, size_t N> constexpr T& get(array<T, N>& arr) noexcept;
```

#### operators
非成员操作符:
operator!=, operator>, ...

### members
类型: 1. iterators, 2. pointers, 3. reference, 4. 类型: size_type, value_type, difference_type
修饰: const, reverse.
成员函数:
array, fill
#### 构造函数
array(); //default constructor
array(const array& right); // copy constructor


## <string>

functions:
getline
stod, stof, stol, stold, stoll, 
swap, to_string, to_wstring

## iterators
- global functions: begin(), end(), ++, --, range-for loop, subscript operator[]
five categories:
1. output, forward: ++, *来修改: 一次
2. input: forward: ++, read:* 多次
3. forward: ++, read/write:*
4. bidirectional:++, --
5. Random access: +, -, +=, -=

### member functions
1. iterator
2. pointer
3. operators
- advance, next, prev,  inserter, back_inserter, front_inserter, begin, end, cbegin, cend, rbegin, rend, crbegin, crend, 
- data,
- empty, size

### pointer
- object pointer: random-access iterator.

## algorithms
- do not work with containers themselves but rather with iterators.
- predicate:

## alocators
所有的标准库容器都有allocator参数allocator<Type>， 除了array.
所有的标准库类型和函数接受一个allocator type parameter support minimal allocator interface.

### minimal allocator
1. converting copy constructor
2. operator==, operator!=
3. allocate
4. deallocate

## function objects
- functor. any type implements operator()