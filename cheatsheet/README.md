# 基本类型
int, long, long long


# 复合类型
## 其他

# 内置函数/operator
typedef
sizeof operator: size of char.
## algo
for_each
generate
generate_n
# 控制及跳转
range for
使用iterator 
# 函数

# 异常

# 标准库
- <iostream>, <string>, <vector>, 
## vector
分类为: 随机访问(遍历，读取，插入修改), 测试, 属性(长度，capacity), 类型
- assign
- 随机访问: at(), back(), begin(), cbegin(),end(), cend(), data()
- 属性:capacity(), get_allocator(),empty(), max_size(), reserve(), resize(),size(),
- 编辑: emplace(), emplace_back(), erase(), insert(), push_back(), pop_back()
- 
- 操作符:[], 赋值.

## iostream
open(), close(), put(), seekp(), tellp()
error processing: bad(), fail(), good(), eof(), clear()
! operator重载为fail: if(!cout) 等效于 if(cout.fail()), void* operator重载:if(cout) 等效于 if(!cout.fail())
