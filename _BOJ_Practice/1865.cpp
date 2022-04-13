#include <bits/stdc++.h>

using namespace std;

struct road{
    int S, E, T;
    road(int a, int b, int c){
        S=a;
        E=b;
        T=c;
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int TC;
    cin >> TC;
    while(TC--){
        int N, M, W;
        cin >> N >> M >> W;
        vector<long long> dist(N+1, INT_MAX);
        vector<road> graph;
        for(int i=0;i<M;i++){
            int S, E, T;
            cin >> S >> E >> T;
            graph.push_back(road(S, E, T));
            graph.push_back(road(E, S, T));
        }

        for(int i=0;i<W;i++){
            int S, E, T;
            cin >> S >> E >> T;
            graph.push_back(road(S, E, -T));
        }

        dist[1] = 0;
        int flag = 0;
        for(int node=1;node<=N;node++){
            for(int i=0;i<graph.size();i++){
                int start = graph[i].S;
                int end = graph[i].E;
                int time = graph[i].T;

                if(dist[start] + time < dist[end]) {
                    dist[end] =  dist[start] + time;

                    if(node == N) {
                        cout << "YES" << '\n';
                        flag = 1;
                        break;
                    }
                }
            }
        } 

        if(flag == 0) cout << "NO\n"; 
    }
    return 0;   
}