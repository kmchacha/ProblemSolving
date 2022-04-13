#include <bits/stdc++.h>

using namespace std;

int t[505], indegree[505], res[505];
vector<int> graph[505];

struct compare{
    bool operator()(pair<int, int> &p1, pair<int,int> &p2) {
        return p1.second > p2.second;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> t[i];
        int x;
        cin >> x;
        while(x != -1) {
            graph[x].push_back(i);
            indegree[i]++;

            cin >> x;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
    for(int i=1;i<=N;i++){
        if(indegree[i] == 0) pq.push(make_pair(i, t[i]));
    }
    while(!pq.empty()){
        pair<int, int> cur = pq.top(); pq.pop();
        // cout << cur.first << " " << cur.second << endl;
        res[cur.first] = cur.second;
        for(int i=0;i<graph[cur.first].size();i++){
            int next = graph[cur.first][i];

            indegree[next]--;
            if(indegree[next] == 0) pq.push(make_pair(next, cur.second + t[next]));
        }
    }
    for(int i=1;i<=N;i++) cout << res[i] << '\n';

    return 0;
}