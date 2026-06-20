#include <iostream>
using namespace std;

int main() {
    int t, a;
    cin >> t;
    while (t--) {
        cin >> a;
        if (360 % (180 - a)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
