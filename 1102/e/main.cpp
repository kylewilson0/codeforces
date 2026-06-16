#include <iostream>
using namespace std;

using ll = long long;

constexpr ll N = 5e5 + 10;
constexpr ll M = 1e9 + 7;

ll n, a[N];
ll fact[N], inv[N];

inline ll quick_power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

ll comb(ll n, ll m) {
    if (n < m) return 0;
    return fact[n] * inv[m] % M * inv[n - m] % M;
}

ll solve(ll l, ll r) {
    if (l == r) return a[l] == 1;
    if (r < l) return 1;

    for (ll i = l; i <= (l + r + 1) / 2; i++) {
        if (a[i] == (i - l + 1) * (r - i + 1)) {
            return solve(l, i - 1) * solve(i + 1, r) % M * comb(r - l, i - l) % M;
        }
        ll j = r - i + l;
        if (a[j] == (j - l + 1) * (r - j + 1)) {
            return solve(l, j - 1) * solve(j + 1, r) % M * comb(r - l, i - l) % M;
        }
    }
    return 0;
}

int main() {
    freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = inv[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % M;
        inv[i] = quick_power(fact[i], M - 2);
    }

    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (ll i = 0; i < n; i++) cin >> a[i];
        cout << solve(0, n - 1) << endl;
    }
    return 0;
}
