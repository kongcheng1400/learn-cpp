// my_class.h
#include <string>
namespace N
{
    class my_class
    {
    public:
        my_class(std::string name) : _name{name} {}
        void do_something();

    private:
        std::string _name {""};
    };

}