
#include<iostream>
#include<string>
using namespace std;





class Car{
    public:
    virtual void startEngine()=0;
    virtual void shiftGear(int gear)=0;
    virtual void stopEngine()=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual ~Car(){};

};

class Sportscar: public Car{
    public:
    string brand;
    string model;
    bool isEngineon;
    int currentGear;
    int currentSpeed;

    Sportscar(string brand, string model){
        this->brand=brand;
        this->model=model;
        isEngineon=false;
        currentSpeed=0;
        currentGear=0;
    }

    void startEngine(){
        isEngineon=true;
        cout<<brand<<" "<<model<<": Engine starts with the roar"<<endl;

    }

    void shiftGear(int gear){
        if(!isEngineon){
           cout<<brand<<" "<<model<<": Engine is off! cannot shift gear"<<endl;
           return;
        }

        currentGear=gear;
        cout<<brand<<" "<<model<<": Shifted to the gear "<<currentGear<<endl;
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
        currentGear=0;
        currentSpeed=0;
        cout<<brand<<" "<<model<<": Engine off!  "<<endl;

    }
};

int main(){
    Car* myCar=new Sportscar("Ford", "Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;
    return 0;




}

