using namespace std;
#include <bits/stdc++.h>
// bridge parttern 

class shape {
    
    public:
    string s;
    virtual string getDescription()=0;
};

class color {
    
    public:
    string c;
    virtual string getColor()=0;
};

class blue: public color {
    public:
    blue(string tempcolor){
        c = tempcolor;
    }
    string getColor(){
        return c;
    }
};

class green: public color {
    public:
    green(string tempcolor){
        c = tempcolor;
    }
    string getColor(){
        return c;
    }
};


class circle: public shape{
    
    color* tempcolor;
    public:
    circle(color* c){
      this->s = "Circle";
      tempcolor = c;
    }
    
    string getDescription(){
        return tempcolor->getColor()+ " " + s;
    }
};

class square: public shape{
    
    color* tempcolor;
    public:
    square(color* c){
      this->s = "Square";
      tempcolor = c;
    }
    
    string getDescription(){
        return tempcolor->getColor()+ " " + s;
    }
};

int main()
{
    color* blueColor = new blue("blue");
    color* greenColor = new blue("green");
    shape* shape1 = new circle(blueColor);
    shape* shape2 = new square(greenColor);
    
    std::cout << shape2->getDescription() << std::endl;
    return 0;
}