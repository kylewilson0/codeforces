#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N = 1e5 + 1;

struct Node {
    int val, index;
};

int n, cnt = 0, x[N], p[N];
Node a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].val;
        a[i].index = i;
    }
    auto comparator = [](const Node &a, const Node &b) -> bool {
        if (a.val != b.val) return a.val < b.val;
        return a.index < b.index;
    };
    sort(a, a + n, comparator);
    int i = 0;
    while (i < n) {
        int j = i + 1, delta = 0;
        bool flag = true;
        while (j < n && a[j].val == a[i].val) {
            if (j == i + 1) delta = a[j].index - a[j - 1].index;
            else {
                if (a[j].index - a[j - 1].index != delta) {
                    flag = false;
                }
            }
            j++;
        }
        if (flag) {
            x[cnt] = a[i].val;
            p[cnt] = delta;
            cnt++;
        }
        i = j;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << x[i] << " " << p[i] << endl;
    }
    return 0;
}
