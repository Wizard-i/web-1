#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        
        // Read input and store with indices
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        // Sort based on the values
        sort(a.begin(), a.end());
        
        // Create b by assigning the reverse of sorted values
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[a[i].second] = n - i;
        }
        
        // Output the result
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
} 