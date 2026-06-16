#include <iostream>
#include <array>
using namespace std;
constexpr int N = 1.5e5 + 1;

int main() {
    int n, k, min = INT_MAX, pos = -1;
    array<int, N> sum = {};
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
        if (i - k >= 0) {
            if (sum[i] - sum[i - k] < min) {
                min = sum[i] - sum[i - k];
                pos = i - k + 1;
            }
        }
    }
    cout << pos;
    return 0;
}
