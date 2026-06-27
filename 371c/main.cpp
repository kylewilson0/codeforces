#include <iostream>
#include <array>
using namespace std;

#define int long long

array<int, 3> recipe{}, n{}, p{};
int ruble;

void init() {
    string st;
    cin >> st;
    for (int i = 0; i < 3; i++) cin >> n[i];
    for (int i = 0; i < 3; i++) cin >> p[i];
    cin >> ruble;
    for (auto &c: st) {
        if (c == 'B') recipe[0]++;
        else if (c == 'S') recipe[1]++;
        else recipe[2]++;
    }
}

bool can_make(int num) {
    int left = ruble;
    array<int, 3> need{};
    for (int i = 0; i < 3; i++) {
        need[i] = recipe[i] * num;
        if (n[i] < need[i]) {
            left -= (need[i] - n[i]) * p[i];
        }
    }
    if (left < 0) return false;
    return true;
}

signed main() {
    freopen("a.in", "r", stdin);
    init();
    int l = 1, r = 1e13;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (can_make(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (can_make(l)) cout << l;
    else cout << l - 1;
    return 0;
}
