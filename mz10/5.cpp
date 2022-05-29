#include <iostream>
#include <string>

using std::string;
using std::cout;

int main() {
    int no_rul = 1, only_term = 1, no_s = 1;
    int eps = 0, eps_s = 0, right_s = 0;
    int l_1 = 1;
    string inp1, inp2;
    while (std::cin >> inp1 >> inp2) {
        no_rul = 0;
        if (inp1 == "S") {
            no_s = 0;
        }
        only_term = 1;
        for (char symb: inp1) {
            if ((symb >= 'A') && (symb <= 'Z')) {
                only_term = 0;
                break;
            }
        }
        if (only_term == 1) {
            break;
        }
        if (inp2 == "_") {
            if (inp1 == "S") {
                eps_s = 1;
            } else {
                eps = 1;
            }
        }
        if (inp2.find('S') != std::string::npos) {
            right_s = 1;
        }
        if (inp1.size() > 1) {
            l_1 = 0;
        }
    }

    if (no_rul || only_term || no_s) {
        cout << -1 << "\n";
    } else if (l_1) {
        if (!eps && !(eps_s && right_s)) {
            cout << 23 << "\n";
        } else {
            cout << 2 << "\n";
        }
    } else {
        cout << 10 << "\n";
    }
    return 0;
}