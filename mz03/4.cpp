#include <iostream>

using namespace std;

int foo(int a, int b, int *x, int *y) {
    if (a ==0){
        *x=0;
        *y=1;
        return b;
    }
    int x1, y1;
    int d=foo(b%a, a, &x1, &y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return d;
}

int main(){
    int a = 1;
    for (int i =14;i<169;++i){
        a= (a*i)%169;
    }
    cout <<a;
    return 0;
}