#include <iostream>

int main() {
    int a[30] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};
    int result = 0;

#pragma omp parallel for reduction(+:result)
    for (int i = 0; i < 30; i++) {
        if (a[i] == 1) {
            result += 1 << (29 - i);
        }
    }

    std::cout << "Decimal number: " << result << std::endl;

    return 0;
}
