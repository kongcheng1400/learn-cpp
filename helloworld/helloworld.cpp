#include <iostream>
#include <string>
#include <vector>

int main()
{
    typedef long long ll;
    ll a = 123456789;
    ll b = 987654321;
    std::cout << a * b << std::endl;
    std::cout << "Hello World" << std::endl;

    std::vector<std::string> msg {"hello", "C++", "world", "from", "VS code", "and the C++ extension!"};

    for (const std::string& word: msg) {

        std::cout << word << " ";
    }
    std::cout << std::endl;
}