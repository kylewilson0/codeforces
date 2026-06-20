#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int tot = (1 + n) * n / 2;
    m = m % tot;
    int i = 1;
    while (true) {
        if (m < i) break;
        m -= i;
        i++;
    }
    cout << m;
    return 0;
}
