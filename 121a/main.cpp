#include <iostream>
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

void generate(int step, vector<int> num) {
    if (step > 9) return;
    for (auto &i: b) {
        num.push_back(i);
        lucky_num.push_back(sum(num));
        generate(step + 1, num);
        num.pop_back();
    }
}

signed main() {
    int l, r;
    cin >> l >> r;
    generate(0, {});
    sort(lucky_num.begin(), lucky_num.end());
    int j = 0, ans = 0;
    while (lucky_num[j] < l) j++;
    while (l <= r) {
        int num = min(lucky_num[j], r) - l + 1;
        ans += lucky_num[j] * num;
        l = lucky_num[j] + 1;
        j++;
    }
    cout << ans;
    return 0;
}
