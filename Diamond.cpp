#include <iostream>
#include <string>
using namespace std;

class Device {
private:
	string name;
	string model;
	string version;

public:
	Device() {
		cout << "device instantiated" << endl;
	}
	~Device() {
		cout << "device destructed" << endl;
	}
};
class Printer : public Device{
public:
	void print(string content) {
		cout << "print" << content << endl;
	}

	Printer() {
		cout << "printer instantiated" << endl;
	}
	~Printer() {
		cout << "printer destructed" << endl;
	}
};

class Scanner : public Device{

public:
	void scan(string content) {
		cout << "Scan " << content << endl;
	}

	Scanner() {
		cout << "scanner instantiated" << endl;
	}
	~Scanner() {
		cout << "scanner destructed" << endl;
	}

};

class PrintScanner :public Printer, public Scanner {  
	//never do this as it is a crime which cpp supports./..
	// try to avoid multiple inheritance
public:
	PrintScanner() {
		cout << "PrintScanner constructor called" << endl;
	}

	~PrintScanner() {
		cout << "PrintScanner Destructed" << endl;
	}

};

class TaskManager {
public:
	void invokePrintTask(Printer* printerPtr, string content) {
		printerPtr->print(content);
	}

	void invokeScanTask(Scanner* scannerPtr, string content) {
		scannerPtr->scan(content);
	}
};

int main() {
	// Printer hpPrinter;
	// Scanner hpScanner;
	PrintScanner hpPrintScanner;
	TaskManager taskMgr;
	// taskMgr.invokePrintTask(&hpPrinter, "doc.pdf");
	// taskMgr.invokeScanTask(&hpScanner, "doc.pdf");

	taskMgr.invokePrintTask(&hpPrintScanner, "doc.pdf");
	taskMgr.invokeScanTask(&hpPrintScanner, "doc.pdf");
}