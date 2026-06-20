#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > a(5e3 + 1);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> t;
        a[t].push_back(i + 1);
    }
    for (auto &i: a) {
        if (i.size() & 1) {
            cout << -1;
            return 0;
        }
    }
    for (auto &i: a) {
        for (int j = 0; j < i.size(); j++) {
            if (j & 1) cout << i[j] << endl;
            else cout << i[j] << " ";
        }
    }
    return 0;
}
