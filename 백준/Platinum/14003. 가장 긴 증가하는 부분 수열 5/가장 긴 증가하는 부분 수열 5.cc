#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> dp;
    vector<int> id(n, -1);
    vector<int> predecessor(n, -1);

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
        int idx = it - dp.begin();

        if (it == dp.end()) {
            dp.push_back(nums[i]);
            if (dp.size() > 1) {
                predecessor[i] = id[dp.size() - 2];
            }
        } else {
            *it = nums[i];
            if (idx > 0) {
                predecessor[i] = id[idx - 1];
            }
        }
        id[idx] = i;
    }

    // Reconstruct LIS
    vector<int> lis(dp.size());
    int length = dp.size();
    for (int i = id[length - 1]; i >= 0; i = predecessor[i]) {
        lis[--length] = nums[i];
    }

    // Output
    cout << dp.size() << endl;
    for (auto x : lis) cout << x << " ";

    return 0;
}
