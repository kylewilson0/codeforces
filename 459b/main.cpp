#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, t, min_b = INT_MAX, min_cnt = 0, max_b = INT_MIN, max_cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < min_b) {
            min_b = t;
            min_cnt = 1;
        } else if (t == min_b) {
            min_cnt++;
        }
        if (t > max_b) {
            max_b = t;
            max_cnt = 1;
        } else if (t == max_b) {
            max_cnt++;
        }
    }
    if (max_b == min_b) {
        cout << 0 << " " << n * (n - 1) / 2;
    } else {
        cout << max_b - min_b << " " << max_cnt * min_cnt;
    }
    return 0;
}
