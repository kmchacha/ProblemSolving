#include <iostream>

using namespace std;

int n, ans=-2147000000;
int _plus[21], _minus[21],  ch[21];

void DFS(int v){
    if(n+1 == v){
        int sum=0, hp=100;
        for(int i=1;i<=n;i++){
            if(ch[i]==1){
                sum += _plus[i];
                hp -= _minus[i];
            }
        }

        if(hp>0 && ans < sum) ans = sum;
        return;
    }
    ch[v]=1;
    DFS(v+1);
    ch[v]=0;
    DFS(v+1);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","rt",stdin);
    cin >> n;
    for(int i=1;i<=n;i++)   cin >> _minus[i];
    for(int i=1;i<=n;i++)   cin >> _plus[i];
    DFS(1);
    cout << ans;
    return 0;
}