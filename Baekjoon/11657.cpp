// 최단 경로 문제에서 한 노드(도시)에서 각 노드(도시)들에 대한 최단경로를 구할 때 벨만-포드 알고리즘을 떠올리자.
// 벨만-포드 알고리즘은 시작노드(도시)를 제외한 전체 노드수 만큼의 edge relaxation을 수행해야 합니다. 
// D(s,v) = D(s,u) + w(u,v)

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long dist[501];

struct edge{
    int s;
    int e;
    int val;
    edge(int a, int b, int c){
        s=a, e=b, val=c;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    vector<edge> Ed;
    cin >> n >> m; // 도시의 개수 , 버스의 개수

    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        Ed.push_back(edge(a,b,c)); // 버스 노선의 정보 입력 받기
    }
    
    // 벨만-포드 알고리즘 적용 -> 각 엣지를 검사하면서 값을 relaxation
    for(int i=1;i<=n;i++){
        dist[i]=9223000000000000000;    // 각 노드 초기화
    }
    
    dist[1]=0; // ********* 시작 노드 초기화 *************

    for(int j=1;j<n;j++){
        for(int i=0;i<Ed.size();i++){
            int start = Ed[i].s;
            int end = Ed[i].e;
            int value = Ed[i].val;
            if(dist[start]!=9223000000000000000 && dist[start] + value < dist[end]){
                dist[end] = dist[start] + value;
            }
        }
    }

    // 한번 더 relaxation이 되는 경우
    for(int i=0;i<Ed.size();i++){
        int start = Ed[i].s;
        int end = Ed[i].e;
        int value = Ed[i].val;
        if(dist[start]!=9223000000000000000 && dist[start] + value < dist[end]){
            cout << -1 << '\n';
            exit(0);
        }
    }

    // 결과 출력, dist[i]의 값이 변하지 않았으면 -1을 출력하고, 변했으면 값을 그대로 출력
    for(int i=2;i<=n;i++){
        if(dist[i]==9223000000000000000) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}





// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// long long dist[501];
// struct Edge{
//     int s;
//     int e;
//     int val;
//     Edge(int a, int b, int c){
//         s = a;
//         e = b;
//         val = c;
//     }
// };
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     //freopen("input.txt", "rt", stdin);
//     vector<Edge> Ed;
//     int i, n, m, a, b, c, j, s;
//     cin >> n >> m;
//     for(i=1;i<=m;i++){
//         cin >> a >> b >> c;
//         Ed.push_back(Edge(a,b,c));
//     }
    
//     // BELLMAN-FORD  
//     for(i=1;i<=n;i++){
//         dist[i]=9223000000000000000;
//     }
//     s=1;
//     dist[s]=0; // 출발점
//     for(i=1;i<=n;i++){
//         for(j=0;j<Ed.size();j++){
//             int u=Ed[j].s;
//             int v=Ed[j].e;
//             int w=Ed[j].val;
//             // Relax
//             if(dist[u]!=9223000000000000000 && dist[u]+w < dist[v]){
//                 dist[v] = dist[u] + w;
//                 if(i==n) {
//                     cout << "-1" << '\n';
//                     exit(0);
//                 }
//             }
//         }
//     }

//     for(int i=2;i<=n;i++){
//         if(dist[i]==9223000000000000000) cout <<"-1" << '\n';
//         else cout << dist[i] << '\n';
//     }
//     return 0;
// }