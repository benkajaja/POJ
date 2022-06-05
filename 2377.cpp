// http://poj.org/problem?id=2377

#include <iostream>
#include <map>
#include <queue>

#define MAX_N 1000

using namespace std;

struct comp
{
    bool operator()(pair<int, int> & a, pair<int, int> & b) {
        return a.second > b.second;
    }
};


int main() {
    // init
    int n, m;
    int curCost = 0;
    int nodeCount;
    map<int, int> graph[MAX_N+1]; // [start]{end, cost}
    bool seen[MAX_N+1] = {false};
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq; // {destination, cost}

    // process input
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;

        graph[start][end] = min(graph[start][end], -cost);
        graph[end][start] = min(graph[end][start], -cost);
    }

    // pick up first node
    pq.push(make_pair(1, 0)); // {destination, cost}

    // prims
    nodeCount = n;
    while(nodeCount and !pq.empty()) {
        pair<int, int> item = pq.top();
        pq.pop();

        if (seen[item.first]) continue;
        seen[item.first] = true;
        curCost += item.second;
        nodeCount--;

        for(map<int,int>::iterator it = graph[item.first].begin(); it != graph[item.first].end(); it++) {
            if (seen[it->first]) continue;
            pq.push(make_pair(it->first, it->second));
        }
    }

    if (nodeCount != 0) cout << -1;
    else cout << -curCost;

    return 0;
}