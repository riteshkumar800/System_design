
// ##########################################################################################################################################################
// SIMPLE FACTORY

#include<bits/stdc++.h>
using namespace std;

class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger(){};

};

class BasicBurger: public Burger{
    public:
    void prepare() override{
        cout<<"Basic burger....."<<endl;

    }


};

class StandardBurger:public Burger{
    public:
    void prepare() override{
        cout<<"prepare Standard burger...."<<endl;
    }
};


class PremiumBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Premium burgeer....."<<endl;

    }
};


class BurgerFactory{
    public:
    Burger* createBurger(string& type){ ///return tthe instance of the class Burger
        if(type=="basic"){
            return new BasicBurger();
        }
        else if(type=="standard"){
            return new StandardBurger();

        }
        else if(type=="premium"){
            return new PremiumBurger();
        }
        else{
            cout<<"Invalid burger type..."<<endl;
            return nullptr;
        }
    }
};

int main(){

    string type="standard";
    BurgerFactory* myBurgerFactory=new BurgerFactory();
    Burger* burger=myBurgerFactory->createBurger(type); //actually burger will store the class burger or may return , and createBurger is returning Burger class instance ,myBurgerFactory->createBurger(type) replaced with StandardBurger
    burger->prepare();

    return 0;



}

// ##########################################################################################################################################################
// SIMPLE FACTORY





