//dependency inversion principle

#include<iostream>
#include<string>
using namespace std;

// Abstraction
class IEngine {
    public:
        virtual void start() = 0;
        virtual void stop() = 0;
};

//low level module
class MPFIEngine : public IEngine {
    public:
        void start() {cout<<"mpfi engine start"<<endl;}
        void stop() {cout<<"mpfi engine stop"<<endl;}
};

//low level module
class GDIEngine : public IEngine {
    public:
        void start() {cout<<"gdi engine start"<<endl;}
        void stop() {cout<<"gdi engine stop"<<endl;}
};

//high level module
class XUV3X0 {
    
    //dependency (abstract)
    IEngine* engine; // high module dont depend on low module (loosely coupled)
    public:         // at creation of car obj i.e, 
                    //at runtime we can select engine (late binding)
        //constructor dependency injection
        XUV3X0(IEngine* engineArg) :engine {engineArg} {}

        void drive() {
            this->engine->start();
        }
        void halt() {
            this->engine->stop();
        }
};

int main() {

    MPFIEngine napEngine;
    GDIEngine turboEngine;
    XUV3X0 car { &napEngine};
    car.drive();
    XUV3X0 turbocar { &turboEngine};
    turbocar.drive();
}

