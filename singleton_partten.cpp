/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
using namespace std;
#include <bits/stdc++.h>
// singleton pattern
class singletonClass {
    static singletonClass* m_singleton;
    
    private:
    singletonClass(){
        std::cout << "singleton instance created" << std::endl;
    }
    
    public:
     static singletonClass*  getsingletonClass (){
     
        if(m_singleton == nullptr){
            cout << "First caller" << "\n";
            m_singleton = new singletonClass();
            return m_singleton;
        }else{
            cout << "Not the first caller" << "\n";
            return m_singleton;
        }
        
    }
};
singletonClass* singletonClass:: m_singleton = nullptr;

int main()
{
    
    singletonClass:: getsingletonClass();//singletonClass();
    singletonClass:: getsingletonClass();//singletonClass();
    singletonClass:: getsingletonClass();//singletonClass();
    

    return 0;
}