#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<double, pair<int, int>> p;
int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);  // 경로 압축
    }
    return parent[x];
}

bool uni(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
 // 크기 합치기
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
 // 크기 합치기
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
 // 크기 합치기
        }
        return true;
    }
    return false;
}

bool check(vector<int>& parent, int x, int y) {
    return find(parent, x) == find(parent, y);
}

double dist(double x1,double y1,double x2,double y2){
    return sqrt(abs((y2-y1)*(y2-y1))+abs((x2-x1)*(x2-x1)));
}
int main() {
    int n;
    scanf("%d", &n);
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    vector<p> mst;
    vector<pair<double,double>> li;
    for (int j = 0; j < n+1; j++) {
        parent[j] = j;
    }
    for (int j = 0; j < n; j++) {
        double a,b;
        scanf("%lf %lf",&a,&b);
        li.push_back(make_pair(a,b));
        }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i!=j) mst.push_back(make_pair(dist(li[i].first,li[i].second,li[j].first,li[j].second),make_pair(i,j)));
        }
    }
    sort(mst.begin(), mst.end());
    double ans=0;
    for(auto x:mst){
        if(!uni(parent,rank,x.second.first,x.second.second)) continue;
        else ans+=x.first;
    }
    printf("%.2lf",ans);
}