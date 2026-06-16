#include <iostream>
using namespace std;

int main() {
    string st;;
    int a[3] = {0}, cur = 0, len = 0;
    cin >> st;
    for (const auto ch: st) {
        if (ch >= '1' && ch <= '3') {
            a[ch - '1']++;
            len++;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << i + 1;
            cur++;
            if (cur != len) cout << '+';
        }
    }

    return 0;
}
