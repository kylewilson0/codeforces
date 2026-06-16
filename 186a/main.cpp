#include <iostream>
using namespace std;
string a, b;
int pos[2], tot = 0;

bool isOk() {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            if (tot == 2) {
                return false;
            }
            pos[tot++] = i;
        }
    }
    return a[pos[0]] == b[pos[1]] && a[pos[1]] == b[pos[0]];
}

int main() {
    cin >> a >> b;
    if (isOk()) cout << "YES";
    else cout << "NO";
    return 0;
}
