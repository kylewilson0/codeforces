#include <iostream>
using namespace std;
int a[3][3], num;

const int dir[5][2] = {
    {0, 0}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}
};

void switchLight(int i, int j) {
    if ((num & 1) == 0) {
        return;
    }
    for (auto k: dir) {
        int x = i + k[0];
        int y = j + k[1];
        if (x >= 0 && x < 3 && y >= 0 && y < 3) {
            a[x][y] ^= 1;
        }
    }
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> num;
            switchLight(i, j);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
