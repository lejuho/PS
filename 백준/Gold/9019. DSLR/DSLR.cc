#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main(){
    int c;
    cin >> c;
    for(int i = 0; i < c; i++){
        int a, b;
        cin >> a >> b;

        vector<int> dp(10001, 10001); // 최단 거리를 저장하는 배열
        vector<pair<int, string>> pre(10001, make_pair(-1, "m")); // 이전 상태와 명령어를 저장하는 배열

        dp[a] = 0; // 시작점의 거리는 0
        queue<int> q; // BFS를 위한 큐
        q.push(a);

        while(!q.empty()){
            int current = q.front();
            q.pop();

            // D 명령어
            int D = (current * 2) % 10000;
            if(dp[D] > dp[current] + 1){
                dp[D] = dp[current] + 1;
                pre[D] = make_pair(current, "D");
                q.push(D);
            }

            // S 명령어
            int S = (current == 0) ? 9999 : current - 1;
            if(dp[S] > dp[current] + 1){
                dp[S] = dp[current] + 1;
                pre[S] = make_pair(current, "S");
                q.push(S);
            }

            // L 명령어
            int L = (current % 1000) * 10 + current / 1000;
            if(dp[L] > dp[current] + 1){
                dp[L] = dp[current] + 1;
                pre[L] = make_pair(current, "L");
                q.push(L);
            }

            // R 명령어
            int R = (current % 10) * 1000 + current / 10;
            if(dp[R] > dp[current] + 1){
                dp[R] = dp[current] + 1;
                pre[R] = make_pair(current, "R");
                q.push(R);
            }
        }

        // 결과 추적
        vector<string> result;
        for(int i = b; i != a; i = pre[i].first){
            result.push_back(pre[i].second);
        }
        reverse(result.begin(), result.end());

        // 결과 출력
        for(const string& s : result) {
            cout << s;
        }
        cout << endl;
    }
    return 0;
}