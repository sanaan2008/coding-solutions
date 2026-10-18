#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    const vector<string> words = {
        "", "one", "two", "three", "four", 
        "five", "six", "seven", "eight", "nine"
    };

    if (n >= 1 && n <= 9) {
        cout << words[n] << endl;
    } else {
        cout << "Greater than 9" << endl;
    }

    return 0;
}
