#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

#define pb push_back
#define f first
#define s second

using std::string;
using std::vector;
using std::map;
using std::stack;
using std::cin;
using std::cout;

int main() {
    char symb, psymb;
    stack <char> st;
    stack<std::pair<string, int>> ans;
    vector<char> temp;
    map<char, int> prior = {{'/', 1}, {'*', 1}, {'+', 2}, {'-', 2}, {'&', 3},
    {'^', 4}, {'|', 5}};
    while (cin >> symb) {
        if (prior.find(symb) != prior.end()) {
            if (!st.empty()) {
                psymb = st.top();
                while(prior.find(psymb) != prior.end() && prior[symb] >= prior[psymb]) {
                    st.pop();
                    temp.pb(psymb);
                    if (!st.empty()) {
                        psymb = st.top();
                    } else {
                        break;
                    }
                }
            }
            st.push(symb);
        } else if (symb == ')') {
            while (st.top() != '(') {
                char ad = st.top();
                temp.pb(ad);
                st.pop();
            }
            st.pop();
        } else if (symb == '(') {
            st.push(symb);
        } else {
            temp.pb(symb);
        }
    }
    while (!st.empty()) {
        symb = st.top();
        temp.pb(symb);
        st.pop();
    }
    for (char symb: temp) {
        if (prior.find(symb) != prior.end()) {
            auto el1 = ans.top();
            ans.pop();
            auto el2 = ans.top();
            ans.pop();
            if (el1.s >= prior[symb] && el2.s > prior[symb]) {
                ans.push({'(' + el2.f + ')' + symb + '(' + el1.f + ')', prior[symb]});
            } else if (el2.s > prior[symb]) {
                ans.push({'(' + el2.f + ')' + symb + el1.f, prior[symb]});
            } else if (el1.s >= prior[symb]) {
                ans.push({el2.f + symb + '(' + el1.f + ')', prior[symb]});
            } else {
                ans.push({el2.f + symb + el1.f, prior[symb]});
            }
        } else {
            std::string str;
            str.append(1, symb);
            ans.push({str, 0});
        }
    }
    cout << ans.top().f << "\n";
    return 0;
}