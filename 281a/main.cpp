#include <iostream>
using namespace std;

int main() {
    string st;

    cin >> st;
    st[0] = static_cast<char>(toupper(st[0]));
    cout << st;

    return 0;
}
