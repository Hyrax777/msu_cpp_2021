#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>

using std::cout;
using std::string;

enum {
    SIZE = 40,
};

namespace numbers {

    class complex {
    private:
        double _frst, _scnd;
    public:
        complex(double frst = 0, double scnd = 0): _frst(frst), _scnd(scnd) {}

        explicit complex(string s) {
            int post = s.find(',');
            _frst = std::stod(s.substr(1, post));
            _scnd = std::stod(s.substr(post + 1));
        }

        explicit complex(const char *s) {
            string st = static_cast<string>(s);
            int post = st.find(',');
            _frst = std::stod(st.substr(1, post));
            _scnd = std::stod(st.substr(post + 1));
        }

        double re() const {
            return _frst;
        }

        double im() const {
            return _scnd;
        }

        double abs2() const {
            return _frst*_frst + _scnd*_scnd;
        }

        double abs() const {
            return sqrt(_frst*_frst + _scnd*_scnd);
        }

        string to_string() const {
            char str[SIZE];
            std::snprintf(str, SIZE, "(%.10g,%.10g)", _frst, _scnd);
            return str;
        }

        void to_string(char *buf, size_t size) const {
            std::snprintf(buf, size, "(%.10g,%.10g)", _frst, _scnd);
        }

        complex& operator+=(complex ex) {
            _frst += ex._frst;
            _scnd +=  ex._scnd;
            return *this;
        }

        complex& operator-=(complex ex) {
            _frst -= ex._frst;
            _scnd -=  ex._scnd;
            return *this;
        }

        complex& operator*=(complex ex) {
            double temp  = _frst;
            _frst = _frst * ex._frst - _scnd * ex._scnd;
            _scnd = temp * ex._scnd + _scnd * ex._frst;
            return *this;
        }

        complex& operator/=(complex ex) {
            double temp  = _frst;
            _frst = (_frst * ex._frst + _scnd * ex._scnd) / (ex._frst * ex._frst + ex._scnd * ex._scnd);
            _scnd = (_scnd * ex._frst - temp * ex._scnd) / (ex._frst * ex._frst + ex._scnd * ex._scnd);
            return *this;
        }

        complex operator~() const {
            complex tmp(_frst, -_scnd);
            return tmp;            
        }

        complex operator-() const {
            complex tmp(-_frst, -_scnd);
            return tmp;
        }

    };

    complex operator*(const complex& a, const complex& b) {
        complex tmp = a;
        tmp *= b;
        return tmp;

    }

    complex operator-(const complex& a, const complex& b) {
        complex tmp = a;
        tmp -= b;
        return tmp;
    }

    complex operator+(const complex& a, const complex& b) {
        complex tmp = a;
        tmp += b;
        return tmp;
    }

    complex operator/(const complex& a, const complex& b) {
        complex tmp = a;
        tmp /= b;
        return tmp;
    }

};
