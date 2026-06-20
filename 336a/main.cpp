#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x > 0) {
        if (y > 0) printf("%d %d %d %d", 0, x + y, x + y, 0);
        else printf("%d %d %d %d", 0, -x + y, x - y, 0);
    } else {
        if (y > 0) printf("%d %d %d %d", x - y, 0, 0, -x + y);
        else printf("%d %d %d %d", x + y, 0, 0, x + y);
    }
    return 0;
}
