// not using  virtual change is-a relation of printscanner of printer and scanner
// to has-a and have is-a relation (for printscanner) with device.

#include<iostream>
#include<string>
using namespace std;
 
class Device {
private:
    string name;
    string model;
    string version;
 
protected:
    Device(string nameArg, string modelArg,string versionArg) : name{nameArg} ,model{modelArg},version{versionArg}{
        cout << "Device constructor called" << endl;
    }
    ~Device() {
        cout << "Device Destructed" << endl;
    }
};

class IPrint {
    public:
    virtual void print (string content) =0;
};

class IScan {
    public:
    virtual void scan (string content) =0;
};

class Printer: public IPrint, public Device{
public:
    Printer() :Device{"","",""} {
        cout << "Printer constructor called"<<endl;
    }
    ~Printer() {
        cout << "Printer Destructed" << endl;
    }
    void print(string content) {
        cout << "Print " << content << endl;
    }
};
 
class Scanner:public IScan, public Device{
public:
    Scanner() : Device{"","",""}{
        cout << "Scanner constructor called" << endl;
    }
    ~Scanner() {
        cout << "Scanner Destructed" << endl;
    }
    void scan(string content) {
        cout << "Scan " << content << endl;
    }
};
 
class PrintScanner : public Device, public IPrint, public IScan{  
    Printer printerObj;
    Scanner scannerObj;
public:
    PrintScanner(string n, string m,string v) : Device{n,m,v} {
        cout << "PrintScanner constructor called" << endl;
    }
    ~PrintScanner() {
        cout << "PrintScanner Destructed" << endl;
    }

    void scan(string content) {
        scannerObj.scan(content);
    }

    void print(string content) {
        printerObj.print(content);
    }
    
};
 
class TaskManager {

public:
    void invokePrintTask(IPrint* printerPtr, string content) {
        printerPtr->print(content);
    }
    void invokeScanTask(IScan* scannerPtr, string content) {
        scannerPtr->scan(content);
    }
};
 
int main() {
    //  Printer hpPrinter;
    // Scanner hpScanner;
    PrintScanner hpPrintScanner("","","");
    TaskManager taskMgr;
    // taskMgr.invokePrintTask(&hpPrinter, "doc.pdf");
    // taskMgr.invokeScanTask(&hpScanner, "doc.pdf");
    taskMgr.invokePrintTask(&hpPrintScanner, "doc.pdf");
    taskMgr.invokeScanTask(&hpPrintScanner, "doc.pdf");
}