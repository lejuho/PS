#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void rec(vector<int>& res,vector<int>& v,int s,int e){
    if(s>e) return;
    int i;
    int root=v[s];
    bool check=false;
    for(int j=s;j<e+1;j++){
        
        if(v[j]>root){
            i=j;
            check=true;
            break;
        }
    }
    if(check) {
        rec(res,v,s+1,i-1);
        rec(res,v,i,e);
    }
    else{
        rec(res,v,s+1,e);
    }
    res.push_back(v[s]);
}


int main(){
    int tmp;
    vector<int> pre;
    vector<int> ans;
    
    while(cin>>tmp){
        pre.push_back(tmp);
    }
    rec(ans,pre,0,pre.size()-1);
    for(auto x:ans) cout<<x<<endl;
}