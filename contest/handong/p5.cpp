#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct AA{
    int a, b;
};

AA a[201], path[201];
int n, ch[201], ans=2147000000;

void DFS(int L){
    if(L==n){
        int pre = 0, cnt=0;
        int tmp1, tmp2;
        tmp1 = path[1].a; tmp2= path[1].b; pre = path[1].b;
        for(int i=2; i<=n; i++){
            if(pre != path[i].a) return;
            pre =path[i].b;

            cnt += (tmp1 * tmp2 * path[i].a);
            //cout << tmp1 << " " << path[i].b << " " << path[i].a << endl;
            tmp1 = path[i].a; tmp2=path[i].b;
        }
        //cout << "-> " << cnt << endl;
        if(cnt==0) ans = 0;

        ans = min(ans, cnt);
    }else {
        for(int i=1;i<=n;i++){
            if(ch[i]==0){
                ch[i]=1;
                path[L+1] = a[i];
                DFS(L+1);
                ch[i]=0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        int pre=0;  int flag=0;
        for(int i=1;i<=n;i++){
            cin >> a[i].a >> a[i].b;
            if(i!=1 && pre != a[i].a) flag=1;
            pre = a[i].b;
        }

        if(flag==1) { cout << -1 << '\n'; continue;}
        DFS(0);
        cout << ans << '\n';
        ans = 2147000000;
    }
    return 0;
}
