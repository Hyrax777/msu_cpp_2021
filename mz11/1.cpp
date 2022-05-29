#include <iostream>
#include <string>

using std::string;
using std::cout;

int main() {
    int eps = 0, eps_s = 0, right_s = 0;
    int right_n1 = 1, right_t1 = 1, cnt = 0;
    int i, j, ons = 1, lside = 0, rside = 0;
    string alph_net = "ABCDEFGHIJKLMONPQRSTUVWXYZ";
    string alph_term = "abcdefghijklmonpqrstuvwxyz1234567890";
    string inp1, inp2;
    while (std::cin >> inp1 >> inp2) {
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
        i = 0;
        j = 0;
        for (char symb: inp2) {
            if (alph_net.find(symb) != std::string::npos) {
                ++i;
            }
            if (alph_term.find(symb) != std::string::npos) {
                ++j;
            }
        }
        if (i > 1) {
            right_n1 = 0;
        }
        if (j != 1) {
            if (!((inp2.size() == 1) && (inp2 == "_") && !right_s) && 
                !(inp2.size() == 1 && alph_net.find(inp2) != std::string::npos && inp1 == "S")){
                right_t1 = 0;
            }
            if (inp2.size() == 1 && alph_net.find(inp2) != std::string::npos && inp1 == "S") {
                ++cnt;
            }
        }
        if (alph_term.find(inp2[0]) != std::string::npos && inp2.size() != 1) {
            int ok = 0;
            for (char symb: inp2) {
                if (alph_net.find(symb) != std::string::npos) {
                    ok = 1;
                }
                if (ok && alph_term.find(symb) != std::string::npos) {
                    ons = 0;
                }
                if (ok) {
                    rside = 1;
                }
            }
        } else if (inp2.size() != 1) {
            lside = 1;
        }
    }

    if (right_n1 && ons && !(lside && rside)) {
        if (!rside) {
            if (right_t1 && !eps && (cnt <= 1) && !(eps_s && right_s)) {
                cout << 311 << "\n";
            } else {
                cout << 31 << "\n";
            }
        } else {
            if (right_t1 && !eps && (cnt <= 1) && !(eps_s && right_s)) {
                cout << 321 << "\n";
            } else {
                cout << 32 << "\n";
            }
        }
    } else {
        if (!eps && !(eps_s && right_s)) {
            cout << 21 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
    return 0;
}
