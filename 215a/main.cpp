#include <iostream>
using namespace std;

int main() {
    int n, m, a[50], b[50], max = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] % a[i] == 0) {
                int t = b[j] / a[i];
                if (t > max) {
                    max = t;
                    cnt = 1;
                } else if (t == max) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
