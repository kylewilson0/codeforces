#include <iostream>
#include <algorithm>
using namespace std;
int t, n, a[101];

void process() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    if (n == 2) {
        cout << a[0] << " " << a[1] << endl;
        return;
    }
    bool flag = true;
    for (int i = 0; i < n - 2; i++) {
        if (a[i + 2] != a[i] % a[i + 1]) {
            flag = false;
            break;
        }
    }

    if (flag) cout << a[0] << " " << a[1] << endl;
    else cout << -1 << endl;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        process();
    }
    return 0;
}
