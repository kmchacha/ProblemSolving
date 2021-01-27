#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n, ch[10], ans=2147000000;
string temp, x;

void DFS(int v){
    if(v==n){
        if(stoi(x) < stoi(temp)) {
            ans = min(ans, stoi(temp));
        }
    }else {
        for(int i=0;i<n;i++){
            if(ch[i]==0){
                ch[i]=1;
                temp[v]=x[i];
                DFS(v+1);
                ch[i]=0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> x;
    n = x.size();
    DFS(0);
    if(ans==2147000000) cout << 0 << '\n';
    else cout << ans << '\n';
    
    return 0;
}
