#include <iostream>
#include <array>

using namespace std;
constexpr int N = 1e5 + 1;

array<int, N> a{};

int main() {
    int n, m, t, x, y, delta = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m--) {
        cin >> t;
        switch (t) {
            case 1:
                cin >> x >> y;
                a[x] = y - delta;
                break;
            case 2:
                cin >> x;
                delta += x;
                break;
            default:
                cin >> x;
                cout << a[x] + delta << endl;
        }
    }
    return 0;
}
