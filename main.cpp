/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
using namespace std;

#include <bits/stdc++.h>

// decorator parttern


class pizza {
public:
	string description;
	int cost;
	string name;

	virtual int getcost() =0;
	virtual string getDescription()=0;

};


class basicPizza: public pizza {

public:
	basicPizza(int price, string des, string itemName) {
		cost= price;
		description= des;
		name = itemName;
	}
	int getcost() {
		return cost;
	}
	string getDescription() {
		return description;
	}

};


class Toppings: public pizza {
public:
	pizza * plainPizza;
	Toppings(int price, string des, string itemName) {
		cost= price;
		description= des;
		name = itemName;
	}

	int getcost() {
		return plainPizza->getcost() +cost;
	}
	string getDescription() {
		return  plainPizza->getDescription() + description ;
	}
};

int main()
{
    pizza* plainPizza = new basicPizza(100, "contents: cheeze", "plainPizza");
    Toppings* panner = new Toppings(20, ",Panner", "Panner");
    panner->plainPizza = plainPizza;
    
    Toppings* meyo = new Toppings(10, ",Meyo", "Meyo");
    meyo->plainPizza = panner;
    
    std::cout << plainPizza->getcost() << " "  << plainPizza->getDescription() << std::endl;
    std::cout << panner->getcost() << " " << panner->getDescription() << std::endl;
    std::cout << meyo->getcost() << " " <<  meyo->getDescription() << std::endl;




}