#include <iostream>
#include <vector>
#include <algorithm>

// use STL algorithm to check if all elements are divisible by 3
// implement 3 versions:
// * lambda
// * functor
// * function

auto divisibleBy3 = [](auto a) {
    if (a % 3 == 0) {
    std::cout << a << "\n";
    } else {
        std::cout << a << " is no devide by 3\n";
    }
    };

class divideBy3
{
public:
    void operator()(int x) {
        if (x % 3 == 0) {
            std::cout << x << "\n";
        } else {
            std::cout << x << " is no devide by 3\n";
        }
    }
};

void is3 (int x) {
    if (x % 3 == 0) {
        std::cout << x << "\n";
    } else {
        std::cout << x << " is not devide by 3\n";
    }
}

int main() {
    std::vector numbers = {18, 21, 36, 90, 27, 14, 103};
    divideBy3 func;
    for (const auto& el : numbers) {
        divisibleBy3(el);
        func(el);
        is3(el);
        std::cout << "\n";
    }

    return 0;
}
