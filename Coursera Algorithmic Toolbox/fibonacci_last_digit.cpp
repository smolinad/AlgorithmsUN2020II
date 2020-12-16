#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 2; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int last_fib_digit(int n){
    if (n < 1) return n;

    int previous = 0;
    int current = 1;

    for(int i = 2; i <= n; i++){
        int temp = previous;
        previous = current;
        current = (temp + current) % 10;
    }

    return current;
}

int main() {
    int n;
    std::cin >> n;
    int c = last_fib_digit(n);
    std::cout << c << '\n';
    }
