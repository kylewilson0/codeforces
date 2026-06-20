#include <iostream>
#include <array>
using namespace std;

int main() {
    int n, sum = 0;
    array<int, 100> a{};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1) a[i] = 1;
        else a[i] = 0;
        sum += a[i];
    }
    if (sum & 1) cout << sum;
    else cout << n - sum;
    return 0;
}
