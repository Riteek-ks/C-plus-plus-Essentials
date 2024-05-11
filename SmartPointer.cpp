#include <iostream>
using namespace std;

class A {
    public:
        A() {
            cout<< "constructor"<<endl;
        }
        ~A() {
            cout<< "destructor"<<endl;
        }
};

template<typename T>
class SmartPointerOfTypeA {
    T* ptr;
public:
    SmartPointerOfTypeA(T* ptrRef) : ptr{ptrRef} {}
    ~SmartPointerOfTypeA() {
        delete ptr;
    }
};

void instantiate() {
    SmartPointerOfTypeA<A> smartptr {new A()};
}

int main() {
    instantiate();
    
}