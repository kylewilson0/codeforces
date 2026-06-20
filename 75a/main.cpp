#include <iostream>
using namespace std;

int remove(int n) {
    int ret = 0, j = 1;;
    while (n) {
        if (n % 10) {
            ret += n % 10 * j;
            j *= 10;
        }
        n /= 10;
    }
    return ret;
}

int main() {
    int a, b;
    cin >> a >> b;
    bool ok = remove(a) + remove(b) == remove(a + b);
    cout << (ok ? "YES" : "NO");
    return 0;
}
