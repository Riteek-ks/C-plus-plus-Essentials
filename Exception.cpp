#include <iostream>
#include <string>
using namespace std;
 
int divFun(int numerator, int divisor) {
    cout << "Div Begin" << endl;
    int result;
    try{
    result = numerator / divisor;
    }
    catch (runtime_error& errObj) {
        cout << errObj.what() << endl;
    }
    cout << "Div End" << endl;
    return result;
}
 
void init() {
    cout << "Init Begin" << endl;
    int result = divFun(10, 0);
    cout << "Init End" << ":" << result << endl;
}
 
int main() {
    cout << "Main Begin" << endl;
    init();
    cout << "Main End" << endl;
    return 0;
}