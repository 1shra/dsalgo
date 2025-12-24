// Problem: Create a smart home system where different devices can be controlled through abstract interfaces.

// Requirements:

// Interface Switchable with turnOn(), turnOff(), isOn()

// Interface Dimable with setBrightness(int level)

// Interface TemperatureControllable with setTemperature(double temp)

// Create classes:

// LightBulb (implements Switchable and Dimable)

// Thermostat (implements Switchable and TemperatureControllable)

// Fan (implements Switchable only)

// Create a SmartHomeController that can manage collections of these devices
#include<iostream>
using namespace std;


class Switchable{
  public:
    virtual ~Switchable() = default; // prevent memory leak
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void isOn() = 0;
};

class Dimable{
  public:
    virtual ~Dimable() = default;
    virtual void setBrightness(int level) = 0;
};

class TempreatureControlled{
  public:
    virtual ~TempreatureControlled() = default;
    virtual void setTemperature(int temp) = 0;
};

class LightBulb:public Switchable,public Dimable{
  bool on = false;
  int brightness = 0;
  public:
    void turnOn(){
      if(on){
        cout<<"Light Bulb is already on";
        return;
      }
      on=true;
      brightness=3;
      cout<<"Light Bulb Is on at brightness 3"<<endl;
    }

    void turnOff(){
      if(!on){
        cout<<"Light bulb is already off"<<endl;
        return;
      }
      cout<<"Light bulb is On"<<endl;
    }

    void isOn(){
      if(on){
        cout<<"Light bulb is on at the brightness level "<<brightness<<endl;
        return;
      }
      cout<<"Light bulb is off"<<endl;
    }
    void setBrightness(int level){
      if(level>6&&brightness<6){
        brightness=6;
        cout<<"Light bulb brightness is full"<<endl;
      }
      else if(level>6&&level>0){
        cout<<"Light bulb is maximum reached"<<endl;
      }
      else if(level<=0){
        cout<<"Warning: brightness is already minimum"<<endl;
      }
      else{
        brightness=level;
      }
    }
};


class Fan:public Switchable{
  bool on = false;
  public:
  void turnOn(){
      if(on){
        cout<<"Fan is already on";
        return;
      }
      on=true;
      cout<<"Fan Is on at brightness 3"<<endl;
    }

    void turnOff(){
      if(!on){
        cout<<"Fan is already off"<<endl;
        return;
      }
      cout<<"Fan is Off"<<endl;
    }

    void isOn(){
      if(on){
        cout<<"Fan is on"<<endl;
        return;
      }
      cout<<"Fan is off"<<endl;
    }
};


class ThermoStat: public Switchable,public TempreatureControlled{
  bool on = false;
  int setTemprature = 25;
  public:
    void turnOn(){
      if(on){
        cout<<"ThermoStat is already on";
        return;
      }
      on=true;
      cout<<"ThermoStat Is on at brightness 3"<<endl;
    }

    void turnOff(){
      if(!on){
        cout<<"ThermoStat is already off"<<endl;
        return;
      }
      cout<<"ThermoStat is Off"<<endl;
    }

    void isOn(){
      if(on){
        cout<<"ThermoStat is on"<<endl;
        return;
      }
      cout<<"ThermoStat is off"<<endl;
    }

    void setTemperature(int temp){
      if(temp>32){
        cout<<"Warning: Temprature reach it limit."<<endl;
      }
      else if(temp<18){
        cout<<"Warning: Temprature can't Decrease"<<endl;
      }
      else{
        setTemprature = temp;
      }
    }
};

int main(){
  
}









// ** MY APPROACH
// #include<iostream>
// using namespace std;

// class SmartHome{
//   public:
//     virtual ~SmartHome(){};
//     virtual void setDeviceOn(){};
//     virtual void setDeviceOff(){};
//     virtual void isDeviceOn(){};

// };

// class Fan:public SmartHome{
//   private:
//     bool fanOn=0;
//     bool fanOff = 1;
//     bool fanIsOn = 0;
//   public:
//     void setDeviceOn(){
//       cout<<"Fan Is On"<<endl;
//       fanOn = 1;
//       fanOff = 0;
//       fanIsOn = 1;
//     }
//     void setDeviceOff(){
//       cout<<"Fan is turn Off"<<endl;
//       fanOn = 0;
//       fanOff = 1;
//       fanIsOn = 0;
//     }
//     void isDeviceOn(){
//       if(fanIsOn) cout<<"Fan Is On"<<endl;
//       else cout<<"Fan is Off"<<endl;
//     }

// };


// class Light:public SmartHome{
//   private:
//     bool lightOn=0;
//     bool lightOff = 1;
//     bool isLightOn = 0;
//     int Brightnesslvl = 0; 
//   public:
//     void setDeviceOn(){
//       cout<<"Light 1 Is On"<<endl;
//       lightOn = 1;
//       lightOff = 0;
//       isLightOn = 1;
//     }
//     void setDeviceOff(){
//       cout<<"Light 1 is turn Off"<<endl;
//       lightOn = 0;
//       lightOff = 1;
//       isLightOn = 0;
//     }
//     void isDeviceOn(){
//       if(isLightOn) cout<<"Light 1 Is On"<<endl;
//       else cout<<"Light 1 is Off"<<endl;
//     }
//     void setBrightness(int level){
//       if(level<7)Brightnesslvl=level;
//     }
// };
// class Thermostat: public SmartHome{
//   private:
//     int temp=18;
//     int thermostatOn=0;
//     int thermostatOff=0;
//     int isThermostatOn=0;
//   public:
//     void setDeviceOn(){
//       cout<<"Light 1 Is On"<<endl;
//       thermostatOn = 1;
//       thermostatOff = 0;
//       isThermostatOn = 1;
//     }
//     void setDeviceOff(){
//       cout<<"Light 1 is turn Off"<<endl;
//       thermostatOn = 0;
//       thermostatOff = 1;
//       isThermostatOn = 0;
//     }
//     void isDeviceOn(){
//       if(isThermostatOn) cout<<"Light 1 Is On"<<endl;
//       else cout<<"Light 1 is Off"<<endl;
//     }
//   void setTemperature(double temp){
//     this->temp = temp;
//   }

// };
// int main(){

// }