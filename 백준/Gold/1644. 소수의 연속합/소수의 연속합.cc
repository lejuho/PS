#include<iostream>
#include<vector>
using namespace std;

int main(){
    bool minor[4000000];
    fill_n(minor,4000000,true);
    minor[0]=false;
    minor[1]=false;
    for(int i=2;i<4000000;i++){
        if(minor[i]){
            for(int j=i+i;j<4000000;j+=i){
                minor[j]=false;
            }
        }
    }
    int n;
    cin>>n;
    vector<long long int> v={0};
    bool solo=false;
    int cnt=0;
    for(long long int i=0;i<4000000;i++){
        if(minor[i]) {
            v.push_back(i);
            cnt+=1;
            if(n==i)solo=true;
        }
    }
    for(int i=1;i<cnt+1;i++){
        v[i]+=v[i-1];
    }
    int s=0;
    int e=1;
    int ans=0;
    while(e>s and e<cnt+1){
        if(v[e]-v[s]==n){
            ans++;
            e++;
        }
        else if(v[e]-v[s]<n) e++;
        else s++;
    }
    cout<<ans;;
}