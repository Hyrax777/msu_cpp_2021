#include <iostream>
#include <set>
#include <string>
#include <map>

using std::map;
using std::string;
using std::cin;
using std::cout;


int main() {
    int ok = 0, cnt = 0;
    string cur, nw;
    char wgt;
    std::set<string> term_st;
    map<std::pair<string, char>, string> dka;
    while (cin >>  cur) {
        if (cur != "END") {
            cin >> wgt >> nw;
            dka[{cur, wgt}] = nw;
        } else {
            break;
        }
    }
    for (; cin >> cur && cur != "END"; term_st.insert(cur));
    cin >> cur;
    while (cin >> wgt) {
        if (!ok) {
            if (dka.find({cur, wgt}) != dka.end()) {
                ++cnt;
                cur = dka[{cur, wgt}];
            } else {
                ok = 1;
            }
        } else {
            break;
        }
    }
    cout << (!ok && (term_st.find(cur) != term_st.end())) << " \n" << cnt << "\n" << cur << "\n";
    return 0;
}