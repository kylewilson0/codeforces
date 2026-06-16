#include <iostream>
using namespace std;

int main() {
    string st;
    cin >> st;

    int i = 0;
    while (i < st.size()) {
        if ("144" == st.substr(i, 3)) {
            i += 3;
        } else if ("14" == st.substr(i, 2)) {
            i += 2;
        } else if ("1" == st.substr(i, 1)) {
            i += 1;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
