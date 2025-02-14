#include<bits/stdc++.h>
using namespace std;

class Fibbo{
  public:
   int a;
   int b;
   int c;
     Fibbo(){
       a = 0;
       b = 1;
       c = 0;
     }
   int giveNextEle(){
      int x = c;
      a = b;
      b = c;
      c = a+b;
      return x;
   }  
};
int main(){
    Fibbo* x = new Fibbo();
 //   cout<< x->giveNextEle();
    
//    Fibbo x = Fibbo();
 //   cout<< x.giveNextEle();
    for(int i = 1; i<=10; i++) cout<<x->giveNextEle()<<" ";
}
