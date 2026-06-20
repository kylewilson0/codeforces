#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            int t = (j - 1) * n + (i + j + n - 1) % n + 1;
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}
