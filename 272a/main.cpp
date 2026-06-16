#include <iostream>
using namespace std;

int main() {
    int n, t, tot = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t, tot += t;
    }
    for (int i = 1; i <= 5; i++) {
        if ((i + tot) % (n + 1) != 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
