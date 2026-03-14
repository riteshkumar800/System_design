#include<iostream>
#include<string>
using namespace std;


class Car{

    protected:
    string brand;
    string model;
    bool isEngineon;
    int currentSpeed;


        
    public:
   Car(string b, string m){
        this->brand=b;
        this->model=m;
        isEngineon=false;
        currentSpeed=0;
        
    }

    void startEngine(){
        isEngineon=true;
        cout<<brand<<" "<<model<<": Engine starts with the roar"<<endl;

    }



    


    void stopEngine(){
        isEngineon=false;
        currentSpeed=0;
        cout<<brand<<" "<<model<<": Engine off!  "<<endl;

    }


   virtual void accelerate()=0;
   virtual void accelerate(int speed)=0;
   virtual void brake()=0;
   virtual ~Car(){};

};

class ManualCar: public Car{
    private:
    int currentGear;
    public:
    ManualCar(string b,string m):Car(b,m){
        currentGear=0;
    }

    void shiftGear(int gear){
        currentGear=gear;
        cout<<brand<<" "<<model<<": Shifted to gear "<<currentGear<<endl;
    }

    void accelerate(){
        if(!isEngineon){
            cout<<brand<<" "<<model<<": Engine is off! cannot shift gear"<<endl;
           return;
        }

        currentSpeed+=20;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<"Km/h"<<endl;


    }
    void accelerate(int speed){
        if(!isEngineon){
            cout<<brand<<" "<<model<<": Engine is off! cannot shift gear"<<endl;
           return;
        }

        currentSpeed+=speed;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<"Km/h"<<endl;


    }
    void brake(){
        currentSpeed-=20;
        if(currentSpeed<0) currentSpeed=0;
        cout<<brand<<" "<<model<<": Braking! speed is now:  "<<currentSpeed<<"Km/h"<<endl;

    }



};


class ElectricCar:public Car{
    private:
    int batteryLevel;

    public:

    ElectricCar(string b,string m): Car(b,m){
          batteryLevel=100;
    }
    void chargeBattery(){
        batteryLevel=100;
        cout<<brand<<" "<<model<<":  batteryfully Charged"<<endl;
    }
    void accelerate(){
        if(!isEngineon){
            cout<<brand<<" "<<model<<": Engine is off! cannot shift gear"<<endl;
           return;
        }
        if(batteryLevel<=0){
            cout<<brand<<" "<<model<<": battery daed! cannot accelerate "<<"Km/h"<<endl;
            return;
        }
        batteryLevel-=10;
        currentSpeed+=20;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<"Km/h"<<endl;


    }
    void accelerate(int speed){
        if(!isEngineon){
            cout<<brand<<" "<<model<<": Engine is off! cannot shift gear"<<endl;
           return;
        }
        if(batteryLevel<=0){
            cout<<brand<<" "<<model<<": battery daed! cannot accelerate "<<"Km/h"<<endl;
            return;
        }
        batteryLevel-=10;
        currentSpeed+=speed;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<"Km/h"<<endl;


    }
    void brake(){
        currentSpeed-=20;
        if(currentSpeed<0) currentSpeed=0;
        cout<<brand<<" "<<model<<": Braking! speed is now:  "<<currentSpeed<<"Km/h. Battery at"<<batteryLevel<<endl;

    }


};




int main(){
    
    ManualCar* myManualCar=new ManualCar("suzuki","wagonr");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->shiftGear(2);
    myManualCar->accelerate(20);
    myManualCar->brake();
    myManualCar->stopEngine();

    delete myManualCar;


  cout<<"------------------------"<<endl;



  ElectricCar* myElectricCar=new ElectricCar("Tesla", "model s");
  myElectricCar->chargeBattery();
  myElectricCar->startEngine();
  myElectricCar->accelerate();
  myElectricCar->brake();
  myElectricCar->accelerate(60);

  myElectricCar->stopEngine();
  

  delete myElectricCar;

  return 0;







}

