#include <iostream>

class Sum
{
    int a;
    int b;
    
public:
    Sum(int x = 0, int y = 0): a(x), b(y) {};
    Sum(Sum x, int y): a(x.get()), b(y) {};
    int get() const {
        return a + b;
    };

};