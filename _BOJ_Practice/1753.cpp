#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int, int> > map[300001];
priority_queue<pair<int, int> > pQ;

struct Edge{
    int v;
    int cost;
    Edge(int a, int b){
        v=a;
        cost=b;
    }
    bool operator < (Edge& e){
        return cost>e.cost;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m, s;
    cin >> n >> m >> s;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back(make_pair(c,b));
    }
    vector<int> ch(n+1);
    vector<int> dist(n+1);
    for(int i=1;i<=n;i++){
        dist[i]=2147000000;
    }
    dist[s]=0;
    pQ.push(make_pair(0, s));
    while(!pQ.empty()){
        int now = pQ.top().second;
        int cost = -pQ.top().first;
        pQ.pop();
        ch[now]=1;
        for(int i=0;i<map[now].size();i++){
            int next = map[now][i].second;
            int nextDis = cost + map[now][i].first;
            if((dist[next] > nextDis) && ch[next]==0){
                dist[next] = nextDis;
                pQ.push(make_pair(-nextDis, next));
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]==2147000000) {
            cout << "INF" << '\n';
            continue;
        }
        cout << dist[i] << '\n';
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using namespace std;
// priority_queue<pair<int, int> > pQ;
// vector<pair<int, int> > map[300001];
// int dist[20001];
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     freopen("input.txt", "rt", stdin);
//     int n, m, s;
//     cin >> n >> m;
//     cin >> s;
//     for(int i=0;i<m;i++){
//         int a, b, c;
//         cin >> a >> b >> c;
//         map[a].push_back(make_pair(c, b)); // 비용 / 도착
//     }
//     for(int i=1;i<=n;i++){
//         dist[i]=2147000000;
//     }
//     dist[s]=0;
//     pQ.push(make_pair(0,s));
//     while(!pQ.empty()){
//         pair<int, int> tmp = pQ.top();
//         pQ.pop();
//         int now = tmp.second;
//         int cost = -tmp.first;
//         if(cost>dist[now]) continue;
//         for(int i=0;i<map[now].size(); i++){
//             int next=map[now][i].second;
//             int nextDis=cost+map[now][i].first;
//             if(dist[next] > nextDis){
//                 dist[next] = nextDis;
//                 pQ.push(make_pair(-nextDis, next));
//             }
//         }
//     }
//     for(int i=1;i<=n;i++){
//         if(dist[i]==2147000000) {
//             cout << "INF" << '\n';
//             continue;
//         }
//         cout << dist[i] << '\n';
//     }
//     return 0;
// }