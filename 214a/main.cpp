#include <iostream>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (i * i + j == n && i + j * j == m) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
