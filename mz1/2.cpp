#include <iostream>

class A 
{
    int b;
    bool ok;

public:
    A() : b(), ok(true) {std::cin >> b;}
    A(A & x) : b(), ok(true) { 
        std::cin >> b;
        x.ok = false;  
        b += x.b;
    }
    ~A() { 
        if (ok) 
            std::cout << b << '\n';
    }
};