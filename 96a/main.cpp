#include <iostream>
using namespace std;

int main() {
    string st;
    cin >> st;

    int i = 0;
    while (i < st.size()) {
        int j = i + 1;
        while (j < st.size() && st[i] == st[j]) j++;
        if (j - i >= 7) {
            cout << "YES";
            return 0;
        }
        i = j;
    }
    cout << "NO";
    return 0;
}
