#include <iostream>
#include <string>
using namespace std;

#define ADD(a,b) ((a) + (b))

template< typename T>
//function template
T add(T operandOne, T operandTwo) {
    return operandOne + operandTwo;
}

int main() {
    cout<<add<string>("ri","ks")<<" "<<add<int>(2,3);
    // cout<< ADD("ri","ks");
    cout << ADD(1,3);
}   