#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    int n;
    char ch;
    array<int, 101> a = {}, b = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        a[i] = ch - '0';
    }
    for (int i = 0; i < n; i++) {
        cin >> ch;
        b[i] = ch - '0';
    }
    sort(a.begin(), a.begin() + n);
    sort(b.begin(), b.begin() + n);

    bool less = true;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i]) {
            less = false;
            break;
        }
    }
    if (less) {
        cout << "YES";
        return 0;
    }
    bool more = true;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) {
            more = false;
            break;
        }
    }
    if (more) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}
