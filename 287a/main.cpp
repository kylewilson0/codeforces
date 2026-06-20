#include <iostream>
#include <array>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    array<array<int, 5>, 5> a = {};
    char ch;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> ch;
            if (ch == '#') a[i][j] = 1;
            a[i][j] += a[i - 1][j];
            a[i][j] += a[i][j - 1];
            a[i][j] -= a[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    bool flag = false;
    for (int i = 2; i <= 4; i++) {
        for (int j = 2; j <= 4; j++) {
            int t = a[i][j] - a[i - 2][j] - a[i][j - 2] + a[i - 2][j - 2];
            if (t != 2) {
                flag = true;
                break;
            }
        }
    }
    cout << (flag ? "YES" : "NO");
    return 0;
}
