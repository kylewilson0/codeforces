#include <iostream>
using namespace std;

const char vowels[] = "aeiouyAEIOUY";

bool isVowel(char c) {
    for (char i: vowels) {
        if (c == i) {
            return true;
        }
    }
    return false;
}

int main() {
    string st;
    cin >> st;
    for (char i: st) {
        if (!isVowel(i)) {
            printf(".%c", tolower(i));
        }
    }
    return 0;
}
