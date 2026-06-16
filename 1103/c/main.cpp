#include <iostream>
using namespace std;

int solve(int a, int b, int x) {
    int ma[33], mb[33], cnt_a = 0, cnt_b = 0, ans = INT_MAX;
    ma[cnt_a++] = a;
    mb[cnt_b++] = b;
    while (a) ma[cnt_a++] = a = a / x;
    while (b) mb[cnt_b++] = b = b / x;
    for (int i = 0; i < cnt_a; i++) {
        for (int j = 0; j < cnt_b; j++) {
            ans = min(ans, i + j + abs(ma[i] - mb[j]));
        }
    }
    return ans;
}

int main() {
    freopen("a.in", "r", stdin);
    int t, a, b, x;
    cin >> t;
    while (t--) {
        cin >> a >> b >> x;
        printf("%d\n", solve(a, b, x));
    }
    return 0;
}
