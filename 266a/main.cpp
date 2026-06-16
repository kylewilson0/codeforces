#include <iostream>
using namespace std;

int main() {
    int n;
    char st[51];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st[i];
    }
    int i = 0, ans = 0;
    while (i < n) {
        int j = i + 1;
        while (st[i] == st[j]) j++;
        if (j > i + 1) {
            ans += j - i - 1;
        }
        i = j;
    }
    cout << ans << endl;
    return 0;
}
