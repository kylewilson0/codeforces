#include <iostream>
using namespace std;

int main() {
    int a, b, c, x1, x2, x3;
    cin >> a >> b >> c;
    x1 = a + b - c;
    x2 = b + c - a;
    x3 = a + c - b;
    if (x1 < 0 || x1 & 1 || x2 < 0 || x2 & 1 || x3 < 0 || x3 & 1) {
        cout << "Impossible";
        return 0;
    }
    cout << x1 / 2 << " " << x2 / 2 << " " << x3 / 2;
    return 0;
}
