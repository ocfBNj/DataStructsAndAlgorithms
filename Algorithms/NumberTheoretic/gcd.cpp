#include <algorithm>
#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int bgcd(int a, int b) {
    // make sure a >= b.
    if (a < b) {
        std::swap(a, b);
    }

    if (b == 0) {
        return a;
    }

    bool a_isodd = a & 1;
    bool b_isodd = b & 1;

    if (a_isodd && b_isodd) {
        return bgcd((a - b) >> 1, b);
    } else if (a_isodd && !b_isodd) {
        return bgcd(a, b >> 1);
    } else if (!a_isodd && b_isodd) {
        return bgcd(a >> 1, b);
    }

    // both a and b are even numbers.
    return bgcd(a >> 1, b >> 1) << 1;
}

int main() {
    std::cout << gcd(25, 125) << "\n";
    std::cout << bgcd(25, 125) << "\n";
}
