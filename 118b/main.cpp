#include <iostream>
using namespace std;

int main() {
    int n, a[20][20];
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            if (j <= n) a[i][j] = i + j - n;
            else a[i][j] = n + i - j;
        }
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            if (j <= n) a[i][j] = n - i + j;
            else a[i][j] = 3 * n - i - j;
        }
    }
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            if (a[i][j] < 0) {
                if (j > n) break;
                cout << "  ";
            } else {
                if (a[i][j] == 0 && j >= n) cout << a[i][j];
                else cout << a[i][j] << " ";
            }
        }
        if (i < 2 * n) cout << endl;
    }

    return 0;
}
