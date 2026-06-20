#include <iostream>
#include <vector>
using namespace std;

#define int long long

using Matrix = vector<vector<int> >;
constexpr int MOD = 1e9 + 7;

Matrix multiply(Matrix &a, Matrix &b) {
    int row = a.size(), col = b[0].size();
    Matrix c(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] += (a[i][k] * b[k][j] % MOD + MOD) % MOD;
            }
        }
    }
    return c;
}

Matrix mPow(Matrix &a, int b) {
    int n = a.size();
    Matrix res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    while (b > 0) {
        if (b & 1) {
            res = multiply(res, a);
        }
        a = multiply(a, a);
        b >>= 1;
    }
    return res;
}

signed main() {
    freopen("a.in", "r", stdin);
    int x, y, n;
    cin >> x >> y >> n;
    vector<vector<int> > a = {
        {1, 1},
        {-1, 0}
    };
    Matrix c = mPow(a, n - 1);
    int ans = ((c[0][1] * y + c[1][1] * x) % MOD + MOD) % MOD;
    cout << ans;
    return 0;
}
