#include <iostream>
using namespace std;
int n, t, cnt_1 = 0, cnt_2 = 0;

bool is_divide() {
    if (cnt_1 & 1) return false;
    if (cnt_1 == 0 && n & 1) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 100) cnt_1++;
        else if (t == 200) cnt_2++;
    }
    if (is_divide()) cout << "YES";
    else cout << "NO";
    return 0;
}
