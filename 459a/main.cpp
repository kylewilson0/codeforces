#include <iostream>
using namespace std;

int main() {
    int x1, x2, y1, y2, t;
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1 == y2) {
        t = abs(x1 - x2);
        cout << x1 << " " << y1 + t << " " << x2 << " " << y1 + t;
        return 0;
    }
    if (x1 == x2) {
        t = abs(y1 - y2);
        cout << x1 + t << " " << y1 << " " << x1 + t << " " << y2;
        return 0;
    }
    if (abs(x1 - x2) != abs(y1 - y2)) {
        cout << -1;
        return 0;
    }
    cout << x1 << " " << y2 << " " << x2 << " " << y1;
    return 0;
}
