#include <iostream>
using namespace std;
#define LOCAL

void solve(string &st, string &ans) {
    int i = 0, sz = st.size();
    while (i < sz) {
        int j = i + 1;
        while (j < sz && st[i] == st[j]) j++;
        if (j - i == 1) {
            ans += st[i];
            i = j;
        } else {
            int len = ans.size();
            if (len >= 2 && ans[len - 1] == ans[len - 2]) {
                ans += st[i];
                i = j;
            } else {
                ans += st.substr(i, 2);
                i = j;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string st, ans;
    cin >> st;
    solve(st, ans);
    cout << ans;
    return 0;
}
