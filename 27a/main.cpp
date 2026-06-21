#include <iostream>
#include <array>
using namespace std;

int main() {
    int n, t;
    array<bool, 3001> a{};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            cout << i;
            return 0;
        }
    }
    cout << n + 1;
    return 0;
}
