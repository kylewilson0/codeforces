#include <iostream>
#include <cmath>

using namespace std;

bool isLucky(int num) {
    while (num) {
        int t = num % 10;
        if (t != 4 && t != 7) return false;
        num /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (isLucky(i) || isLucky(n / i)) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
