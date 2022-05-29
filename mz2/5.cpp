#include <string>

using std::string;

class BinaryNumber
{
public:
    string str;
    BinaryNumber(const string &s) {
        str = s;
    };
    operator string () const {
        return str;
    };
    const BinaryNumber &operator++() {
        long long i = str.length() - 1;
        int ok = 0;
        while (i >= 0) {
            if (str[i] == '1') {
                str[i] = '0';
            } else {
                str[i] = '1';
                ok = 1;
                break;
            }
            --i;
        }
        if ((!ok)) {
            str.insert(0, "1");
        }
        return *this;
    };
};
