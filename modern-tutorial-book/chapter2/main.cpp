#include <iostream>
#include <type_traits>

void printer(std::initializer_list<int> list)
{
    for (std::initializer_list<int>::iterator i = list.begin();i!=list.end();i++)
    {
        std::cout << *i << std::endl;
    }
};

int main()
{

    printer({12, 4, 7, 8, 4, 3});

    return 0;
}
