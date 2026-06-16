#include <iostream>
#include <array>
#include <vector>
#include <map>
using namespace std;

#define int long long

constexpr int N = 5e5 + 1;
constexpr int M = 1e9 + 7;

array<int, N> least_prime;
array<int, N> a;
vector<int> prime;
int n, x;

int solve() {
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int val = a[i];
        while (val > 1) {
            cnt[least_prime[val]]++;
            val /= least_prime[val];
        }
    }
    int ans = 1;
    for (auto c: cnt) {
        ans = ans * (1 + c.second) % M;
    }
    return ans;
}

void init() {
    least_prime[1] = 1;
    for (int i = 2; i < N; i++) {
        if (least_prime[i] == 0) {
            prime.push_back(i);
            least_prime[i] = i;
        }
        for (auto prime_j: prime) {
            if (prime_j * i >= N) break;
            least_prime[prime_j * i] = prime_j;
            if (i % prime_j == 0) break;
        }
    }
}

signed main() {
    freopen("a.in", "r", stdin);
    init();
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve() << endl;
    }
    return 0;
}
