#include <iostream>
using namespace std;

int main() {
    int n, p, max_point, min_point, ans = 0;
    cin >> n >> p;
    max_point = min_point = p;
    for (int i = 1; i < n; i++) {
        cin >> p;
        if (p > max_point) {
            max_point = p;
            ans++;
        }
        if (p < min_point) {
            min_point = p;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
