#include <iostream>
using namespace std;
int t;
long long n;

void process() {
    cin >> n;
    if (n == 10) {
        cout << -1 << endl;
        return;
    }
    long long r = n % 12, a;
    if (r <= 9) {
        a = r;
    } else if (r == 10) {
        a = 22;
    } else {
        a = 11;
    }
    cout << a << " " << n - a << endl;;
}

int main() {
    cin >> t;
    while (t--) process();
    return 0;
}
