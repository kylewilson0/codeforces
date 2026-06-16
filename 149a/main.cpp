#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int k, a[12], height = 0;
    cin >> k;
    for (int &i: a) cin >> i;
    sort(a, a + 12, greater<int>());;
    int i = 0;
    while (i < 12) {
        if (height >= k) break;
        height += a[i];
        i++;
    }
    if (height >= k) cout << i;
    else cout << -1;
    return 0;
}
