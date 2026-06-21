#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    array<int, 101> a{};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.begin() + n);
    cout << a[n - 1] << " ";
    for (int i = 1; i <= n - 2; i++) cout << a[i] << " ";
    cout << a[0] << " ";
    return 0;
}
