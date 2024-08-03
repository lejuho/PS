#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int find(vector<int>& parent, int x) {
    if(parent[x] !=x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
    
}

void uni(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if(rootX != rootY) {
        if(rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if(rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

bool check(vector<int>& parent, vector<int>& rank, int x, int y) {
    return find(parent,  x) == find(parent, y);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> p(n + 1);
    for(int i=0;i<n+1;i++) p[i]=i;
    vector<int> rank(n + 1, 0); // 랭크 배열 초기화


    for(int i = 0; i < m; i++) {
        int c, a, b;
        scanf("%d %d %d", &c, &a, &b);
        if(c == 0) {
            uni(p, rank, a, b);
        } else {
            if(check(p, rank, a, b)) printf("yes\n");
            else printf("no\n");
        }
    }
}
