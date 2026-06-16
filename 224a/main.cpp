#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c;
    y = sqrt(a * c / b);
    x = a / y;
    z = c / y;
    cout << 4 * (x + y + z) << endl;
    return 0;
}
