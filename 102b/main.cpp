#include <iostream>
using namespace std;

int main() {
    string st;
    cin >> st;
    if (st.size() == 1) {
        cout << 0;
        return 0;
    }
    int i = 1, sum = 0;
    for (const auto &ch: st) sum += ch - '0';
    while (sum >= 10) {
        int t = 0;
        while (sum) {
            t += sum % 10;
            sum /= 10;
        }
        sum = t;
        i++;
    }
    cout << i;
    return 0;
}
