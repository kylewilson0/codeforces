#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
constexpr int N = 1e3 + 1;

array<pair<int, int>, N> a;

bool is_intersected(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first && b.first < a.second && a.second < b.second) {
        return true;
    }
    if (b.first < a.first && a.first < b.second && b.second < a.second) {
        return true;
    }
    return false;
}

int main() {
    freopen("a.in", "r", stdin);
    int n, t, last;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (i == 0) {
            last = t;
            continue;
        }
        a[i - 1] = {min(last, t), max(last, t)};
        last = t;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (i == j) continue;
            if (is_intersected(a[i], a[j])) {
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no";
    return 0;
}
