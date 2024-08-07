#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include<algorithm>
using namespace std;
typedef pair<int, pair<int, int>> p;
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

int main() {
    int v,e;
    scanf("%d %d", &v,&e);
    vector<int> parent(v+1);
    vector<int> rank(v+1, 0);
    vector<p> mst;
    for (int j = 0; j < v+1; j++) {
        parent[j] = j;
    }
    for (int j = 0; j < e; j++) {
        int p, c,w;
        scanf("%d %d %d",&p,&c,&w);
        mst.push_back(make_pair(w,make_pair(min(p,c),max(p,c))));
        }
    sort(mst.begin(), mst.end());
    int ans=0;
    for(auto x:mst){
        if(!uni(parent,rank,x.second.first,x.second.second)) continue;
        else ans+=x.first;
    }
    printf("%d",ans);
}