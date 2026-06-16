#include <iostream>
using namespace std;

int main() {
    int y, k, n;
    bool find = false;
    cin >> y >> k >> n;
    for (int i = 1; i * k <= n; i++) {
        if (i * k > y) {
            cout << i * k - y << " ";
            find = true;
        }
    }
    if (!find) cout << -1;
    return 0;
}
