#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

vector<int> b = {4, 7};
vector<int> lucky_num{};

int sum(vector<int> &num) {
    int ret = 0, j = 1;
    for (int i = num.size() - 1; i >= 0; i--) {
        ret += num[i] * j;
        j *= 10;
    }
    return ret;
}

bool is_super(vector<int> &num) {
    int a = 0, b = 0;
    for (auto &i: num) {
        if (i == 4) a++;
        else b++;
    }
    return a == b;
}

void generate(int step, vector<int> num) {
    if (step > 9) return;
    for (auto &i: b) {
        num.push_back(i);
        if (is_super(num)) lucky_num.push_back(sum(num));
        generate(step + 1, num);
        num.pop_back();
    }
}

signed main() {
    freopen("a.in", "r", stdin);
    generate(0, {});
    ranges::sort(lucky_num);
    int n;
    cin >> n;
    auto it = ranges::lower_bound(lucky_num, n);
    cout << *it;
    return 0;
}
