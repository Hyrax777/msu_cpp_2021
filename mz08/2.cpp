#include <string>
#include <sstream>
#include <cmath>
#include <iostream>

class Square: public Figure {
private:
    double _a = 0;
public:
    static Square* make(std::string str) {
        Square *ex = new Square;
        ex->_a = std::stod(str);
        return ex;
    }
    double get_square() const override {
        return _a * _a;
    }
};

class Rectangle: public Figure {
private:
    double _a = 0, _b = 0;
public:
    static Rectangle* make(std::string str) {
        Rectangle *ex = new Rectangle;
        std::string a, b;
        std::stringstream ss;
        ss << str;
        ss >> a >> b;
        ex->_a = std::stod(a);
        ex->_b = std::stod(b);
        return ex;
    }
    double get_square() const override {
        return _a * _b;
    }
};

class Circle: public Figure {
private:
    double _r = 0;
public:
    static Circle* make(std::string str) {
        Circle *ex = new Circle;
        ex->_r = std::stod(str);
        return ex;
    }
    double get_square() const override {
        return M_PI * _r * _r;
    }
};
