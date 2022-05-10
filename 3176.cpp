#include <iostream>

using namespace std;

#define MAX_N 350

int n;
int cows[MAX_N][MAX_N] = {0};

int main() {

    // process input
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> cows[i][j];
        }
    }

    // dp
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) cows[i][j] += cows[i-1][j];
            else cows[i][j] += max(cows[i-1][j-1], cows[i-1][j]);
        }
    }

    // find max in last row
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, cows[n-1][i]);
    }
    
    cout << res;

    return 0;
}