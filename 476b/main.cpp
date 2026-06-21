#include <iomanip>
#include <iostream>
using namespace std;

string s1, s2;
int a = 0, b = 0, t = 0;

void dfs(int step, int pos, string &st) {
    if (step >= st.size()) {
        if (pos == t) a++, b++;
        else b++;
        return;
    }
    switch (st[step]) {
        case '+':
            dfs(step + 1, pos + 1, st);
            break;
        case '-':
            dfs(step + 1, pos - 1, st);
            break;
        default:
            dfs(step + 1, pos + 1, st);
            dfs(step + 1, pos - 1, st);
    }
}

void solve1() {
    dfs(0, 0, s2);
    double ans = static_cast<double>(a) / static_cast<double>(b);
    cout << setprecision(12) << fixed << ans;
}

int combination(int n, int a) {
    if (a > n - a) a = n - a;
    int ret = 1;
    for (int i = 1; i <= a; i++) {
        ret = ret * (n - a + i) / i;
    }
    return ret;
}

void solve2() {
    int s = 0, q_num = 0;
    for (char &c: s2) {
        if (c == '+') s++;
        else if (c == '-') s--;
        else q_num++;
    }
    int denominator = 1 << q_num, dis = abs(t - s);
    double ans = 0;
    if (q_num + dis & 1 || dis > q_num) {
        cout << setprecision(12) << fixed << ans;
        return;
    }
    int numerator = combination(q_num, (q_num + dis) / 2);
    ans = static_cast<double>(numerator) / static_cast<double>(denominator);
    cout << setprecision(12) << fixed << ans;
}

int main() {
    cin >> s1 >> s2;
    for (char &c: s1) {
        if (c == '+') t++;
        else t--;
    }
    solve2();
    return 0;
}
