#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n - k - 1; i++) {
        cout << i << " ";
    }
    for (int i = 0; i <= k; i++) {
        cout << n - i << " ";
    }
    return 0;
}
