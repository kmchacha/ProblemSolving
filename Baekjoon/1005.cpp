#include <iostream>
#include <vector>

using namespace std;

long long building[1001], cost[1001];

struct Edge{
    int vex;
    Edge(int a){
        vex = a;
    }
};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","rt",stdin);
    int T, n, k, w;
    cin >> T;
    vector<Edge> graph[1001];

    while(T--){
        cin >> n >> k; // 건물의 갯수, 건물 순서 규칙의 수
        for(int i=1;i<=n;i++)   { cin >> building[i]; cost[i]=building[i];}

        // map 설정
        for(int i=1;i<=k;i++){
            int s, e;
            cin >> s >> e;
            graph[s].push_back(Edge(e));
        }
        cin >> w;
        for(int q=1;q<=n;q++){
            for(int i=1;i<=n;i++){
                for(int j=0;j<graph[i].size();j++){
                    int to = graph[i][j].vex;
                    cost[to] = max(cost[i] + building[to], cost[to]);
                }
            }
        }
        cout << cost[w] << '\n';
        
        // 건물 순서 규칙 초기화 및 cost 초기화
        for(int i=1;i<=n;i++)   {
            building[i]=0;
            cost[i]=0;
            while(graph[i].size()!=0) graph[i].pop_back();
        }
    }

    return 0;
}
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>

// using namespace std;

// vector<int> ch(1001), ch2(1001);
// int N, idx=1;

// struct mypair{
//     int vex ,first, second, dist;
//     mypair(int a, int b, int c, int d){
//         vex=a, first=b, second=c, dist=d;
//     }
//     bool operator < (const mypair& m) const {
//         return second < m.second;
//     }
// };
// struct Edge{
//     int vex;
//     Edge(int a){
//         vex=a;
//     }
// };
// void DFS(int v, vector<Edge> graph[], vector<mypair> &node){
//     ch[v]=1;
//     if(node[v].first==0) node[v].first=idx++;

//     for(int i=0;i<graph[v].size();i++){
//         int next = graph[v][i].vex;
//         if(ch[next]==0){
//             DFS(next, graph, node);
//         }
//     }
//     node[v].second = idx++;
// }
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     //freopen("input.txt", "rt", stdin);
//     int T, K, W;
//     cin >> T;
//     while(T--){
//         cin >> N >> K;
//         vector<Edge> graph[N+1];
//         vector<mypair> node(N+1, mypair(0,0,0,0));
//         for(int i=1;i<=N;i++) {
//             cin >> node[i].dist;
//             node[i].vex=i;
//         }
//         for(int i=1;i<=K;i++) {
//             int a, b;
//             cin >> a >> b;
//             graph[a].push_back(Edge(b));
//         }
//         cin >> W;

//         // DFS
//         DFS(1, graph, node);
//         vector<int> pre_path(N+1,0); vector<int> cost(N+1,0);
//         priority_queue<mypair> pQ;
//         int ans=node[W].dist;
//         pQ.push(node[W]);
//         while(!pQ.empty()){
//             mypair tmp = pQ.top();
//             pQ.pop();
//             //cout << "vertex:"<<tmp.vex <<  " start:"<<tmp.first << " end:"<<tmp.second << " dist:"<< tmp.dist << endl;
//             for(int i=1;i<=N;i++){
//                 for(int j=0;j<graph[i].size();j++){
//                     int next = graph[i][j].vex;
//                     if(next==tmp.vex) {
//                         pQ.push(node[i]);
//                         if(cost[i]==0 && cost[next]==0) {
//                             cost[i] = node[i].dist + node[next].dist;
//                         }
//                         else {
//                             //cout << "cost[i]:"<< cost[i] << " cost[next]:" << cost[next] << " node[i].dist:" << node[i].dist << endl;
//                             if(cost[i] < cost[next] + node[i].dist) {
//                                 cost[i] = cost[next] + node[i].dist;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         for(int i=1;i<=N;i++){
//             ans = max(ans, cost[i]);
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }


// Queue + BFS
// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// long long building[1001], cost[1001];
// int ch[1001];
// struct Edge{
//     int vex;
//     Edge(int a){
//         vex = a;
//     }
// };

// int main(){
//     ios_base::sync_with_stdio(false); 
//     cin.tie(NULL); cout.tie(NULL);
//     //freopen("input.txt","rt",stdin);
//     int T, n, k, w;
//     cin >> T;
//     queue<int> Q;
//     vector<Edge> graph[1001];

//     while(T--){
//         cin >> n >> k; // 건물의 갯수, 건물 순서 규칙의 수
//         for(int i=1;i<=n;i++)   { cin >> building[i]; cost[i]=building[i];}

//         // graph 설정
//         for(int i=1;i<=k;i++){
//             int s, e;
//             cin >> s >> e;
//             graph[s].push_back(Edge(e));
//         }
//         cin >> w;

//         Q.push(w);
//         ch[w]=1;
//         while(!Q.empty()){
//             int cur = Q.front();
//             Q.pop();
//             int flag = 0;
//             for(int i=1;i<=n;i++){
//                 for(int j=0;j<graph[i].size();j++){
//                     int next = graph[i][j].vex;
//                     if(next == cur){
//                         flag = 1;
//                         cost[i] = max(building[i]+cost[next], cost[i]);
//                         Q.push(i);
//                     }
//                 }
//             }
//             if(flag==0) ch[cur]=1;
//         }
//         //for(int i=1;i<=n;i++) cout << cost[i] << endl;
//         long long ans = 0;
//         for(int i=1;i<=n;i++)   {
//             if(ch[i]==1){
//                  ans = max(ans, cost[i]);
//             }
//         }
//         cout << ans << '\n';

//         // 건물 순서 규칙 초기화 및 cost 초기화
//         for(int i=1;i<=n;i++)   {
//             building[i]=0;
//             cost[i]=0;
//             ch[i]=0;
//             while(graph[i].size()!=0) graph[i].pop_back();
//         }
//     }

//     return 0;
// }