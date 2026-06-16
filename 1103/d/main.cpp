#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

constexpr int N = 2e5 + 1;

int a[N];
pair<int, int> b[N];

bool solve(int n, int k) {
    sort(a, a + n);
    int i = 0, cnt = 0;
    while (i < n) {
        int j = i + 1;
        while (a[j] == a[i] && j < n) j++;
        b[cnt++] = {a[i], j - i};
        i = j;
    }
    i = cnt - 1;
    queue<int> win;
    while (i >= 0) {
        auto [fst, snd] = b[i];
        while (!win.empty() && win.front() - fst > k) win.pop();
        if (win.empty() && snd & 1) {
            win.push(fst);
        } else {
            return true;
        }
        i = i - 1;
    }
    return false;
}

int main() {
    freopen("a.in", "r", stdin);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << (solve(n, k) ? "YES\n" : "NO\n");
    }
    return 0;
}
