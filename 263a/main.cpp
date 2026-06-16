#include <iostream>
using namespace std;

int main() {
    freopen("a.in", "r",stdin);
    freopen("a.out", "w",stdout);

    int x;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            cin >> x;
            if (x == 1) {
                cout << abs(i - 2) + abs(j - 2) << endl;
            }
        }
    return 0;
}
