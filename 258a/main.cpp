#include <iostream>
using namespace std;

int main() {
    string st;
    cin >> st;
    int zero = -1;
    for (int i = 0; i < st.size(); i++) {
        if (st[i] == '0') {
            zero = i;
            break;
        }
    }
    if (zero > -1) {
        cout << st.substr(0, zero) + st.substr(zero + 1, st.size()) << endl;
    } else {
        cout << st.substr(0, st.size() - 1);
    }
    return 0;
}
