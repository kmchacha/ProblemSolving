#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

// Union & Find
int unf[1001];
vector<pair<int, int> > enf;

int Find(int v){
    if(unf[v]==v) return v;
    else return unf[v]=Find(unf[v]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) unf[i]=i;
    for(int i=1;i<=m;i++){
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == 'E') {
            for(int j=0;j<enf.size();j++){
                if(a == enf[j].first){
                    if(b > enf[j].second) Union(enf[j].second, b);
                    else Union(b, enf[j].second);
                }else if(a == enf[j].second){
                    if(enf[j].first < b) Union(enf[j].first, b);
                    else Union(b, enf[j].first);
                }else if(b == enf[j].first){
                    if(a > enf[j].second) Union(enf[j].second, a);
                    else Union(a, enf[j].second);
                }else if(b == enf[j].second){
                    if(enf[j].first < a) Union(enf[j].first, a);
                    else Union(a, enf[j].first);
                }
            }
            enf.push_back(make_pair(a, b));
        }else if(c == 'F'){
            Union(a,b);
        }
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(Find(i));
    }

    cout << s.size() << '\n';
    return 0;
}