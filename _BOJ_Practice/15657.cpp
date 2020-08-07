#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, ans[10];
vector<int> a;
void DFS(int s, int L){
    if(L==m){
        for(int i=0;i<L;i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    else {
        for(int i=s;i<n;i++){
            ans[L] = a[i];
            DFS(i, L+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        a.push_back(k);
    }
    sort(a.begin(), a.end());
    DFS(0, 0);

    return 0;
}