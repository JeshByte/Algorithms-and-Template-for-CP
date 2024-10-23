#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> simpleSieve(int limit) {
    std::vector<bool> isPrime(limit + 1, true);
    std::vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return primes;
}

void segmentedSieve(int L, int R) {
    int limit = std::sqrt(R);
    std::vector<int> primes = simpleSieve(limit);

    std::vector<bool> isPrime(R - L + 1, true);

    if (L == 1) {
        isPrime[0] = false;
    }

    for (int prime : primes) {
        int start = std::max(prime * prime, (L + prime - 1) / prime * prime);

        for (int j = start; j <= R; j += prime) {
            isPrime[j - L] = false;
        }
    }

    for (int i = 0; i <= R - L; ++i) {
        if (isPrime[i]) {
            std::cout << (L + i) << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int L = 10, R = 50;
    std::cout << "Primes in the range [" << L << ", " << R << "] are:\n";
    segmentedSieve(L, R);
    return 0;
}
