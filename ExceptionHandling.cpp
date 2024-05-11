#include <iostream>
#include <string>
using namespace std;
 
struct ErrorInfo{
    string methodName;
    string lineNumber;
    string message;
};
 
int divFun(int numerator,int divisor){
    int result;
    cout<<"Div Begin"<<endl;
    if(divisor<=0){
        ErrorInfo errorDetails;
        errorDetails.methodName="divFun";
        errorDetails.lineNumber="21";
        errorDetails.message="Divisor value cannot be zero or negative";
        throw errorDetails;
    }
    result= numerator/divisor;
    cout<<"Div End"<<endl;
    return result;
}
 
void init(){
    cout<<"Init Begin"<<endl;
    int result=divFun(10,0);
    cout<<"Init End"<<":"<<result<<endl;
    
    
    
}
 
int main(){
    cout<<"Main Begin"<<endl;
    try{
        init();
        cout<<"Main End"<<endl;
    }catch(ErrorInfo& exObj){
        cout<<"Method Name :"<<exObj.methodName<<endl;
        cout<<"Line Number :"<<exObj.lineNumber<<endl;
        cout<<"Message :"<<exObj.message<<endl;
    }
    
    
    return 0;
}