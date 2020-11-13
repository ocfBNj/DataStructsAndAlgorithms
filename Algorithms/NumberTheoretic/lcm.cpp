#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a = 0;
    int b = 0;

    std::cout << "Please enter two numbers: ";
    std::cin >> a >> b;

    std::cout << "lcm(" << a << ", " << b << ") = " << lcm(a, b) << "\n";
}
