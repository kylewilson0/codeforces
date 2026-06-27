#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;
constexpr int N = 3e3 + 2;

array<int, N> day{};
array<pair<int, int>, N> num{};

int main() {
    freopen("a.in", "r", stdin);
    int n, v, a, b;
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        num[i] = {a, b};
    }
    sort(num.begin(), num.begin() + n);
    for (int i = 0; i < n; i++) {
        a = num[i].first, b = num[i].second;
        int remaining = b - (v - day[a]);
        day[a] += min(v - day[a], b);
        if (remaining > 0) {
            day[a + 1] += min(v - day[a + 1], remaining);
        }
    }
    int ans = accumulate(day.begin(), day.end(), 0);
    cout << ans;
    return 0;
}
