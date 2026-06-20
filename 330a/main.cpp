#include <iostream>
#include <array>
using namespace std;

array<array<int, 11>, 11> a{}, lsum{}, usum{};

int main() {
    int n, m;
    char ch;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ch;
            if (ch == 'S') a[i][j] = 1;
            lsum[i][j] = lsum[i][j - 1] + a[i][j];
            usum[i][j] = usum[i - 1][j] + a[i][j];
        }
    }
    int r = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        if (lsum[i][m] > 0) r++;
    }
    for (int i = 1; i <= m; i++) {
        if (usum[n][i] > 0) c++;
    }
    cout << n * m - r * c;
    return 0;
}
