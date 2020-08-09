#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int ch[1001];
queue<int> Q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        Q.push(i);
    }

    cout << "<";
    int cnt=0;
    while(Q.size() != 1){
        int x = Q.front();
        Q.pop();

        cnt++;
        if(cnt==k) {
            cnt=0;
            cout <<  x << ", ";
            continue;
        }
        Q.push(x);
    }
    int ans = Q.front();
    cout << ans << ">";
    
    return 0;
}