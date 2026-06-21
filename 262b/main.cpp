#include <iostream>
#include <array>
#include <numeric>
using namespace std;
constexpr int N = 1e5 + 1;
array<int, N> a;

int main() {
    int n, k, pos = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0 && k) {
            a[i] = -a[i];
            k--;
        }
        if (abs(a[i]) < abs(a[pos])) {
            pos = i;
        }
    }
    if (k && k & 1) {
        a[pos] = -a[pos];
    }
    int ans = accumulate(a.begin(), a.begin() + n, 0);
    cout << ans;
    return 0;
}
