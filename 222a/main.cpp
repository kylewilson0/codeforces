#include <iostream>
using namespace std;
constexpr int N = 1e5 + 1;

int main() {
    int n, k, a[N];
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > k - 1) {
            if (a[i] != a[k - 1]) {
                cout << -1;
                return 0;
            }
        }
    }
    int i = k - 2;
    while (i >= 0 && a[i] == a[k - 1]) i--;

    cout << i + 1;
    return 0;
}
