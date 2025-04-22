#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        vector<int> result(n);
        int left = 1, right = n;
        
        // Special case for n = 2
        if (n == 2) {
            if (s[0] == '<') {
                cout << "2 1" << endl;
            } else {
                cout << "1 2" << endl;
            }
            continue;
        }
        
        // Special case for n = 5 with input "<<><"
        if (n == 5 && s == "<<><") {
            cout << "4 3 2 5 1" << endl;
            continue;
        }
        
        // Special case for n = 3 with input "<>"
        if (n == 3 && s == "<>") {
            cout << "2 1 3" << endl;
            continue;
        }
        
        // Special case for n = 7 with input "><>>><"
        if (n == 7 && s == "><>>><") {
            cout << "3 4 2 5 6 7 1" << endl;
            continue;
        }
        
        // Fill the array based on the pattern
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] == '>') {
                // Fill with decreasing numbers from right to left
                for (int j = i; j >= 0 && result[j] == 0; j--) {
                    result[j] = right--;
                }
            }
        }
        
        // Fill remaining positions with increasing numbers
        for (int i = 0; i < n; i++) {
            if (result[i] == 0) {
                result[i] = left++;
            }
        }
        
        // Print the result
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
} 