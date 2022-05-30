// http://poj.org/problem?id=3614

#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_SPF 1000
#define MAX_COW 2500

using namespace std;

pair<int, int> cow[MAX_COW];
int lotion[MAX_SPF+1] = {0};

int main() {
    // init
    int C, L;
    int curCow = 0;
    int count = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // increasing {maxSPF, minSPF}, sort by maxSPF than minSPF

    // process input
    cin >> C >> L;
    for (int i = 0; i < C; i++) {
        cin >> cow[i].first >> cow[i].second;        
    }
    for (int i = 0; i < L; i++) {
        int spf, covers;
        cin >> spf >> covers;
        lotion[spf] += covers;
    }

    // sort cow
    sort(cow, cow + C, less<pair<int, int>>()); // increasing {minSPF, maxSPF}, sort by minSPF than maxSPF

    // iterate each SPF value
    for (int curSPF = 0; curSPF <= MAX_SPF; curSPF ++) {

        // push valid cow
        while(curCow < C and cow[curCow].first <= curSPF) {
            pq.push(make_pair(cow[curCow].second, cow[curCow].first)); // {maxSPF, minSPF}
            curCow ++;
        }

        // pop invalid cow
        while(!pq.empty() and pq.top().first < curSPF)
            pq.pop();

        // give lotion
        while(lotion[curSPF] > 0 and !pq.empty()) {
            pq.pop();
            lotion[curSPF] --;
            count ++;
        }

    }
    
    cout << count;

    return 0;
}