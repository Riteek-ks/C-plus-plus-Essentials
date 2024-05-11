#include <iostream>
#include <string>
using namespace std;
 
class Customer {
private:
    string name, address, pan, aadhar, emailId, contactNumber;
 
public:
    Customer(string nameArg,
        string addressArg,
        string panArg,
        string aadharArg
    ) : name{ nameArg }, address{ addressArg }, pan{ panArg }, aadhar{ aadharArg } {
 
    }
    Customer(string nameArg,
        string addressArg,
        string panArg,
        string aadharArg,
        string contactNumberArg
    ) : name{ nameArg }, address{ addressArg }, pan{ panArg },
        aadhar{ aadharArg }, contactNumber{ contactNumberArg } {
 
    }
    Customer(string nameArg,
        string addressArg,
        string panArg,
        string aadharArg,
        string contactNumberArg,
        string emailIdArg
    ) : name{ nameArg }, address{ addressArg }, pan{ panArg },
        aadhar{ aadharArg }, contactNumber{ contactNumberArg }, emailId{ emailIdArg } {
 
    }
 
    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "PAN: " << pan << endl;
        cout << "Aadhar: " << aadhar << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Email ID: " << emailId << endl;
    }
};
 
int main() {
    Customer obj1("tom", "BLR", "abcd234", "23424232");
    Customer obj2{ "tom", "BLR", "efd56434", "23424232" ,"5684521156"};
    Customer obj3{ "tom", "BLR", "nitish747", "23424232" ,"5684521156" ,"abc@gmail.com" };
 
    obj1.displayInfo();
    obj2.displayInfo();
    obj3.displayInfo();
 
    return 0;
}