#include <iostream>
#include <stack>
using namespace std;

constexpr int N = 2 * 1e5 + 1;
long long t, n, a[N], pos_max;

void init() {
    cin >> n;
    pos_max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > a[pos_max]) pos_max = i;
    }
}

void solve() {
    stack<pair<long long, long long> > s;
    long long lv[N] = {0}, rv[N] = {0};

    s.emplace(INT_MAX, 0);
    for (long long i = 1; i < n; i++) {
        long long j = (pos_max + i) % n;
        long long temp = lv[j] + a[j], c = 1;
        while (s.top().first <= a[j]) {
            temp += s.top().second * (a[j] - s.top().first);
            c += s.top().second;
            s.pop();
        }
        s.emplace(a[j], c);
        lv[(j + 1) % n] = temp;
    }

    s = stack<pair<long long, long long> >();
    s.emplace(INT_MAX, 0);
    for (long long i = 1; i < n; i++) {
        long long j = (pos_max + n - i) % n;
        long long temp = rv[(j + 1) % n] + a[j], c = 1;
        while (s.top().first <= a[j]) {
            temp += s.top().second * (a[j] - s.top().first);
            c += s.top().second;
            s.pop();
        }
        s.emplace(a[j], c);
        rv[j] = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << lv[i] + rv[i] << " ";
    }
    cout << endl;
}

int main() {
    freopen("a.in", "r", stdin);
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}
