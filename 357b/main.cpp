#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
constexpr int N = 1e5 + 1;

array<int, N> color{};

int main() {
    freopen("a.in", "r", stdin);
    int n, m;
    array<int, 3> a{};
    ranges::fill(color, -1);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int previous = -1;
        for (int j = 0; j < 3; j++) {
            cin >> a[j];
            if (color[a[j]] != -1) {
                previous = j;
            }
        }
        if (previous != -1) {
            color[a[(previous + 1) % 3]] = (color[a[previous]] + 1) % 3;
            color[a[(previous + 2) % 3]] = (color[a[previous]] + 2) % 3;
        } else {
            for (int j = 0; j < 3; j++) color[a[j]] = j;
        }
    }
    for (int i = 1; i <= n; i++) cout << color[i] + 1 << " ";
    return 0;
}
