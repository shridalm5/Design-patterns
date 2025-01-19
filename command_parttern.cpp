
using namespace std;
#include <bits/stdc++.h>
//command partten
class tv {
    public:
    bool isOn;
    int channel;
    tv(){
        isOn = false;
        channel = 1;
    }
};

class command {
    public:
    virtual void execute()=0;
    virtual void undo()=0;
};

class remote{
    
    command* On; command* pressUp;
    public:
    void pressOn(){
        On->execute();
    }
    void pressOff(){
        On->undo();
    }
    void onPressChannelUp(){
        pressUp->execute();
    }
    void onPressChannelDown(){
        pressUp->undo();
    }
    remote(command* turnOn,command* up ){
        On = turnOn;
        pressUp = up;
        
    }
};

class turnOnTv: public command {
    tv* myTv;
    public:
    void execute(){
        myTv->isOn = true;
    }
    
    void undo(){
        myTv->isOn = false;
    }
    turnOnTv(tv* mTv){
        myTv = mTv;
    }

};

class channelUp: public command {
    tv* myTv;
    public:
    void execute(){
        myTv->channel = (myTv->channel)+1;
    }
    
    void undo() { 
        myTv->channel = (myTv->channel)-1;
    }
    channelUp(tv* mTv){
        myTv = mTv;
    }

};


int main()
{
    tv* sonyTV = new tv();
    turnOnTv* onCommand = new turnOnTv(sonyTV);
    channelUp* upCommand = new channelUp(sonyTV);
    remote* sonyRemote = new remote(onCommand, upCommand);
    
    
    std::cout <<  "TV isOn and channel state : " << sonyTV->isOn << "," << sonyTV->channel << std::endl;
    sonyRemote->pressOn();
    std::cout <<  "TV isOn and channel state : " << sonyTV->isOn << "," << sonyTV->channel << std::endl;
    sonyRemote->onPressChannelUp();
    std::cout <<  "TV isOn and channel state : " << sonyTV->isOn << "," << sonyTV->channel << std::endl;
    sonyRemote->pressOff();
    std::cout <<  "TV isOn and channel state : " << sonyTV->isOn << "," << sonyTV->channel << std::endl;

    return 0;
}