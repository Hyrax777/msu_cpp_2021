#include <iostream>

using std::cin;
using std::cout;

int main() {
    int ok_swp = 0, ok_out = 0;
    char a;
    while ((a = getchar()) != EOF) {
        if (!((a >= '0') && (a <= '9'))) {
            if (ok_out) {
                cout << '0';
            }
            ok_swp = 0;
            ok_out =0;
            cout << a;
            continue;
        }
        if (!ok_swp) {
            if (a != '0') {
                ok_swp = 1;
                ok_out = 0;
                cout << a;
            } else {
                ok_out = 1;
            }
        } else {
            cout << a;
            ok_out = 0;
        }
    }
    if (ok_out) {
        cout << '0';
    }
    return 0;
}