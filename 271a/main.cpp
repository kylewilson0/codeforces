#include <iostream>

using namespace std;

bool isDistinct(int x) {
    bool digit[10] = {false};
    while (x) {
        int num = x % 10;
        x /= 10;
        if (digit[num]) {
            return false;
        }
        digit[num] = true;
    }
    return true;;
}

int main() {
    int y;
    cin >> y;
    do {
        y++;
    } while (!isDistinct(y));
    cout << y << endl;
}
