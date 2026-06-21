#include <iostream>
#include <array>
using namespace std;

int main() {
    array<array<char, 11>, 11> a{};
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 'W') continue;
            bool flag = false;
            if (i > 0 && a[i - 1][j] == 'P') flag = true;
            if (i < n - 1 && a[i + 1][j] == 'P') flag = true;
            if (j > 0 && a[i][j - 1] == 'P') flag = true;
            if (j < m - 1 && a[i][j + 1] == 'P') flag = true;
            if (flag) ans++;
        }
    }
    cout << ans;
    return 0;
}
