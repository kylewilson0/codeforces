#include <iostream>
#include <array>
using namespace std;

constexpr int N = 1e3 + 1;
array<int, N> a{}, b{}, cnt_a{}, cnt_b{};

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        cnt_a[a[i]]++;
        cnt_b[b[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            if (cnt_b[b[i]] > 1) {
                ans += cnt_a[b[i]];
            } else {
                ans += cnt_a[b[i]] - 1;
            }
            cnt_a[b[i]] = 0;
        } else {
            ans += cnt_a[b[i]];
            cnt_a[b[i]] = 0;
        }
    }
    cout << n - ans;
    return 0;
}
