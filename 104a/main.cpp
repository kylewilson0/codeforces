#include <iostream>
using namespace std;

int n;

int solve() {
    if (n <= 0) return 0;
    if (n < 10) return 4;
    if (n == 10) return 15;
    if (n == 11) return 4;
    return 0;
}

int main() {
    cin >> n;
    n -= 10;
    cout << solve();
    return 0;
}
