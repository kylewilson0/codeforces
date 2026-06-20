#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

constexpr int N = 1e6 + 1;

array<int, N> lp = {};
vector<int> pr;
set<long long> d;

int main() {
    for (int i = 2; i < N; i++) {
        if (lp[i] == 0) {
            pr.push_back(i);
            d.insert(i);
            lp[i] = i;
        }
        for (const auto &prime_j: pr) {
            if (prime_j * i >= N) break;
            lp[prime_j * i] = prime_j;
            if (i % prime_j == 0) break;
        }
    }

    long long n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        const auto s = static_cast<long long>(sqrt(m));
        if (s * s != m) {
            cout << "NO" << endl;
            continue;
        }
        if (d.contains(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
