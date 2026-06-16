#include <iostream>
using namespace std;

int main() {
    int m, n;
    freopen("a.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char ch;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            if (ch == '.') {
                if (i + j & 1) cout << "W";
                else cout << "B";
            } else {
                cout << ch;
            }
        }
        cout << endl;
    }
    return 0;
}
