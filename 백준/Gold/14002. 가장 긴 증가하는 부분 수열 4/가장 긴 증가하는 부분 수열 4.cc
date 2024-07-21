#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    int num[1000]={0,};
    int dp[1000];
    fill_n(dp,1000,1);
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        num[i]=tmp;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(num[i]>num[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int last=-1;
    int start=-1;
    for(int i=0;i<n;i++){
        if(dp[i]>last){
            last=dp[i];
            start=i;
        }
    }
    cout<<last<<endl;
    vector<int> v;
    while(start>-1){
        if(dp[start]==last){
            v.push_back(num[start]);
            last--;
        }
        start--;
    }
    for(int i=v.size()-1;i>-1;i--)cout<<v[i]<<"\t";
}