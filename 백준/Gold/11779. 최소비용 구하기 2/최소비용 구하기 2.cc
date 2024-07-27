#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<pair<int, int>>> edge(n + 1); // n+1로 벡터 초기화
    
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        edge[s].push_back(make_pair(e, w));
    }
    
    int a, b;
    cin >> a >> b;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu; // 최소 힙으로 변경
    vector<int> dist(n + 1, int(1e9)); // 벡터로 dist 초기화
    dist[a] = 0;
    vector<int> pre(n + 1, -1); // 벡터로 pre 초기화
    
    qu.push(make_pair(0, a));
    
    while (!qu.empty()) {
        int d = qu.top().first;
        int now = qu.top().second;
        qu.pop();
        
        if (d > dist[now]) continue;
        
        for (auto x : edge[now]) {
            int next = x.first;
            int weight = x.second;
            int tmpdist = d + weight;
            
            if (tmpdist < dist[next]) {
                dist[next] = tmpdist;
                pre[next] = now;
                qu.push(make_pair(tmpdist, next));
            }
        }
    }
    
    cout << dist[b] << endl;
    
    // 경로 역추적
    vector<int> path;
    int cnt=0;
    for (int i = b; i != -1; i = pre[i]) {
        path.push_back(i);
        cnt++;
    }
    reverse(path.begin(), path.end());
    cout<<cnt<<endl;
    for (int i : path) {
        cout << i << " ";
    }
    
    return 0;
}
