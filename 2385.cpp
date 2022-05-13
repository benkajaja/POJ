// http://poj.org/problem?id=2385

#include <iostream>

#define MAX_T 1000
#define MAX_W 30
using namespace std;

int t, w;
int dp[MAX_T][MAX_W+1] = {0};
int apples[MAX_T];

using namespace std;

int main() {
    
    // process input
    cin >> t;
    cin >> w;
    for (int i = 0; i < t; i++) {
        cin >> apples[i];
    }

    // process time = 1
    if (apples[0] == 1) {
        dp[0][0] = 1;
    } else {
        dp[0][1] = 1;
    }

    // dp
    for (int i = 1; i < t; i++) {
        for (int j = 0; j <= min(i+1, w); j++) {
            if (j == 0) {
                if (apples[i] == 1) dp[i][0] = dp[i-1][0] + 1; // Pos1 catch apple
                else dp[i][0] = dp[i-1][0];
            } else if (j % 2 == 0 and apples[i] == 1 or j % 2 == 1 and apples[i] == 2) { // Pos1 catch apple while number of transition is even or Pos2 catch apple while number of transition is odd
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + 1;
            } else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }

    // find max in last row
    int res = 0;
    for (int i = 0; i <= w; i++) {
        res = max(res, dp[t-1][i]);
    }

    cout << res;

    return 0;
}
