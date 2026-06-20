#include <iostream>
#include <array>
using namespace std;

constexpr int N = 1e5 + 1;
array<int, N> a{}, ans{};
array<bool, N> b{};

int main() {
    int n, m, t;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        if (!b[a[i]]) {
            ans[i] = ans[i + 1] + 1;
            b[a[i]] = true;
        } else {
            ans[i] = ans[i + 1];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        cout << ans[t - 1] << endl;
    }
    return 0;
}
