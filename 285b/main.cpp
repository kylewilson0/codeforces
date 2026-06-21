#include <iostream>
#include <array>
using namespace std;
constexpr int N = 1e5 + 1;
array<int, N> a{};
array<int, N> b{};

int main() {
    int n, s, t, ans = 0;
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    b[s] = true;
    while (s != t) {
        if (!b[a[s]]) {
            s = a[s];
            b[s] = true;
            ans++;
        } else {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
