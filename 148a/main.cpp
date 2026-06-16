#include <iostream>
using namespace std;

bool flag[100001] = {false};
int d;

void filter(int s) {
    for (int i = 1; i * s <= d; i++) {
        flag[i * s] = true;
    }
}

int main() {
    int a[4], ans = 0;
    for (int &i: a) cin >> i;
    cin >> d;
    for (int &i: a) filter(i);

    for (int i = 1; i <= d; i++) {
        if (flag[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
