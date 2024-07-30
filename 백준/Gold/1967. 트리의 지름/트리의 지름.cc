#include <iostream>
#include <vector>
#include <utility>
#include <cstring> // memset 사용을 위해 필요

using namespace std;

// DFS 함수
int dfs(int cur, int dist, vector<vector<pair<int, int>>>& graph, bool visited[], int& maxDist, int& farthestNode) {
    visited[cur] = true;

    // 현재 거리보다 크면 갱신
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = cur;
    }

    for (auto& ad : graph[cur]) {
        int nextNode = ad.first;
        int nextDist = ad.second + dist;
        if (!visited[nextNode]) {
            dfs(nextNode, nextDist, graph, visited, maxDist, farthestNode);
        }
    }
    return farthestNode;
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n + 1);

    // 그래프 입력 처리
    for (int i = 1; i < n; ++i) {
        int tmp, node, weight;
        cin >> node >> tmp >> weight;
        graph[node].push_back(make_pair(tmp, weight));
        graph[tmp].push_back(make_pair(node, weight));
    }

    bool visited[100001];
    int maxDist = 0;
    int farthestNode = 1;

    // 첫 번째 DFS: 임의의 정점(1번)에서 가장 먼 정점을 찾음
    memset(visited, false, sizeof(visited));
    farthestNode = dfs(1, 0, graph, visited, maxDist, farthestNode);

    // 두 번째 DFS: 찾은 정점에서 가장 먼 정점을 찾아 트리의 지름 구함
    maxDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(farthestNode, 0, graph, visited, maxDist, farthestNode);

    // 트리의 지름 출력
    cout << maxDist << endl;

    return 0;
}