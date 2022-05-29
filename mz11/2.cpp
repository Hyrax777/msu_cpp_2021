#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

#define pb push_back

using std::string;
using std::vector;
using std::set;

int main() {
    string lp, rp;
    std::map<char, vector<int>> dict;
    vector<string> pfl, pfr;
    set<char> st;
    int i = 0;
    while (std::cin >> lp >> rp) {
        char fsym = lp[0];
        dict[fsym].pb(i++);
        pfl.pb(lp);
        pfr.pb(rp);
        st.insert(fsym);
    }
    set<char> st2 = {'S'};
    set<char> ear = st2;
    for (i = 0; i < ssize_t(st.size()); ++i) {
        set<char> st3;
        for (char el: ear) {
            const auto& t = dict[el];
            for (int j: t) {
                string rpr = pfr[j];
                for (char symb: rpr) {
                    if ((symb <= 'Z') && (symb >= 'A')) {
                        st3.insert(symb);
                    }
                }
            }
        }
        for (char el: st3) {
            st2.insert(el);
        }
        ear = st3;
    }

    for (char symb: st2) {
        const auto& t = dict[symb];
        for (int j: t) {
            std::cout << pfl[j] << " " << pfr[j] << '\n';
        }
    }

    return 0;
}