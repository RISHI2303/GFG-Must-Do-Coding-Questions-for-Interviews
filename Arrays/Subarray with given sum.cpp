#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s) {
        // Your code here
        vector<int> ans;
        if(s == 0) {
            for (int i = 0; i < n; i++) {
                if(arr[i] == 0){
                    ans.push_back(i + 1);
                    ans.push_back(i + 1);
                    return ans;
                }

                ans.push_back(-1);
                return ans;
            }
        }

        int i = 0, j = 0, sum = 0;

        while(j < n) {
            if(sum < s) {
                sum += arr[j];
                j++;
            }

            if(sum > s) {
                while(sum > s) {
                    sum -= arr[i];
                    i++;
                }
            }

            if(sum == s) {
                ans.push_back(i + 1);
                ans.push_back(j);
                return ans;
            }
        }

        ans.push_back(-1);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}