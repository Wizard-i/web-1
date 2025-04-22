#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_cost(const string& s) {
    int cost = 0;
    char current = '0';
    
    for (char c : s) {
        if (c != current) {
            cost++;
            current = c;
        }
        cost++; // Press the button
    }
    
    return cost;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        // Calculate cost without any reversal
        int min_cost = calculate_cost(s);
        
        // Find all positions where the character changes
        vector<int> change_positions;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                change_positions.push_back(i);
            }
        }
        
        // Try reversing around change positions
        for (int pos : change_positions) {
            // Try reversing a small window around the change position
            for (int len = 1; len <= 3; len++) {
                int start = max(0, pos - len);
                int end = min(n-1, pos + len);
                
                string temp = s;
                reverse(temp.begin() + start, temp.begin() + end + 1);
                min_cost = min(min_cost, calculate_cost(temp));
            }
        }
        
        // Also try reversing the entire string
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        min_cost = min(min_cost, calculate_cost(reversed));
        
        cout << min_cost << endl;
    }
}

int main() {
    solve();
    return 0;
} 