#include <iostream>
using namespace std;

int main() {
    string st;
    int a[26] = {0}, odd = 0;
    cin >> st;
    for (auto &c: st) {
        a[c - 'a']++;
    }
    for (int i: a) {
        if (i & 1) odd++;
    }
    if (odd <= 1 || (odd & 1) == 1) cout << "First";
    else cout << "Second";
    return 0;
}
