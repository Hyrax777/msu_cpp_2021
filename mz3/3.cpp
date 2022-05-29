#include <iostream>
#include <vector>
#include <map>
#include <functional>

using std::string;
using std::vector;

namespace numbers {
    complex eval(const vector<std::string> &args, const complex &z) {
        complex_stack stk;
        std::map<string, std::function<void()>> mp {
                {"z", [&stk, &z]() {stk = stk << z;}},
                {";", [&stk](){stk = ~stk;}},
                {"~", [&stk, &z](){
                    complex z1 = +stk;
                    stk = ~stk;
                    z1 = ~z1;
                    stk = stk << z1;}},
                {"!", [&stk](){stk = stk << (+stk);}},
                {"#", [&stk, &z](){
                    complex z1 = +stk;
                    stk = ~stk;
                    z1 = -z1;
                    stk = stk << z1;}},
                {"+", [&stk](){
                    complex z2 = +stk;
                    stk = ~stk;
                    complex z1 = +stk;
                    stk = ~stk;
                    z1 += z2;
                    stk = stk << z1;}},
                {"*", [&stk](){
                    complex z2 = +stk;
                    stk = ~stk;
                    complex z1 = +stk;
                    stk = ~stk;
                    z1 *= z2;
                    stk = stk << z1;}},
                {"-", [&stk](){
                    complex z2 = +stk;
                    stk = ~stk;
                    complex z1 = +stk;
                    stk = ~stk;
                    z1 -= z2;
                    stk = stk << z1;}},
                {"/", [&stk](){
                    complex z2 = +stk;
                    stk = ~stk;
                    complex z1 = +stk;
                    stk = ~stk;
                    z1 /= z2;
                    stk = stk << z1;}},
        };
        for (auto it: args) {
            if (it[0] == '(') {
                stk = stk << complex(it);
            } else {
                mp[it]();
            }
        }
        return +stk;
    }
}

