#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char str[100001][4], path[100001][4];
int n, ch[100001], ans=2147000000;

void DFS(int v){
    if(v == 3){
        int sum=0;
        // for(int i=0;i<3;i++){
        //     cout << path[i] << " ";
        // }
        // cout << endl;
        if(path[0][0] != path[1][0]) sum = sum + 1;
        if(path[0][1] != path[1][1]) sum = sum + 1;
        if(path[0][2] != path[1][2]) sum = sum + 1;
        if(path[0][3] != path[1][3]) sum = sum + 1;

        if(path[1][0] != path[2][0]) sum = sum + 1;
        if(path[1][1] != path[2][1]) sum = sum + 1;
        if(path[1][2] != path[2][2]) sum = sum + 1;
        if(path[1][3] != path[2][3]) sum = sum + 1;

        if(path[0][0] != path[2][0]) sum = sum + 1;
        if(path[0][1] != path[2][1]) sum = sum + 1;
        if(path[0][2] != path[2][2]) sum = sum + 1;
        if(path[0][3] != path[2][3]) sum = sum + 1;

        if(ans > sum) ans = sum;
    }else{
        for(int i=v+1;i<=n;i++){
            if(ch[i]==0){
                ch[i]=1;
                strcpy(path[v], str[i]);
                DFS(v+1);
                ch[i]=0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt","rt",stdin);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=1;i<=n;i++)   cin >> str[i];
        DFS(0);
        cout << ans << '\n';
        ans = 2147000000;
    }
    return 0;
}