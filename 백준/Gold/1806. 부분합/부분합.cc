#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,s;
    cin>>n>>s;
    vector<int> v={0};
    int tmp;
    bool solo=false;
    bool whole=false;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
        if(tmp==s) solo=true;
    }
    for(int i=1;i<n+1;i++){
        v[i]=v[i]+v[i-1];
    }
    int mini=100001;
    int i,j;
    i=0;
    j=1;
    if(!solo){
    while(i<j && j<n+1){
        if(v[j]-v[i]<s){
            j++;
        }
        else{
            if(mini>j-i) mini=j-i;
            i++;
        }
        
    }
    }
    if(!solo){
    if(mini==100001){
        cout<<0;
    }
    else cout<<mini;}
    else cout<<1;
}