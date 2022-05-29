#include <iostream>

using std::cin;
using std::cout;

void print_bc(int c) {
    if (c == 1) {
        cout << "bc";
        return;
    }
    cout << "b";
    print_bc(c - 1);
    cout << "c";
}

void print_ad(int a, int b) {
    if (a == 0) {
        print_bc(b);
        return;
    }
    cout << "a";
    print_ad(a - 1, b);
    cout << "d";   
}

void rec(int l, int a) {
    if (l <= 0) {
        return;
    }
        print_ad(l, a - l);
    cout << "\n";
    rec(l - 1, a);
}

int main() {
    int k;
    cin >> k;
    if (k % 2 == 0) {
        rec(k / 2 - 1, k/2);
    }
    return 0;
}