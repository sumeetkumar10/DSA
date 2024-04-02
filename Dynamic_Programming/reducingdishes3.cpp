#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& satisfaction){
    int n=satisfaction.size();
    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);

    for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
            int excl=0+next[time];
            int incl=satisfaction[index]*(time+1)+next[time+1];

            curr[time]=max(excl,incl);
        }
        next=curr;
    }
    return next[0];
}

int maxSatisfaction(vector<int>& satisfaction){
    sort(satisfaction.begin(),satisfaction.end());
    int ans=solve(satisfaction);
    return ans;
}

int main(){
    vector<int> satisfaction={-1,-8,0,5,-9};

    cout<<"The maximum of like-time coefficient is "<<maxSatisfaction(satisfaction)<<endl;

    return 0;
}