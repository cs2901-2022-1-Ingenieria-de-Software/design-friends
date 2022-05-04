#include <iostream>
#include <vector>
using namespace std;

class Led{
protected:
    bool activated;
    string name;
public:
    virtual void accion() = 0;
    Led(){
        activated = false;
    }
    string getName(){
        return name;
    }
};

class YellowLed:public Led{
public:
    YellowLed():Led(){
        name = "Yellow_Led";
    }
    void accion() override{
        if(!activated)
            cout<<"Yellow on"<<endl;
        else
            cout<<"Yellow off"<<endl;
    }
};

class RedLed:public Led{
public:
    RedLed(){
        name = "Red_Led";
    }
    void accion() override{
        if(!activated)
            cout<<"Red on"<<endl;
        else
            cout<<"Red off"<<endl;
    }
};

class WhiteLed:public Led{
public:
    WhiteLed(){
        name = "White_Led";
    }
    void accion() override{
        if(!activated)
            cout<<"White on"<<endl;
        else
            cout<<"White off"<<endl;
    }
};

class Fan{
private:
    bool activated;
public:
    Fan(){
        activated = false;
    }
    void function(){
        if(!activated)
            cout<<"Fan on"<<endl;
        else
            cout<<"Fan off"<<endl;
    }
};

class MainControl{
private:
    vector<Led*> led;
    Fan fan;
public:
    MainControl(){};
    MainControl(vector<Led*> _led, Fan _fan){
        led = _led;
        fan = _fan;
    }
    void setLEDs(vector<Led*> _led){
        led = _led;
    }
    void setFan(Fan _fan){
        fan = _fan;
    }
    vector<Led*> getLEDs(){
        return led;
    }
    Fan getFan(){
        return fan;
    }
    void activateGadgets(string gadget){
        if(gadget == "Fan")
            fan.function();
        else {
            for(int i=0; i<led.size(); i++)
                if(led[i]->getName() == gadget)
                    led[i]->accion();
        }
    }
};

int main() {
    MainControl *control = new MainControl();
    vector<Led*> led;
    auto *n = new YellowLed();
    auto *n1 = new RedLed();
    auto *n2 = new WhiteLed();
    Fan fan;
    led.push_back(n);
    led.push_back(n1);
    led.push_back(n2);
    control->setLEDs(led);
    control->setFan(fan);
    control->activateGadgets("Yellow_Led");
}