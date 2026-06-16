#include <iostream>

using namespace std;

int main() {
    string st;
    cin >> st;

    int lower = 0;
    for (char c: st) {
        if (c >= 'a' && c <= 'z') {
            lower++;
        }
    }
    if (st.size() - lower > lower) {
        for (char &c: st) {
            c = static_cast<char>(toupper(c));
        }
    } else {
        for (char &c: st) {
            c = static_cast<char>(tolower(c));
        }
    }
    cout << st << endl;
    return 0;
}
