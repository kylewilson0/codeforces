#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n, x, y;
    cin >> n >> x >> y;
    cout << max(0, static_cast<int>(ceil(n * y / 100 - x)));
    return 0;
}
