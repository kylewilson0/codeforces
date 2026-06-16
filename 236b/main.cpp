#include <iostream>
#include <vector>
#include <array>
using namespace std;

#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e6 + 1;
constexpr int M = 1 << 30;

array<int, N> lp = {}, d = {};
vector<int> pr;

int main() {
    freopen("a.in", "r", stdin);
    int a, b, c;
    cin >> a >> b >> c;
    _rep(i, 2, N-1) {
        if (lp[i] == 0) {
            pr.push_back(i);
            lp[i] = i;
        }
        for (auto &p: pr) {
            if (p * i >= N) break;
            lp[p * i] = p;
            if (i % p == 0) break;
        }
    }
    d[1] = 1;
    _rep(i, 2, N-1) {
        int cur = i;
        d[i] = 1;
        while (cur > 1) {
            int div = lp[cur], j = 0;
            while (cur % div == 0) {
                j++;
                cur /= div;
            }
            d[i] *= j + 1;
        }
    }

    int ans = 0;
    _rep(i, 1, a) {
        _rep(j, 1, b) {
            _rep(k, 1, c) {
                ans = (ans + d[i * j * k]) % M;
            }
        }
    }
    cout << ans;
    return 0;
}
