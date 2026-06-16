#include <iostream>
using namespace std;

int main() {
    string st;
    cin >> st;
    int num = 0;
    for (char c: st) {
        if (c == '4' || c == '7') {
            num++;
        }
    }
    string st_num = to_string(num);
    for (char c: st_num) {
        if (c != '4' && c != '7') {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
