#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parent, int x) {
    if(parent[x] != x) {
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1);
    vector<int> rank(n+1, 1);

    // Initialize the Union-Find structure
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // Read the connection matrix and perform union operations
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int connected;
            cin >> connected;
            if(connected == 1) {
                uni(parent, rank, i, j);
            }
        }
    }

    vector<int> route(m);
    for(int i = 0; i < m; i++) {
        cin >> route[i];
    }

    bool possible = true;
    for(int i = 1; i < m; i++) {
        if(find(parent, route[i-1]) != find(parent, route[i])) {
            possible = false;
            break;
        }
    }

    if(possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
