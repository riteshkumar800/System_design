#include<bits/stdc++.h>
using namespace std;


// observer
class Subscriber{
    public:
    string name;

    Subscriber(string n){
        name=n;

    }

    void update(string message){
        cout<<name<<" received "<<message<<endl;
    }


};

// subject
class Channel{
    private:
    vector<Subscriber*>subs;
    public:
    void subscriber(Subscriber* s){
        subs.push_back(s);

    }

    void notify(string msg){
        for(Subscriber*s: subs){
            s->update(msg);
        }
    }
};

int main(){
    Channel ch;

    Subscriber s1("Aman");
    Subscriber s2("Rohit");

    ch.subscriber(&s1);
    ch.subscriber(&s2);

    ch.notify("New video uploaded");


}