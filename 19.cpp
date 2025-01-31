#include<iostream>
using namespace std;

class shape{
    int l;
    int b;
    int h;
    public:
      float volume(int l){
        return l*l*l;
      }
      float volume(int b, int h){
      	return 3.14*b*b*h;
      }
      float volume(int l,int b, int h){
      	return l*b*h;
      }

};

int main(){
	shape v;
	float a=2,b=4,c=6;
	cout<<v.volume(a)<<endl;
	cout<<v.volume(a,b)<<endl;
	cout<<v.volume(a,b,c)<<endl;

	return 0;
}
