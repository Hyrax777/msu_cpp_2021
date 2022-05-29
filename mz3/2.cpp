#include <iostream>
#include <cstring>

namespace numbers {
    class complex_stack {
    private:
        complex *_stack = nullptr;
        size_t _size = 128;
        size_t _cursz = 0;

    public:
        complex_stack() {
            _stack = new complex[_size];
        }

        complex_stack(const complex_stack& old): _size(old._size), _cursz(old._cursz) {
            if (_stack != nullptr) {
                delete[] _stack;
            }
            _stack = new complex[_size];
            memcpy(_stack, old._stack, _size * sizeof(complex));
        }


        void operator=(const complex_stack& old) {
            _size = old._size;
            _cursz = old._cursz;
            if (_stack != nullptr) {
                delete[] _stack;
            }
            _stack = new complex[old._size];
            memcpy(_stack, old._stack, _size * sizeof(complex));
        }

        size_t size() const {
            return _cursz;
        }
        
        complex& operator[](size_t i) const {
            return _stack[i];
        }

        friend complex operator+(const complex_stack& stk);

        friend complex_stack operator~(const complex_stack& stk);

        friend complex_stack operator<<(const complex_stack& stk, complex numb);

        ~complex_stack() {
            delete[] _stack;
        }
    };

    complex_stack operator<<(const complex_stack& stk, complex numb) {
        complex_stack temp(stk);
        if (temp._cursz >= temp._size) {
                temp._size *= 2;
                delete[] temp._stack;
                temp._stack = new complex[stk._size];
                memcpy(temp._stack, stk._stack, stk._size*sizeof(complex));
        }
        temp[temp._cursz++] = numb;
        return temp;
    }

    complex_stack operator~(const complex_stack& stk) {
            complex_stack tmp(stk);
            --tmp._cursz;
            return tmp;  
    }

    complex operator+(const complex_stack& stk) {
            return stk[stk._cursz - 1];
        }

};
