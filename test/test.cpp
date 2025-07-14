#include "aurray/aurray.hpp"
#include <iostream>

int main() {
    Aurray a(16);
    Aurray b(16);

    a.load_data({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});
    b.load_data({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});

    Aurray c = a + b;
    Aurray d = a - b;
    Aurray e = a * b;
    Aurray f = a / b;
    Aurray g = a + 2;
    Aurray h = a - 2;
    Aurray i = a * 2;
    Aurray j = a / 2;

    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    std::cout << g << std::endl;
    std::cout << h << std::endl;
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    std::cout << a.sum() << std::endl;
    std::cout << a.dot(b) << std::endl;

    return 0;
}