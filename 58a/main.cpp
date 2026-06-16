#include <iostream>
using namespace std;

int main() {
    string a;
    string b = "hello";
    cin >> a;
    int j = 0;
    for (auto &ch: a) {
        if (ch == b[j]) j++;
    }
    if (j == b.size()) cout << "YES";
    else cout << "NO";
    return 0;
}
