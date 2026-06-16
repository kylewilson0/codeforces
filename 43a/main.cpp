#include <iostream>
using namespace std;

int main() {
    string a, b, s;
    int n, cnt_a = 1, cnt_b = 0;
    cin >> n;
    cin >> a;
    for (int i = 1; i < n; i++) {
        cin >> s;
        if (s == a) cnt_a++;
        else {
            cnt_b++;
            if (b.empty()) b = s;
        }
    }
    cout << (cnt_a > cnt_b ? a : b) << endl;
    return 0;
}
