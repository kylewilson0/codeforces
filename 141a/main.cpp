#include <iostream>

int main() {
    freopen("a.in", "r", stdin);
    char a[26] = {0}, b[26] = {0}, ch;

    for (int i = 0; i < 2; i++) {
        while (scanf("%c", &ch) != EOF && ch != '\n') a[ch - 'A']++;
    }

    while (scanf("%c", &ch) != EOF && ch != '\n') b[ch - 'A']++;

    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            printf("%s", "NO");
            return 0;
        }
    }
    printf("%s", "YES");
    return 0;
}
