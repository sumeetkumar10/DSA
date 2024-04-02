#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& satisfaction,int index,int time){
    if(index==satisfaction.size()){
        return 0;
    }

    int excl=0+solve(satisfaction,index+1,time);
    int incl=satisfaction[index]*(time+1)+solve(satisfaction,index+1,time+1);

    return max(excl,incl);
}

int maxSatisfaction(vector<int>& satisfaction){
    sort(satisfaction.begin(),satisfaction.end());
    int ans=solve(satisfaction,0,0);
    return ans;
}

int main(){
    vector<int> satisfaction={-1,-8,0,5,-9};

    cout<<"The maximum of like-time coefficient is "<<maxSatisfaction(satisfaction)<<endl;

    return 0;
}