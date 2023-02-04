#include<iostream>
#include<random>
using namespace std;
int main(){
   std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(0.0, 1.0);
    float x,y;
    int count=0;
    for(int i=0;i<1000000;i++){
        x=distr(eng);
        y=distr(eng);
        if((x*x + y*y) <= 1){
            count++;
        }
    }
    cout<<((float)count)/250000;
}