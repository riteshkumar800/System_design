
// ##########################################################################################################################################################
// SIMPLE FACTORY

// #include<bits/stdc++.h>
// using namespace std;

// class Burger{
//     public:
//     virtual void prepare()=0;
//     virtual ~Burger(){};

// };

// class BasicBurger: public Burger{
//     public:
//     void prepare() override{
//         cout<<"Basic burger....."<<endl;

//     }


// };

// class StandardBurger:public Burger{
//     public:
//     void prepare() override{
//         cout<<"prepare Standard burger...."<<endl;
//     }
// };


// class PremiumBurger:public Burger{
//     public:
//     void prepare() override{
//         cout<<"Premium burgeer....."<<endl;

//     }
// };


// class BurgerFactory{
//     public:
//     Burger* createBurger(string& type){ ///return tthe instance of the class Burger
//         if(type=="basic"){
//             return new BasicBurger();
//         }
//         else if(type=="standard"){
//             return new StandardBurger();

//         }
//         else if(type=="premium"){
//             return new PremiumBurger();
//         }
//         else{
//             cout<<"Invalid burger type..."<<endl;
//             return nullptr;
//         }
//     }
// };

// int main(){

//     string type="standard";
//     BurgerFactory* myBurgerFactory=new BurgerFactory();
//     Burger* burger=myBurgerFactory->createBurger(type); //actually burger will store the class burger or may return , and createBurger is returning Burger class instance ,myBurgerFactory->createBurger(type) replaced with StandardBurger
//     burger->prepare();

//     return 0;



// }

// ##########################################################################################################################################################
// FACTORY METHOD
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

class BasicWheatBurger: public Burger{
    public:
    void prepare()override{
        cout<<"basicWHeatburger prepared....."<<endl;
    }
};

class StandardWheatBurger: public Burger{
    public:
    void prepare()override{
        cout<<"standardWHeatburger prepared....."<<endl;
    }
};

class PremiumWheatBurger: public Burger{
    public:
    void prepare()override{
        cout<<"premiumWHeatburger prepared....."<<endl;
    }
};


class BurgerFactory{
    public:
    virtual Burger* createBurger(string& type)=0;


};

class SinghBurger:public BurgerFactory{
    public:
    Burger* createBurger(string& type) override{
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
            cout<<"invalid burger type.."<<endl;
            return nullptr;
        }
    }
};

class KingBurger:public BurgerFactory{
    public:
    Burger* createBurger(string&type)override{
        if(type=="basic"){
            return new BasicWheatBurger();
        }
        else if(type=="standard"){
            return new StandardWheatBurger();
        }
        else if(type=="premium"){
            return new PremiumBurger();
        }
        else{
            cout<<"invalid burger type.."<<endl;
            return nullptr;
        }

    }
};

int main(){
    string type="basic";
    BurgerFactory* myFactory=new KingBurger();
    Burger* burger=myFactory->createBurger(type);
    burger->prepare();

    return 0;

}







