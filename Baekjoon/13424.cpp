#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 다익스트라 알고리즘 --> struct, priority queue
struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex = a;
        dis = b;
    }
    bool operator < (const Edge &b) const{
        return dis > b.dis;
    }
};  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    while(T-->0){
        int n, m, k, c;
        cin >> n >> m;
        vector<int> dist(n+1, 2147000000), sum(n+1, 0);
        vector<pair<int, int> > graph[n+1];
        priority_queue<Edge> pQ;
        for(int i=1;i<=m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back(make_pair(b,c));
            graph[b].push_back(make_pair(a,c));
        }
        cin >> k;
        for(int i=1;i<=k;i++){
            cin >> c;
            pQ.push(Edge(c,0));
            dist[c]=0;
            while(!pQ.empty()){
                int now = pQ.top().vex;
                int cost = pQ.top().dis;
                pQ.pop();
                if(cost > dist[now]) continue;
                for(int j=0;j<graph[now].size();j++){
                    int next = graph[now][j].first;
                    int nextDis = graph[now][j].second + cost;
                    if(dist[next]>nextDis){
                        dist[next]=nextDis;
                        pQ.push(Edge(next, nextDis));
                    }
                }
            }
            // 초기화
            for(int j=1;j<=n;j++) {
                sum[j] += dist[j];
                dist[j] = 2147000000;
            }
        }

        int tmp = 2147000000, ans=0;
        for(int i=1;i<=n;i++){
            if(tmp > sum[i]){
                tmp = sum[i];
                ans = i;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
