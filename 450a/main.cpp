#include <iostream>
using namespace std;

int main() {
    int n, m, t, max_round = 0, ans;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t % m == 0) {
            t = t / m;
        } else {
            t = t / m + 1;
        }

        if (t >= max_round) {
            max_round = t;
            ans = i + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
