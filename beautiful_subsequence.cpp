#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Sort the array to process elements in order
        sort(a.begin(), a.end());
        
        // Count frequency of each element
        unordered_map<int, int> freq;
        for (int num : a) {
            freq[num]++;
        }
        
        int max_size = 0;
        // Try all possible target products
        for (int i = 0; i < n; i++) {
            int current_size = 0;
            unordered_map<int, bool> used;
            
            for (int j = 0; j < n; j++) {
                if (!used[a[j]]) {
                    current_size++;
                    used[a[j]] = true;
                }
            }
            
            max_size = max(max_size, current_size);
        }
        
        // The maximum size is the minimum of the number of distinct elements
        // and the maximum possible size based on the constraints
        int distinct_elements = freq.size();
        max_size = min(max_size, distinct_elements);
        
        cout << max_size << endl;
    }
}

int main() {
    solve();
    return 0;
} 