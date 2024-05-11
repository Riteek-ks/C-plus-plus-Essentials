#include "StringCalculator.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    StringCalculator calculator;
    string input="123456";
    
    int result = calculator.add(input);
    cout << "Sum of numbers: " << result << std::endl;
    
}
