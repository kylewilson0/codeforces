#include <iostream>
using namespace std;

int main() {
    int a[4], have = 1;
    for (int &i: a) cin >> i;
    for (int i = 1; i < 4; i++) {
        bool same = false;
        for (int j = 0; j < i; j++) {
            if (a[j] == a[i]) {
                same = true;
                break;
            }
        }
        if (!same) have++;
    }
    cout << 4 - have << endl;
    return 0;
}
