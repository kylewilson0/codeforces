#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
constexpr int N = 1e5 + 1;
array<pair<int, int>, N> a{};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.begin() + n);
    for (int i = 0; i < n - 1; i++) {
        if (a[i].second > a[i + 1].second) {
            cout << "Happy Alex";
            return 0;
        }
    }
    cout << "Poor Alex";
    return 0;
}
