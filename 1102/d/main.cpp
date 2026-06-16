#include <iostream>
using namespace std;

int n, k;
long long cnt[3];

void process() {
    long long ans = 0, avg;
    ans = cnt[0] + cnt[1];
    int step = 0;
    while (k) {
        if (step & 1) {
            avg = ((1 << step) + 1) / 3;
            ans += cnt[2] * (avg - 1) + (cnt[0] + cnt[1]) * avg;
        } else {
            avg = ((1 << step) - 1) / 3;
            ans += cnt[2] * (avg + 1) + (cnt[0] + cnt[1]) * avg;
        }
        step++, k--;
    }
    cout << ans << endl;
}

void init() {
    string a, b;
    cin >> n >> k;
    for (auto &i: cnt) i = 0;

    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        cnt[0] += a[i] - '0';
        cnt[1] += b[i] - '0';
        cnt[2] += a[i] - '0' ^ b[i] - '0';
    }
    for (long long &i: cnt) i = i * (n - i);
}

int main() {
    freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        init(), process();
    }
    return 0;
}
