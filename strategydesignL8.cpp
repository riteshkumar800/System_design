#include<bits/stdc++.h>
using namespace std;
class WalkableRobot{
    public:
    virtual void Walk()=0;
    virtual ~WalkableRobot(){};

};


class NormalWalk: public WalkableRobot{
    public:
    void Walk() override{
        cout<<" normal walking....."<<endl;
    }

};

class Nowalk:public WalkableRobot{
    public:
    void Walk() override{
        cout<<"Cannot walk....."<<endl;

    }


};


class TalkableRobot{
    public:
    virtual void Talk()=0;
    virtual ~TalkableRobot(){};

};

class NormalTalk:public TalkableRobot{
    public:
    void Talk() override{
        cout<<"normally talking...."<<endl;
    }
};


class Notalk:public TalkableRobot{
    public:
    void Talk(){
        cout<<"cannot talk...."<<endl;
    }

    
};

class FlyableRobot{
    public:
    virtual void Fly()=0;
    virtual ~FlyableRobot(){};

};

class Normalfly:public FlyableRobot{
    public:
    void Fly() override{
        cout<<"Normal Fly....."<<endl;

    }


};

class Nofly: public FlyableRobot{
    public:
    void Fly() override{
        cout<<"NO fly...."<<endl;
    }
};


class Robot{
    protected:
    WalkableRobot* walkBehaviour;
    TalkableRobot* talkBehaviour;
    FlyableRobot* flyBehaviour;

    public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f){
        this->flyBehaviour=f;
        this->talkBehaviour=t;
        this->walkBehaviour=w;
    }

    void walk(){
        walkBehaviour->Walk();
    }
    void talk(){
        talkBehaviour->Talk();

    }

    void fly(){
        flyBehaviour->Fly();
    }

    virtual void projection()=0;



};


class CompanionRobot: public Robot{
    public:
    CompanionRobot(WalkableRobot*w , TalkableRobot* t,FlyableRobot* f): Robot(w,t,f){}

    void projection() override{
        cout<<"Displaying friendly coompanion features....."<<endl;
    }



};


class WorkerRobot: public Robot{
    public:
    WorkerRobot(WalkableRobot*w,TalkableRobot* t,FlyableRobot* f ):Robot(w,t,f){}

    void projection() override{
        cout<<"Displaying worker efficiency stats...."<<endl;
    }
};

int main(){
    Robot* robot1= new CompanionRobot(new NormalWalk(), new NormalTalk(), new Normalfly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();
   

    cout<<"--------------------------------"<<endl;

    Robot* robot2=new WorkerRobot(new Nowalk(), new Notalk(),new Nofly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();


}



