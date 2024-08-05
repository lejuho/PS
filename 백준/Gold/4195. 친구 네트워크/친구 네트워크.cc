#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);  // 경로 압축
    }
    return parent[x];
}

void uni(vector<int>& parent, vector<int>& rank, vector<int>& size, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];  // 크기 합치기
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];  // 크기 합치기
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
            size[rootX] += size[rootY];  // 크기 합치기
        }
    }
}

bool check(vector<int>& parent, int x, int y) {
    return find(parent, x) == find(parent, y);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int f;
        scanf("%d", &f);
        unordered_map<string, int> m;
        vector<int> parent(f * 2 + 1);
        vector<int> size(f * 2 + 1, 1);  // 초기에는 모든 집합의 크기가 1
        vector<int> rank(f * 2 + 1, 0);  // 초기 랭크는 0
        for (int j = 0; j < f * 2 + 1; j++) {
            parent[j] = j;
        }
        int index = 0;
        for (int j = 0; j < f; j++) {
            string p, c;
            cin >> p >> c;
            if (m.find(p) == m.end()) {
                m[p] = index++;
            }
            if (m.find(c) == m.end()) {
                m[c] = index++;
            }
            int f = m[p];
            int s = m[c];
            uni(parent, rank, size, f, s);
            printf("%d\n", size[find(parent, f)]);
        }
    }
    return 0;
}
