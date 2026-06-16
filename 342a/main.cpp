#include <iostream>
using namespace std;

int n, t, a[8] = {0};

bool is_found() {
    if (a[1] != n / 3) return false;
    if (a[2] < a[4] || a[6] < a[3]) return false;
    if (a[2] - a[4] != a[6] - a[3]) return false;
    if (a[2] - a[4] != n / 3 - a[3] - a[4]) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t]++;
    }
    if (!is_found()) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < a[3]; i++) printf("1 3 6\n");
    for (int i = 0; i < a[4]; i++) printf("1 2 4\n");
    for (int i = 0; i < a[2] - a[4]; i++) printf("1 2 6\n");
    return 0;
}
