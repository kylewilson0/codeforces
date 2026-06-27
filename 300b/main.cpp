#include <iostream>
#include <array>
#include <vector>

using namespace std;
constexpr int N = 1e2;

array<int, N> stu{};
vector<vector<int> > gro(N);
int group_idx = 0, three = 0, two = 0, n;

bool Solve() {
    int m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (stu[a] && stu[b]) {
            if (stu[a] != stu[b]) return false;
            continue;
        }
        if (!stu[a] && !stu[b]) {
            group_idx++;
            gro[group_idx].push_back(a);
            gro[group_idx].push_back(b);
            stu[a] = stu[b] = group_idx;
            two++;
        } else {
            if (stu[a]) {
                stu[b] = stu[a];
                gro[stu[a]].push_back(b);
            } else {
                stu[a] = stu[b];
                gro[stu[a]].push_back(a);
            }
            if (gro[stu[a]].size() > 3) return false;
            three++, two--;
        }
    }
    if (two && n - 3 * three - 2 * two < two) return false;
    int j = 1;
    for (int i = 1; i <= n; i++) {
        if (!stu[i]) {
            while (gro[j].size() == 3) j++;
            stu[i] = j;
            gro[j].push_back(i);
        }
    }
    return true;
}

int main() {
    freopen("a.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    if (!Solve()) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n / 3; i++) {
        for (int j: gro[i]) cout << j << " ";
        cout << endl;
    }
    return 0;
}
