#include <iostream>
using namespace std;

int main() {
    int n, m, t, min_correct = INT_MAX, max_correct = INT_MIN, min_wrong = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        max_correct = max(max_correct, t);
        min_correct = min(min_correct, t);
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        min_wrong = min(min_wrong, t);
    }
    if (int v = max(min_correct * 2, max_correct); v < min_wrong) cout << v;
    else cout << -1;
    return 0;
}
