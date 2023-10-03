#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

int main() {
    int start, end;

    std::cout << "Enter the start of the range: ";
    std::cin >> start;
    std::cout << "Enter the end of the range: ";
    std::cin >> end;

    int sqrt_end = std::sqrt(end);

    std::vector<bool> is_prime(end + 1, true);
    is_prime[0] = is_prime[1] = false;

#pragma omp parallel for
    for (int p = 2; p <= sqrt_end; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= end; i += p) {
                is_prime[i] = false;
            }
        }
    }

    std::cout << "Prime numbers in the range [" << start << ", " << end << "]:" << std::endl;
    for (int i = start; i <= end; i++) {
        if (is_prime[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
