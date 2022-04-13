#include <bits/stdc++.h>

using namespace std;

struct Edge{
    long long from, to, value;
    Edge(long long a, long long b, long long c){
        from = a;
        to = b;
        value = c;
    }
    bool operator < (const Edge &e) const {
        return value < e.value;
    }
};

long long V, E, answer, unf[10005];
vector<Edge> graph;

int find(int v){
    if(v == unf[v]) return v;
    else return unf[v] = find(unf[v]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) unf[a] = b;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> V >> E;
    for(int i=1;i<=V;i++) unf[i] = i;
    for(int i=0;i<E;i++){
        long long A, B, C;
        cin >> A >> B >> C;
        graph.push_back(Edge(A, B, C));
    }
    sort(graph.begin(), graph.end());
    for(int i=0;i<graph.size();i++){
        int a = graph[i].from;
        int b = graph[i].to;
        long long value = graph[i].value;

        if(find(a) != find(b)) {
            Union(min(a, b), max(a, b));
            answer += value;
        }

    }
    for(int i=1;i<=V;i++){ 
        cout << unf[i] << " ";
    }
    
    cout << answer;
    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;

// long long V, E, answer, check[10005];
// struct Edge{
//     long long from, to, value;
//     Edge(long long a, long long b, long long c){
//         from = a;
//         to = b;
//         value = c;
//     }
//     bool operator < (const Edge &e) const {
//         return value < e.value;
//     }
// };
// vector<Edge> graph;

// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     freopen("input.txt", "rt", stdin);
//     cin >> V >> E;
//     for(int i=0;i<E;i++){
//         long long A, B, C;
//         cin >> A >> B >> C;
//         graph.push_back(Edge(A, B, C));
//     }
//     sort(graph.begin(), graph.end());
    
//     cout << answer;
//     return 0;
// }