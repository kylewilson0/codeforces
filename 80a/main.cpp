#include <iostream>
using namespace std;

bool isPrime(const int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    int next_prime = 0;
    for (int i = n + 1; i <= m; i++) {
        if (isPrime(i)) {
            next_prime = i;
            break;
        }
    }
    cout << (next_prime == m ? "YES" : "NO") << endl;
    return 0;
}
