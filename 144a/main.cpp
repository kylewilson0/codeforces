#include <iostream>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    int n, x, min_p = 0, max_p = 0;
    int min_h = INT_MAX, max_h = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x <= min_h) {
            min_h = x;
            min_p = i;
        }
        if (x > max_h) {
            max_h = x;
            max_p = i;
        }
    }
    if (min_p < max_p) {
        cout << n - 1 - min_p + max_p - 1 << endl;
    } else {
        cout << n - 1 - min_p + max_p << endl;
    }
    return 0;
}
