#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 101> a{};
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i];
    }
    int i = 0, ans = 0;
    if (cnt == n) {
        cout << cnt - 1;
        return 0;
    }
    while (i < n) {
        if (a[i]) {
            i++;
            continue;
        }
        int j = i + 1, cur = 1;
        ans = max(ans, cnt + 1);
        while (cur && j < n) {
            if (a[j] == 0) cur++;
            else cur--;
            ans = max(ans, cnt + cur);
            j++;
        }
        i = j;
    }
    cout << ans;
    return 0;
}
