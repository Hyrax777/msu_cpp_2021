#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::string_view;

int main() {
    string str;
    std::getline(std::cin, str);
    str.erase(str.find_last_not_of(" \n\r\t") + 1);
    int n = ssize_t(str.size());
    vector<string_view> pref;
    string_view s2 = str;
    for (int i = 0; i < n; ++i) {
        pref.push_back(s2.substr(i, n - i));
    }
    std::sort(pref.begin(), pref.end());
    for (int i = 0; i < ssize_t(pref.size()); ++i) {
        cout << n - pref[i].length() << "\n";
    }
    return 0;
}