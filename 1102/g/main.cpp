#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
constexpr int N = 1e5 + 1;
int n, a[N];
bool f[N][N];

struct Node {
    int l, r;

    bool operator <(const Node &a) const {
        if (l != a.l) return l < a.l;
        return r < a.r;
    }
};

void process() {
    vector<vector<int> > losing;
    for (int i = 1; i <= n; i++) {
        losing[i].emplace_back(n + 1);
    }

    int cur = n;
    while (cur >= 0) {
        map<int, Node> map1;
        map<int, Node> map2;

        int w = 1;
        while (w <= n) {
            int start = w, end = w;
            while (cur + end >= losing[end][losing.size() - 1] && end <= n) {
                end++;
            }

            if (end > start) {
                map1.emplace(start, Node{start, end - 1});
            }


            w++;
        }
        for (int w = 1; w <= n; w++) {
            bool found = false;
            for (int i = losing[w].size() - 1; i >= 0; i--) {
                if (cur + w >= losing[w][i]) {
                    found = true;
                    break;
                }
            }
            if (found) {
                losing[w].emplace_back(cur);
            }
        }


        cur--;
    }
    // for (auto i: losing) {
    //     cout << i.size() << endl;
    //     for (auto j: i) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
}

// bool operator<(const Node &a,const Node &b){
//     return a.l<b.l;
// }
int main() {
    freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        // process();
    }

    set<pair<int, Node>, greater<> > test;
    test.emplace(1, Node{2, 3});
    test.emplace(1, Node{2, 1});
    test.emplace(2, 1);

    const auto it = test.upper_bound({1, Node{2, 2}});
    if (it != test.end()) {
        cout << "find " << it->first << " " << it->second.l << " " << it->second.r << endl;
    }
    test.erase(it);


    // test.emplace(2, "a");
    // test.emplace(0, "abb");
    for (const auto &[l, r]: test) {
        cout << l << " " << r.l << " " << r.r << endl;
    }
    cout << test.size() << endl;

    map<string, Node> map;
    map.emplace("a", Node{1, 1});
    map.emplace("b", Node{2, 1});

    for (const auto &[fst, snd]: map) {
        cout << fst << " " << snd.l << endl;
    }
    return 0;
}

void process1() {
    for (int i = 1; i <= n; ++i) {
        f[n - 1][i] = true;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            if (j + a[i] >= n - i) {
                f[i][j] = true;
                continue;
            }
            f[i][j] = false;
            // f[t][j] = 1 - f[1 - t][j];
            for (int k = i + 1; k <= min(i + j, n - 1); k++) {
                // int w = max(1, j - a[i]);
                if (f[k][j] == 0) {
                    f[i][j] = true;
                    // else f[t][k] = 1;
                    break;
                }
            }

            for (int k = i + j + 1; k <= min(i + j + a[i], n - 1); k++) {
                // int w = max(1, j - a[i]);
                if (f[k][j + k - i - j] == 0) {
                    f[i][j] = true;
                    // else f[t][k] = 1;
                    break;
                }
            }
        }
        // for (int j = 1; j <= n; j++) {
        //     printf("%d ", f[i][j]);
        // }
        // cout << endl;
    }
    cout << (f[0][1] ? 1 : 2) << endl;
}
