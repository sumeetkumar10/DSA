#include<iostream>
using namespace std;

void towerOfHanoi(int n,string src,string helper,string dest){
    if(n==1){
        cout<<"Transfer disk"<<n<<" from "<<src<<" to "<<dest<<endl;
        return ;
    }

    towerOfHanoi(n-1,src,dest,helper);
    cout<<"Transfer disk"<<n<<" from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,helper,src,dest);
}

int main(){
    int n;
    cout<<"Enter the number of disks"<<endl;
    cin>>n;

    towerOfHanoi(n,"S","H","D");

    return 0;
}