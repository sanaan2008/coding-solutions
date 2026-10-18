#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    const vector<string> words = {
        "", "one", "two", "three", "four", 
        "five", "six", "seven", "eight", "nine"
    };

    for (int i = a; i <= b; ++i) {
        if (i >= 1 && i <= 9) {
            cout << words[i] << "\n";
        } else if (i % 2 == 0) {
            cout << "even\n";
        } else {
            cout << "odd\n";
        }
    }

    return 0;
}
