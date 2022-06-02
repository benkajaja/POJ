// http://poj.org/problem?id=1258

#include <iostream>
#include <queue>

#define MAX_N 100

using namespace std;

int d[MAX_N][MAX_N] = {0};
bool seen[MAX_N] = {false};

int prims(int n) {
    // init
    int totalDistance = 0;
    int nodeCount = n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance, node};

    // start from node 0
    pq.push(make_pair(0, 0));
    while(nodeCount) {

        // pick min distance node
        pair<int, int> item = pq.top();
        pq.pop();

        if (seen[item.second]) continue;
        seen[item.second] = true;
        nodeCount --;
        totalDistance += item.first; 

        // update edge weight
        for (int i = 0; i < n; i++) {
            if (seen[i]) continue;
            pq.push(make_pair(d[item.second][i], i));
        }
    }

    return totalDistance;
}

int main() {
    // init
    int n;

    // read multiple cases
    while (cin >> n) {
        // process input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> d[i][j];
            }
        }
        // clear seen array
        for (int i = 0; i < n; i++) {
            seen[i] = false;
        }
        cout << prims(n) << endl;
    }
    
    return 0;
}