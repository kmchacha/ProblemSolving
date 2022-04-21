#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans[10], num[10], ch[10], n, m;
vector<int> a;

void DFS(int L){
    if(L==m){
        for(int i=0;i<L;i++){
            cout << ans[i] << " ";
        }
        cout << '\n'; 
    }else {
        int before = -1;
        for(int i=0;i<a.size();i++){
            if(ch[i]==0 && (i==0 || before != a[i])){
                before = a[i];
                ch[i] = 1;
                ans[L] = a[i];
                DFS(L+1);
                ch[i] = 0;
            }
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
    DFS(0);

    return 0;
}

// #include <cstdio>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int N, M;
// vector<int> v;
// bool chk[8];
// int nums[8];
 
// void dfs(int depth){
//     if (depth == M){
//         for (int i=0; i<M; ++i) printf("%d ", nums[i]);
//         puts("");
//         return;
//     }
//     bool used[10001] {false};
//     for (int i=0; i<v.size(); ++i){
//         if (used[v[i]] || chk[i]) continue;
//         used[v[i]] = true;
//         nums[depth] = v[i];
//         chk[i] = true;
//         dfs(depth + 1);
//         chk[i] = false;
//     }
// }
 
// int main() {
//     scanf("%d %d", &N, &M);
//     int val;
//     for (int i=0; i<N; ++i) {
//         scanf("%d", &val);
//         v.push_back(val);
//     }
//     sort(v.begin(), v.end());
//     dfs(0);
 
//     return 0;
// }