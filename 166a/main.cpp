#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    int n, p, t, k;
    vector<pair<int, int> > a;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> p >> t;
        a.emplace_back(p, t);
    }
    auto cmp = [](const pair<int, int> &l, const pair<int, int> &r) {
        if (l.first != r.first) return l.first > r.first;
        return l.second < r.second;
    };
    sort(a.begin(), a.end(), cmp);
    auto k_element = a[k - 1];
    auto lower_it = lower_bound(a.begin(), a.end(), k_element, cmp);
    auto upper_it = upper_bound(a.begin(), a.end(), k_element, cmp);
    cout << upper_it - lower_it;
    return 0;
}
