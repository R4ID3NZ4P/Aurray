#include "aurray/aurray.hpp"
#include <iostream>

int main() {
    Aurray a(15);
    Aurray b(16);

    a.load_data({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
    b.load_data({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});

    Aurray c = a + b;

    std::cout << c << std::endl;

    return 0;
}