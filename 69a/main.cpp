#include <iostream>
using namespace std;

int main() {
    int n, x, y, z, tx, ty, tz;
    tx = ty = tz = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        tx += x;
        ty += y;
        tz += z;
    }
    if (tx == 0 && ty == 0 && tz == 0) cout << "YES";
    else cout << "NO";
    return 0;
}
