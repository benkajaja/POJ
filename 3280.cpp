// http://poj.org/problem?id=3280

#include <iostream>
#include <string>
#define MAX_M 2000
#define MAX_N 26

using namespace std;

int n, m;
int dp[MAX_M][MAX_M] = {0};
int cost[MAX_N];
string s;

int main() {
    // process input
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n; i++) {
        char c;
        int addingCost, deletingCost;
        cin >> c;
        cin >> addingCost >> deletingCost;
        cost[c-'a'] = min(addingCost, deletingCost);
    }

    // dp
    for (int i = m-1; i >= 0; i--) {
        for (int j = i+1; j < m; j++) {
            if (s[i] == s[j] and (i+1 == j or dp[i+1][j-1] == 0)) continue;
            else {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = min(dp[i][j-1] + cost[s[j]-'a'],  dp[i+1][j] + cost[s[i]-'a']);
                }
                
            }
        }
    }

    cout << dp[0][m-1];

    return 0;
}