#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int j = -1;
    for (int i = 0; i <= 9; i++) {
        if ((a * 10 + i) % b == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        cout << -1;
        return 0;
    }
    cout << a * 10 + j;
    for (int i = 1; i < n; i++) cout << 0;
    return 0;
}
