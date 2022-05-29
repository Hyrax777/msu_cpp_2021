#include <iostream>

using std::cout;
using std::endl;

class C
{
    int ex;

public:
    C(int a) {
        ex = a * 2;
    };
    int get() const {
        return ex;
    };
};

int operator+ (C ex1, C ex2) {
        return ex1.get() + ex2.get();
};
