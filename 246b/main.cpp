#include <iostream>
using namespace std;

int main() {
    int n, t, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        sum += t;
    }
    if (sum % n == 0) cout << n;
    else cout << n - 1;
    return 0;
}
