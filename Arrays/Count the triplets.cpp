#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplet(int arr[], int n) {
        // Your code goes here
        int i = 0, j = 0, k = 0, ans = 0;
        sort(arr, arr + n);

        for (int i = n - 1; i >= 0; i--) {
            int target = arr[i];
            int l = 0, h = i - 1;

            while(l < h) {
                int curr = arr[l] + arr[h];

                if(curr == target) {
                    ans++;
                    l++;
                    h--;
                }

                else if(curr > target)
                    h--;

                else
                    l++;
            }
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";
    }

    return 0;
}