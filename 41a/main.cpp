#include <iostream>
using namespace std;

int main() {
    string a, b;
    bool equal = true;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[b.size() - i - 1]) {
            equal = false;
            break;
        }
    }

    cout << (equal ? "YES" : "NO");
    return 0;
}
