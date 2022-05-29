#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>

using std::cin;
using std::cout;
using std::string;

class Date {
private:
    string _year, _month, _day, mainstr;
public:
    Date(string str) {
        std::stringstream ss;
        ss << str;
        getline(ss, _year, '/');
        getline(ss, _month, '/');
        getline(ss, _day, '/');
        char buf[30];
        snprintf(buf, 30, "%04d/%02d/%02d", std::stoi(_year),  std::stoi(_month),  std::stoi(_day));
        mainstr = buf;
    }
    string get_string(){
        return mainstr;
    }


};

int main() {
    string st_surn, st_date;
    int mark;
    std::map<std::pair<string, string>, int> mp;
    std::set<string> surn;
    std::set<string> dt;
    while (cin >> st_surn >> st_date >> mark) {
        st_date = Date(st_date).get_string();
        mp[make_pair(st_surn, st_date)] = mark;
        surn.insert(st_surn);
        dt.insert(st_date);
    }
    cout << ". ";
    for (auto it: dt) {
        cout << it << " ";
    }
    cout << "\n";
    for (auto it1: surn) {
        cout << it1 << " ";
        for (auto it2: dt) {
            if (mp.find(make_pair(it1, it2)) != mp.end()) {
                cout << mp[make_pair(it1, it2)] << " ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
    return 0;
}