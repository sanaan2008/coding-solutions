#include <iostream>
#include <cstdlib> // For abs()

void update(int *a, int *b) {
    int sum = *a + *b;
    int diff = std::abs(*a - *b);
    
    *a = sum;
    *b = diff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    std::cin >> a >> b;
    update(pa, pb);
    std::cout << a << "\n" << b << "\n";

    return 0;
}
