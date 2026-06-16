#include <iostream>

int main() {
    char ch;
    while (scanf("%c", &ch) != EOF && ch != '\n') {
        if (ch == 'H' || ch == 'Q' || ch == '9') {
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
    return 0;
}
