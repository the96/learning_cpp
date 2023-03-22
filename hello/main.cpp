#include <iostream>

int main () {
    std::cout << "Hello, world" << std::endl;

    const int x = 10;
    int var_x = x * 2;

    auto func   = [&](int a) -> int { return a + var_x; };
    auto func_b = [=](int a) -> int { return a + var_x; };

    std::cout << func(x) << std::endl;

    var_x = x * 3;

    std::cout << func(x) << std::endl;

    std::cout << func_b(x) << std::endl;
    std::cout << func_b(var_x) << std::endl;
    return 0;
}