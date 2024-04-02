#include<iostream>
using namespace std;

class squareRoot{
    public:
    float Sq(float n){
        float x=n;
        float y=1;
        float e=0.000001;
        while(x-y>e){
            x=(x+y)/2;
            y=n/x;
        }
        return x;
    }

};

int main(){
    int n;
    cout<<"Enter the number of which you want to find the square root"<<endl;
    cin>>n;

    squareRoot root;

    cout<<"The square root of "<<n<<" is "<<root.Sq(n)<<endl;
    
    return 0;
}