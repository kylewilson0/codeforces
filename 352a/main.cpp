#include <iostream>
using namespace std;

int main() {
    int n, t, five_cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        five_cnt += t == 5;
    }

    if (n - five_cnt == 0) {
        cout << -1;
        return 0;
    }

    if (five_cnt < 9) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < five_cnt / 9; i++) cout << 555555555;
    for (int i = 0; i < n - five_cnt; i++) cout << 0;

    return 0;
}
