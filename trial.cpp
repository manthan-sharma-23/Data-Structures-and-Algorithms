#include <iostream>

void addOne(int &num)
{
    num + 1;
}

int main()
{
    int a = 1;

    addOne(a);

    std::cout << a << std::endl;
}