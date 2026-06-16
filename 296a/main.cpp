#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    int n, t;
    array<int, 1001> a = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t]++;
    }
    auto p = max_element(a.begin(), a.end());
    if (*p > (n + 1) >> 1) cout << "NO";
    else cout << "YES";
    return 0;
}
