#include <iostream>
using namespace std;

int main() {
    int t, sx, sy, ex, ey;
    char ch;
    cin >> t >> sx >> sy >> ex >> ey;
    for (int i = 0; i < t; i++) {
        cin >> ch;
        switch (ch) {
            case 'E':
                if (sx < ex) sx++;
                break;
            case 'W':
                if (sx > ex) sx--;
                break;
            case 'N':
                if (sy < ey) sy++;
                break;
            case 'S':
                if (sy > ey) sy--;
                break;
        }
        if (sx == ex && sy == ey) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
