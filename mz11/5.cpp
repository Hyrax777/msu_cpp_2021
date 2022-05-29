#include <iostream>
#include <string>
#include <stack>
 

int main() {
    std::string inp, outp = "";
    std::string el1, el2;
    std::stack<std::string> st;
    std::cin >> inp;
    int n = inp.size();
    for (int i = 0; i < n; ++i) {
        if ((inp[i] == '+') || (inp[i] == '-') || (inp[i] == '*') || (inp[i] == '/')) {
            el1 = st.top();
            st.pop();
            el2 = st.top();
            st.pop();
            st.push('(' + el2 + inp[i] + el1 + ')');
        } else if (inp[i] == ' ') {
            continue;
        } else {
            std::string symb;
            symb.append(1, inp[i]);
            st.push(symb);
        }
    }
    std::cout << st.top() << "\n";
    return 0;
}