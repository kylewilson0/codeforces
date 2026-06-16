#include <iostream>
using namespace std;

constexpr int N = 52;

int main() {
    string a, b;
    int cnt_a[N] = {0}, cnt_b[N] = {0};
    getline(cin, a);
    getline(cin, b);
    for (const auto &c: a) {
        if (c >= 'a' && c <= 'z') cnt_a[c - 'a']++;
        else if (c >= 'A' && c <= 'Z') cnt_a[c - 'A' + 26]++;
    }
    for (const auto &c: b) {
        if (c >= 'a' && c <= 'z') cnt_b[c - 'a']++;
        else if (c >= 'A' && c <= 'Z') cnt_b[c - 'A' + 26]++;
    }
    for (int i = 0; i < N; i++) {
        if (cnt_a[i] < cnt_b[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
