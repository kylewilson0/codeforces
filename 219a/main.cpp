#include <iostream>
using namespace std;;

int main() {
    int n, a[26] = {0}, b[26] = {0};
    char ch;

    cin >> n;
    getchar();
    while (scanf("%c", &ch) != EOF && ch != '\n') {
        a[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] % n != 0) {
            cout << -1 << endl;
            return 0;
        }
        b[i] = a[i] / n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < b[j]; k++) {
                printf("%c", j + 'a');
            }
        }
    }
    return 0;
}
