#include <iostream>
#include <string>

/*
тип языка 1

вид грамматики a^n 0^m b^n 1^m
*/

using std::string;
using std::cout;

int main() {
    string inp;
    while(std::cin >> inp) {
        int ok = 1;
        int n1 = 0, n2 = 0, m1 = 0, m2 = 0;
        int n = inp.size();

        if (inp[0] != 'a') {
            ok = 0;
        }
        while ((inp[n1++] == 'a') && (n1 <= n)) {}

        
        if ((n1 <= n) && (inp[n1-- - 1] != '0')) {
            ok = 0;
        }
        while ((inp[n1 + m1++] == '0') && (n1 + m1 <= n)) {}

        if ((n1 + m1 <= n) && (inp[n1 + m1-- - 1] != 'b')) {
            ok = 0;
        }
        while ((inp[n1 + m1 + n2++] == 'b') && (n1 + m1 + n2 <= n)) {}

        if ((n1 + m1 + n2 <= n) && (inp[n1 + m1 + n2-- - 1] != '1')) {
            ok = 0;
        }
        while ((inp[n1 + m1 + n2 + m2++] == '1') && (n1 + m1 + n2 + m2 <= n)) {}
        --m2;
        
        if ( (!((n1 == n2) && (m1 == m2))) || (n1 == 0) || (m1 == 0) || (n1 + m1 + n2 + m2 != n)) {
            ok = 0;
        }

        std::cout << ok << "\n";
    }
    return 0;
}