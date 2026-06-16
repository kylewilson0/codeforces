#include <iostream>
using namespace std;
const int N = 5;

int a[N][N], b[N], ans = 0;

int calc() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        int j = i;
        while (j < N - 1) {
            ret += a[b[j]][b[j + 1]] + a[b[j + 1]][b[j]];
            j += 2;
        }
    }
    return ret;
}

void permute(int left, int right) {
    if (left == right) {
        ans = max(ans, calc());
    }
    for (int i = left; i <= right; i++) {
        swap(b[left], b[i]);
        permute(left + 1, right);
        swap(b[left], b[i]);
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> a[i][j];
        b[i] = i;
    }
    permute(0, 4);
    cout << ans;
    return 0;
}
