#include <iostream>
#include <array>
using namespace std;
constexpr int N = 1e5 + 1;

int main() {
    string st;
    array<int, N> a{};
    cin >> st;
    for (int i = 1; i < st.size(); ++i) {
        if (st[i - 1] == st[i]) {
            a[i] = a[i - 1] + 1;
        } else {
            a[i] = a[i - 1];
        }
    }
    int m, l, r;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        l--, r--;
        cout << a[r] - a[l] << endl;
    }
    return 0;
}
