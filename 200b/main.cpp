#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);

    int n, p;
    double frac = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        frac += p;
    }

    ans = frac / n;
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
