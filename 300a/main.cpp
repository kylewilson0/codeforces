#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    vector<int> a{}, b{}, c{};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < 0) a.emplace_back(t);
        if (t > 0) b.emplace_back(t);
        if (t == 0) c.emplace_back(t);
    }
    if ((a.size() & 1) == 0) {
        c.emplace_back(a.back());
        a.pop_back();
    }
    if (b.empty()) {
        b.emplace_back(a.back());
        a.pop_back();
        b.emplace_back(a.back());
        a.pop_back();
    }
    cout << a.size() << " ";
    for (const auto &i: a) cout << i << " ";
    cout << endl;
    cout << b.size() << " ";
    for (const auto &i: b) cout << i << " ";
    cout << endl;
    cout << c.size() << " ";
    for (const auto &i: c) cout << i << " ";
    return 0;
}
