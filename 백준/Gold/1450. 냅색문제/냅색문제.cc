#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generate_subset_sums(const vector<int>& v, vector<long long int>& subset_sums) {
    int n = v.size();
    int subset_count = 1 << n;  // 2^n
    for (int mask = 0; mask < subset_count; ++mask) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += v[i];
            }
        }
        subset_sums.push_back(sum);
    }
}

int main() {
    int n;
    long long c;
    cin >> n >> c;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    vector<int> lv(arr.begin(), arr.begin() + n / 2);
    vector<int> rv(arr.begin() + n / 2, arr.end());
    
    vector<long long> ls, rs;
    generate_subset_sums(lv, ls);
    generate_subset_sums(rv, rs);

    sort(rs.begin(), rs.end());

    int ans = 0;
    for (long long sum : ls) {
        // Find the number of elements in rs such that sum + element <= c
        ans += upper_bound(rs.begin(), rs.end(), c - sum) - rs.begin();
    }

    cout << ans << endl;

    return 0;
}