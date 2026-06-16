#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    string st;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st;
        if (st[1] == '+') ans++;
        else ans--;
    }
    cout << ans << endl;
    return 0;
}
