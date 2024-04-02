#include<iostream>
#include<vector>
using namespace std;

vector<int> calculateSpan(int price[],int n){
    vector<int> ans;
    vector<int> s(n);

    s[0]=1;
    ans.push_back(s[0]);

    for(int i=1;i<n;i++){
        s[i]=1;
        for(int j=i-1;j>=0 && price[i]>=price[j];j--){
            s[i]++;
        }
        ans.push_back(s[i]);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the you want to create"<<endl;
    cin>>n;
    
    int* price=new int[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    vector<int> ans=calculateSpan(price,n);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}