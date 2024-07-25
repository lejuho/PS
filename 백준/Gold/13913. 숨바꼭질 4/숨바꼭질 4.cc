#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int dp[100001];
    int predecessor[100001]; // Array to store the predecessor of each index

    fill_n(dp, 100001, 100001);
    fill_n(predecessor, 100001, -1); // Initialize predecessor array with -1

    dp[n] = 0;
    predecessor[n] = n; // The predecessor of the start node is itself

    for (int i = 0; i < 100001; i++) {
        if (i > 0 && dp[i] > dp[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            predecessor[i] = i - 1;
        }
        if (i < 100000 && dp[i] > dp[i + 1] + 1) {
            dp[i] = dp[i + 1] + 1;
            predecessor[i] = i + 1;
        }
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            predecessor[i] = i/2;
        }
    }
    
    for (int i = 100000; i >-1; i--) {
        if (i > 0 && dp[i] > dp[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            predecessor[i] = i - 1;
        }
        if (i < 100000 && dp[i] > dp[i + 1] + 1) {
            dp[i] = dp[i + 1] + 1;
            predecessor[i] = i + 1;
        }
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            predecessor[i] = i/2;
        }
    }
    
    for (int i = 0; i < 100001; i++) {
        if (i > 0 && dp[i] > dp[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            predecessor[i] = i - 1;
        }
        if (i < 100000 && dp[i] > dp[i + 1] + 1) {
            dp[i] = dp[i + 1] + 1;
            predecessor[i] = i + 1;
        }
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            predecessor[i] = i/2;
        }
    }
    
    for (int i = 100000; i >-1; i--) {
        if (i > 0 && dp[i] > dp[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            predecessor[i] = i - 1;
        }
        if (i < 100000 && dp[i] > dp[i + 1] + 1) {
            dp[i] = dp[i + 1] + 1;
            predecessor[i] = i + 1;
        }
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            predecessor[i] = i/2;
        }
    }
    
    for (int i = 0; i < 100001; i++) {
        if (i > 0 && dp[i] > dp[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            predecessor[i] = i - 1;
        }
        if (i < 100000 && dp[i] > dp[i + 1] + 1) {
            dp[i] = dp[i + 1] + 1;
            predecessor[i] = i + 1;
        }
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            predecessor[i] = i/2;
        }
    }
    
    for (int i = 100000; i >-1; i--) {
        if (i > 0 && dp[i] > dp[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            predecessor[i] = i - 1;
        }
        if (i < 100000 && dp[i] > dp[i + 1] + 1) {
            dp[i] = dp[i + 1] + 1;
            predecessor[i] = i + 1;
        }
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            predecessor[i] = i/2;
        }
    }
    
    for (int i = 0; i < 100001; i++) {
        if (i > 0 && dp[i] > dp[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            predecessor[i] = i - 1;
        }
        if (i < 100000 && dp[i] > dp[i + 1] + 1) {
            dp[i] = dp[i + 1] + 1;
            predecessor[i] = i + 1;
        }
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            predecessor[i] = i/2;
        }
    }
    
    for (int i = 100000; i >-1; i--) {
        if (i > 0 && dp[i] > dp[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            predecessor[i] = i - 1;
        }
        if (i < 100000 && dp[i] > dp[i + 1] + 1) {
            dp[i] = dp[i + 1] + 1;
            predecessor[i] = i + 1;
        }
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            predecessor[i] = i/2;
        }
    }
    cout << dp[k] << endl;
    // Backtrack from k to n using the predecessor array
    vector<int> res;
    for (int i = k; i != n; i = predecessor[i]) {
        res.push_back(i);
    }
    res.push_back(n); // Finally add the start node

    reverse(res.begin(), res.end()); // Reverse to get the path from n to k

    // Print the path (optional)
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
