#include <iostream>
using namespace std;

int main() {
    int n, t, min_time = INT_MAX, ans = 0, min_cnt = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < min_time) {
            min_time = t;
            min_cnt = 1;
            ans = i + 1;
        } else if (t == min_time) {
            min_cnt++;
        }
    }
    if (min_cnt > 1) cout << "Still Rozdil" << endl;
    else cout << ans << endl;
    return 0;
}
