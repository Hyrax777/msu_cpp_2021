#include <iostream>

using std::cin;
using std::cout;

enum
{
    THR = 4, // порог
};


int main() {
    char a, start = '0';
    int count = 0;
    if (cin.get(start)) {
        ++count;
    }
    while ((cin.get(a)) && (!cin.eof())) {
        if (a == start) {
            ++count;
        } else {
            if ((count > THR) || (start == '#')) {
                cout << '#' << start << std::hex << count << '#';
                count = 0;
            } else {
                for (int i = 0; i < count; i++) {
                    cout << start;
                }
            }
            count = 1;
            start = a;
        }
    }
    if (count) {
        if ((count > THR) || (start == '#')) {
            cout << '#' << start << std::hex << count << '#';
        } else {
            for (int i = 0; i < count; i++) {
                cout << start;
            }
        }
    }
    return 0;
}