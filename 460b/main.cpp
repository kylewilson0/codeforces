#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int cal(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main() {
    int a, b, c;
    vector<int> ans{};
    cin >> a >> b >> c;
    for (int i = 1; i <= 81; i++) {
        int x = b * pow(i, a) + c;
        if (x > 0 && x < 1e9 && cal(x) == i) {
            ans.push_back(x);
        }
    }
    cout << ans.size() << endl;
    for (auto &i: ans) cout << i << " ";
    return 0;
}
