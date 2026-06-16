#include <iostream>
using namespace std;

int main() {
    string st;
    cin >> st;
    int i = 0;
    while (i < st.size()) {
        if (st[i] == '.') {
            cout << 0;
        } else if (st[i] == '-' && st[i + 1] == '.') {
            i++;
            cout << 1;
        } else if (st[i] == '-' && st[i + 1] == '-') {
            i++;
            cout << 2;
        }
        i++;
    }
    return 0;
}
