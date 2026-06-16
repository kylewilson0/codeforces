#include <iostream>
#include <algorithm>
using namespace std;

#define N 1001

struct Node {
    int x, y;
};

Node dragon[N];

int main() {
    int s, n;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        cin >> dragon[i].x >> dragon[i].y;
    }
    auto comparator = [](const Node &a, const Node &b) {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.y > b.y;
    };
    sort(dragon, dragon + n, comparator);
    int i = 0;
    for (; i < n; i++) {
        if (s > dragon[i].x) {
            s += dragon[i].y;
        } else break;
    }
    if (i == n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
