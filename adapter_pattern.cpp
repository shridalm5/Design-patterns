/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
using namespace std;
#include <bits/stdc++.h>


// adapter partten

class customString {
    public:
    string st;    
};


class convertAdpter{
  public:
  virtual customString* convert(customString*)=0;
};

class lowercaseToUppercaseAdpter: public convertAdpter{
  public:
  customString* convert(customString* l){
    customString* string1 = new customString();
    string1->st= l->st;
    transform(string1->st.begin(), string1->st.end(), string1->st.begin(),
              ::toupper);
    return string1;
  }
    
};

class CamelToSnakeCaseAdpter: public convertAdpter{
    
 string camelToSnake(string str) { 
     
        string result = ""; 
        char c = tolower(str[0]); 
        result+=(char(c)); 
        for (int i = 1; i < str.length(); i++) { 
            char ch = str[i]; 
            if (isupper(ch)) { 
                result = result + '_'; 
                result+=char(tolower(ch)); 
            } 
            else { 
                result = result + ch; 
                } 
            } 
        return result; 
    }
  public:
  customString* convert(customString* l){
    customString* string1 = new customString();
    string s = camelToSnake(l->st);
    string1->st =  s;
    return string1;
  }
    
};

int main()
{
    convertAdpter* concreteConverter = new lowercaseToUppercaseAdpter();
    convertAdpter* concreteConverter2 = new CamelToSnakeCaseAdpter();
    
    customString* string1 = new customString();
    string1->st = "shrikant";
    
    customString* camelCase = new customString();
    camelCase->st = "CamelToSnakeCaseAdpter";
    
    customString* string2 = concreteConverter->convert(string1);
    customString* string3 = concreteConverter2->convert(camelCase);
    
    std::cout << string2->st << " " << string3->st << std::endl;
    

    return 0;
};