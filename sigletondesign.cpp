#include<bits/stdc++.h>
using namespace std;


// class Singleton{
//     private:
//     static Singleton* instance;
//     static mutex mtx;

//     Singleton(){
//         cout<<"Singleton constructor is called...."<<endl;
//     }

//     public:
//     static Singleton* getInstance(){
//         if(instance==nullptr){
//             lock_guard<mutex>lock(mtx);
//             if(instance==nullptr){
//                 instance=new Singleton();
//             }
//         }

//         return instance;
//     }



// };
// Singleton* Singleton::instance = nullptr;
// mutex Singleton::mtx;


class Singleton{
    private:
    static Singleton* instance;

    Singleton(){
        cout<<"singleton constructor called...."<<endl;
    }


    public:
    static Singleton* getInstance(){
        return instance;
    }

};

// Singleton* Singleton::instance=new Singleton();





// int main(){
//     Singleton* s1=Singleton::getInstance();
//     Singleton* s2=Singleton::getInstance();

//     cout<<(s1==s2)<<endl;


class Singleton {
private:
    Singleton() {}

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton\n";
    }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.showMessage();

    if (&s1 == &s2)
        cout << "Same object\n";

    return 0;
}


