#include <iostream>
using namespace std;

int main() {
    int n, t, a[2] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        switch (t) {
            case 25:
                a[0]++;
                break;
            case 50:
                a[0]--, a[1]++;
                break;
            case 100:
                if (a[1] > 0) {
                    a[0]--, a[1]--;
                } else {
                    a[0] -= 3;
                }
                break;
        }
        if (a[0] < 0 || a[1] < 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
