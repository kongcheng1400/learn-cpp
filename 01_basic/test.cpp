#include <iostream>
#include <string>
#include <vector>

int main() {
    const wchar_t* str = L"Hello!";
    const size_t byteSize = (wcslen(str) + 1)*sizeof(wchar_t);
    std::cout << "length = " << byteSize << std::endl;

    char str1[] = "12" "3455";
    std::cout << "str = " << str1 << std::endl;

    int *a = nullptr;

    auto c = 'a', *d(&c);
    std::cout << "d = " << d << std::endl;
    return 0;
}