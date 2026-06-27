#include <iostream>
#define int long long
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void simplify(int a, int b) {
    int d = gcd(a, b);
    while (d > 1) {
        a = a / d;
        b = b / d;
        d = gcd(a, b);
    }
    cout << b - a << "/" << b << endl;
}

signed main() {
    freopen("a.in", "r", stdin);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int lcm = a * c / gcd(a, c);
    int s1 = lcm / a, s2 = lcm / c;
    if (d * s2 <= b * s1) {
        simplify(lcm * d * s2, lcm * b * s1);
    } else {
        int lcm = b * d / gcd(b, d);
        int s1 = lcm / b, s2 = lcm / d;
        simplify(lcm * c * s2, lcm * a * s1);
    }
    return 0;
}
