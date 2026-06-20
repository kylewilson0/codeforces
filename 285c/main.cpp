#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
constexpr int N = 3e5;

int main() {
    array<long long, N> a = {};
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.begin() + n);
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - i - 1);
    }
    cout << ans;
    return 0;
}
