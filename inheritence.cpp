#include<iostream>
#include<string>
using namespace std;



// class Student{

//     public:
//     string name;
//     int age;

// };

// int main(){
//     Student s1;
//     s1.name="ritesh";
//     s1.age=22;
//     cout<<s1.name<<" "<<s1.age<<" "<<endl;
// }

class Car{
    // public:
    // virtual void startEngine()=0;
    // virtual void shiftGear(int gear)=0;
    // virtual void stopEngine()=0;
    // virtual void accelerate()=0;
    // virtual void brake()=0;
    // virtual ~Car(){};


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



    void accelerate(){
        if(!isEngineon){
            cout<<brand<<" "<<model<<": Engine is off! cannot shift gear"<<endl;
           return;
        }

        currentSpeed+=20;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<"Km/h"<<endl;


    }


    void brake(){
        currentSpeed-=20;
        if(currentSpeed<0) currentSpeed=0;
        cout<<brand<<" "<<model<<": Braking! speed is now:  "<<currentSpeed<<"Km/h"<<endl;

    }


    void stopEngine(){
        isEngineon=false;
        currentSpeed=0;
        cout<<brand<<" "<<model<<": Engine off!  "<<endl;

    }
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

};




int main(){
    
    ManualCar* myManualCar=new ManualCar("suzuki","wagonr");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->shiftGear(2);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();

    delete myManualCar;


  cout<<"------------------------"<<endl;



  ElectricCar* myElectricCar=new ElectricCar("Tesla", "model s");
  myElectricCar->chargeBattery();
  myElectricCar->startEngine();
  myElectricCar->accelerate();
  myElectricCar->brake();
  myElectricCar->stopEngine();
  delete myElectricCar;

  return 0;







}

