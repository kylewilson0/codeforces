#include <iostream>
using namespace std;

int main() {
    int n, a[7], tot = 0, cur = 0, ans = 0;
    cin >> n;
    for (int &i: a) {
        cin >> i;
        tot += i;
    }
    n = n % tot;
    if (n == 0) n = tot;
    for (int i = 0; i < 7; i++) {
        cur += a[i];
        if (cur >= n) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
