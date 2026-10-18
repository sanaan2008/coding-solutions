#include <iostream>
#include <algorithm>

using namespace std;

// Function to find the maximum of four numbers
int max_of_four(int a, int b, int c, int d) {
    return max({a, b, c, d});
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int ans = max_of_four(a, b, c, d);
    cout << ans << endl;
    
    return 0;
}
