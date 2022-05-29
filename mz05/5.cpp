#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;

int main() {
    std::list<long long> lst;
    long long exm, exm2;
    int ct = 0;
    while ((cin >> exm) && (exm != 0)) {
        lst.push_back(exm);
    }
    while (cin >> exm) {
        if (exm < 0) {
            if (abs(exm) <= ssize_t(lst.size())) {
                auto it = lst.begin();
                for (ct = 1; ct < abs(exm) ; ++ct){
                    ++it;
                }
                lst.erase(it);
            }
        } else {
            cin >> exm2;
            if (exm <= ssize_t(lst.size())) {
                auto it = lst.begin();
                for (ct = 1; ct < exm ; ++ct){
                    ++it;
                }
                lst.insert(it, exm2);
            } else {
                lst.push_back(exm2);
            }
        }
    }
    for (auto i: lst) {
        std::cout << i << "\n";
    }
    return 0;
}