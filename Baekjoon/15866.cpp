#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int m, ans=2147000000, ch[15];
vector<pair<int, int> > hs;
vector<pair<int, int> > ck;
void DFS(int s, int L){
    if(L==m){
        int sum=0, dis;
        for(int i=0;i<hs.size();i++){
            int x1=hs[i].first;
            int y1=hs[i].second;
            dis=2147000000;
            for(int j=0;j<m;j++){
                int x2=ck[ch[j]].first;
                int y2=ck[ch[j]].second;
                dis=min(dis, abs(x1-x2)+abs(y1-y2));
            }
            sum += dis;
        }
        if(sum < ans) ans = sum;
    }else {
        for(int i=s;i<ck.size();i++){
            ch[L]=i;
            DFS(i+1, L+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int k;
            cin >> k;
            if(k==1) hs.push_back(make_pair(i,j));
            else if(k==2) ck.push_back(make_pair(i,j));
        }
    }
    DFS(0, 0);
    cout << ans << endl;
    return 0;
}