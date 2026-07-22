#include <iostream>
using namespace std;

// Product
class Vehicle {
public:
    virtual void start() = 0;
    virtual ~Vehicle() {}
};

// Concrete Products
class Car : public Vehicle {
public:
    void start() override {
        cout << "Car started\n";
    }
};

class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike started\n";
    }
};

class Truck : public Vehicle {
public:
    void start() override {
        cout << "Truck started\n";
    }
};

// Simple Factory
class VehicleFactory {
public:
    static Vehicle* createVehicle(string type) {
        if (type == "car")
            return new Car();
        else if (type == "bike")
            return new Bike();
        else if (type == "truck")
            return new Truck();
        else
            return nullptr;
    }
};

int main() {
    string type;
    cin >> type;

    Vehicle* v = VehicleFactory::createVehicle(type);

    if (v) {
        v->start();
        delete v;
    } else {
        cout << "Invalid vehicle type\n";
    }

    return 0;
}