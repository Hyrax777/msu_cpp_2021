#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::make_pair;

#define f first 
#define s second

unsigned int MOD = 4294967161;

int main() {
    std::map<std::pair<unsigned int, unsigned int>, unsigned long long> mp;
    unsigned int r, c, v;
    while (cin >> r >> c >> v) {
        if ((r == 0) && (c == 0) && (v == MOD)) {
            break;
        }
        mp[make_pair(r, c)] = v % MOD;
    }
    while (cin >> r >> c >> v) {
        mp[make_pair(r, c)] += v % MOD;
        mp[make_pair(r, c)] %= MOD;
    }
    cout << "\n";
    for(const auto &[key, value]: mp){
        if(value != 0){
            cout << key.f << " " << key.s << " " << value << "\n";
        }
    }
    return 0;
}