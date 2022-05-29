#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::string;

#define f first 
#define s second


int main() {
    std::map<string,std::pair<int,int>>  mp;
    string surn;
    int scr;
    while (cin >> surn >> scr) {
        auto it = mp.find(surn);
        if (it != mp.end()) {
            mp[surn].f += scr;
            mp[surn].s += 1;
        } else {
            mp[surn].f = scr;
            mp[surn].s = 1;
        }
    }
    for (auto i: mp) {
        cout <<  i.f << " " << i.s.f / double(i.s.s) << "\n";
    }
    return 0;
}