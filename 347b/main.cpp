#include <iostream>
#include <array>
using namespace std;

constexpr int N = 1e5 + 1;

int main() {
    array<int, N> a{};
    int n, ans = 0, k = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] == i) ans++;
        else {
            if (a[a[i]] == i) {
                k = max(k, 2);
            } else k = max(k, 1);
        }
    }
    cout << ans + k;
    return 0;
}
