#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
using namespace std;

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
    int n,m;
    scanf("%d %d", &n,&m);
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);  // 초기 랭크는 0
    for (int j = 0; j < n+1; j++) {
        parent[j] = j;
    }
    int ans=1;
    for (int j = 0; j < m; j++) {
        
        int p, c;
        scanf("%d %d",&p,&c);
        if(!uni(parent, rank, p, c)) break;
        else ans++;
        }
    if(ans==m+1){
        printf("%d",0);
    }
    else printf("%d",ans);
    }
