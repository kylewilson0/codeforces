#include <iostream>
#include <array>

using namespace std;

int main() {
    int n, m, a, b;
    array<bool, 1001> flag{};
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        flag[a] = true;
        flag[b] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!flag[i]) {
            cout << n - 1 << endl;
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    cout << i << " " << j << endl;
                }
            }
            break;
        }
    }
    return 0;
}
