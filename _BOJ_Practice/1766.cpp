#include <bits/stdc++.h>

using namespace std;

int indegree[32005];
vector<int> graph[32005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=1;i<=N;i++) {
        if(indegree[i] == 0) pq.push(i);
    }
    while(!pq.empty()){
        int cur = pq.top(); pq.pop();
        cout << cur << " ";

        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            indegree[next]--;
            if(indegree[next] == 0) pq.push(next);
        }
    }
    return 0;
}