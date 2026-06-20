#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 100> a = {}, b = {};
    int n, sum_a = 0, sum_b = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum_a += a[i];
        sum_b += b[i];
    }
    if ((sum_a & 1) == 0 && (sum_b & 1) == 0) {
        cout << 0;
        return 0;
    }
    if (sum_a + sum_b & 1) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] + b[i] & 1) {
            cout << 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
