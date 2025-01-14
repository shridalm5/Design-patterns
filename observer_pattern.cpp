/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
using namespace std;

#include <bits/stdc++.h>

// observer parttern

class Customer {
  public:
  string name;
  void notification(string s){
      std::cout << s << std::endl;
      
  }
  Customer(string n){
      name = n;
      
  }
};

class Shop {
    public:
    vector<Customer*> customerList;
    string item;
    virtual void registerCustomer(Customer* cx) =0;
    virtual void removeCustomer(Customer* cx)=0;
    virtual void notifyCustomer()=0;

};



class IphoneShop : public Shop{
    public:

    
    IphoneShop(string i){
        item = i;
    }
    
    void registerCustomer(Customer* cx){
        customerList.push_back(cx);
    }
    void removeCustomer(Customer* cx){
        
        std::vector<Customer*>::iterator position = std::find(customerList.begin(), customerList.end(), cx);
        if (position != customerList.end()) // == customerList.end() means the element was not found
            customerList.erase(position);
        else
          cout << "Customer not found\n";

        
    }
    
    
    void notifyCustomer(){
        for(int i=0;i< customerList.size();i++){
            customerList[i]->notification("we have restocked item " + item );
        } 
    }
  
};

int main()
{
    
    Customer* customer1 = new Customer("shrikant");
    string iphone = "Iphone 16";
    
    Shop* myshop = new IphoneShop(iphone);
     
    myshop->registerCustomer(customer1);
    myshop->notifyCustomer(); 
    myshop->notifyCustomer(); 
    myshop->removeCustomer(customer1);
    myshop->removeCustomer(customer1);
    myshop->notifyCustomer();
    
    cout << myshop->item;


}