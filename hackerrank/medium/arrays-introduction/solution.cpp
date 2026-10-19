#include <iostream>
#include <vector>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Print elements in reverse order
    for (int i = n - 1; i >= 0; --i) {
        std::cout << arr[i] << (i == 0 ? "" : " ");
    }
    std::cout << "\n";

    return 0;
}
