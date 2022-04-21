#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long building[1001], cost[1001];
int ch[1001];
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
    queue<int> Q;
    vector<Edge> graph[1001];

    while(T--){
        cin >> n >> k; // 건물의 갯수, 건물 순서 규칙의 수
        for(int i=1;i<=n;i++)   { cin >> building[i]; cost[i]=building[i];}

        // graph 설정
        for(int i=1;i<=k;i++){
            int s, e;
            cin >> s >> e;
            graph[s].push_back(Edge(e));
        }
        cin >> w;

        Q.push(w);
        ch[w]=1;
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            int flag = 0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<graph[i].size();j++){
                    int next = graph[i][j].vex;
                    if(next == cur){
                        flag = 1;
                        cost[i] = max(building[i]+cost[next], cost[i]);
                        Q.push(i);
                    }
                }
            }
            if(flag==0) ch[cur]=1;
        }
        //for(int i=1;i<=n;i++) cout << cost[i] << endl;
        long long ans = 0;
        for(int i=1;i<=n;i++)   {
            if(ch[i]==1){
                 ans = max(ans, cost[i]);
            }
        }
        cout << ans << '\n';

        // 건물 순서 규칙 초기화 및 cost 초기화
        for(int i=1;i<=n;i++)   {
            building[i]=0;
            cost[i]=0;
            ch[i]=0;
            while(graph[i].size()!=0) graph[i].pop_back();
        }
    }

    return 0;
}