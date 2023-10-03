#include <iostream>

int main() {
    int number = 210;
    int result = 0;

#pragma omp parallel for reduction(+:result)
    for (int i = 1; i <= number; i++) {
        result += (2 * i - 1);
    }

    std::cout << "Square of " << number << " is " << result << std::endl;

    return 0;
}