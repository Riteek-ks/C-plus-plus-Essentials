#include <iostream>
#include <string>
using namespace std;

void f3 (string &arg) {
    arg ="hello reference";
}

// Read it right-to-left: “x is a reference to an X that is const.”
//void f2 (string *arg) 
void f2 (const string *arg) {
    // *arg ="hello pointer";
    string temp ="you can't change value but change pointer it points";
    arg =&temp;
    cout<< *arg << endl;
}

void f1 (string arg) {
    arg ="hello value";
}

int main() {
    string data ="hi";
    f1(data);
    cout<<data<<endl;
    f2(&data);
    cout<<data<<endl;
    f3(data);
    cout<<data<<endl;
}