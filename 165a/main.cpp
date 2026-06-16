#include <iostream>
using namespace std;

const int N = 201;

int main() {
    int a[N][2];
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            found |= (a[j][0] == a[i][0] && a[j][1] > a[i][1]);
            found |= (a[j][0] == a[i][0] && a[j][1] < a[i][1]) << 1;
            found |= (a[j][1] == a[i][1] && a[j][0] > a[i][0]) << 2;
            found |= (a[j][1] == a[i][1] && a[j][0] < a[i][0]) << 3;
            if (found == (1 << 4) - 1) {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
