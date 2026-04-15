#include<bits/stdc++.h>
using namespace std;


// observer
// class Subscriber{
//     public:
//     string name;

//     Subscriber(string n){
//         name=n;

//     }

//     void update(string message){
//         cout<<name<<" received "<<message<<endl;
//     }


// };

// // subject
// class Channel{
//     private:
//     vector<Subscriber*>subs;
//     string latestvideo;
//     public:
//     void subscriber(Subscriber* s){
//         subs.push_back(s);

//     }

//     void unsubscribe(Subscriber* s){
//         // subs.erase(s);
//         int i=0;

//         for(Subscriber* s1:subs){

//             if(s1==s) subs.erase(subs.begin()+i);
//             i++;
//         }
//     }

//     void notify(string msg){
//         for(Subscriber*s: subs){
//             s->update(msg);
//         }
//     }


//     void uploadvideo(string title){
        
//     }
// };

// int main(){
//     Channel ch;

//     Subscriber s1("Aman");
//     Subscriber s2("Rohit");

//     ch.subscriber(&s1);
//     ch.subscriber(&s2);

//     ch.notify("New video uploaded");

//     ch.unsubscribe(&s2);
        
//     ch.notify("New video uploaded");




// }

// class Channel;


// class Subscriber {
//     public:
//     string name;
//     Channel* channel;

//     Subscriber(string n, Channel* ch){
//         name=n;
//         channel=ch;

//     }

//     void update();





// };

// // void Subscriber::update(){

// // }


// class Channel{
//     private:
//     vector<Subscriber*> subs;
//     string latestVideo;
    

//     public:
//     void Subscribe(Subscriber* s){
//         subs.push_back(s);

//     }
//     void Uploadvideo(string title){
//         latestVideo=title;
//         notify();

//     }

//     void notify(){
//         for(Subscriber* s:subs){
//             s->update();
//         }
//     }

//     string getvideo(){
//         return latestVideo;
//     }


// };

// void Subscriber::update(){
//     cout<<name<<"got update: "<<channel->getvideo()<<endl;

// }

// int main(){
//     Channel ch;


//     Subscriber s1("Rahul", &ch);
//     Subscriber s2("madan", &ch);

//     ch.Subscribe(&s1);
//     ch.Subscribe(&s2);

//     ch.Uploadvideo("Observer pattern video");
// }



class User{
    public:

   string name;
   User(string n){
    name=n;
   }

   void update(string post){
    cout<<name<<" saw post "<<post<<endl;
   }


};
class InstagramUser{
    private:
    vector<User*>followers;
    public:
    void follow(User* u){
        followers.push_back(u);
    }

    void post(string content){
        for(User* u:followers){
            u->update(content);
        }
    }
    


};

int main(){
    InstagramUser creator;

    User u1("ritesh");
    User u2("Rahul");

    creator.follow(&u1);
    creator.follow(&u2);

    creator.post("photo");


}