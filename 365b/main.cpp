#include <iostream>
#include <array>
using namespace std;
constexpr int N = 1e5 + 1;

int main() {
    freopen("a.in", "r", stdin);
    array<int, N> a{};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n <= 2) {
        cout << n;
        return 0;
    }
    int i = 0, ans = 2;
    while (i < n) {
        int j = i + 2;
        while (j < n) {
            if (a[j] != a[j - 1] + a[j - 2]) break;
            ans = max(ans, j - i + 1);
            j++;
        }
        i = j - 1;
    }
    cout << ans;
    return 0;
}
