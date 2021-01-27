#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

long long check(int v, vector<int> &a){
    return (a[v] + a[v+1])/10000000.0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int t, x, n;
    cin >> t;
    while(1){
        cin >> x >> n;
        if(cin.eof()) break;

        vector<int> a(n+1, 0);
        for(int i=1;i<=n;i++){
            // 블록의 길이는 10 센티미터 (100000000 나노미터)를 넘지 않는다. 10^7 = 1cm
            cin >> a[i];
        }

        sort(a.begin()+1, a.end());
        int lt=1, rt=n;
        while(lt<=rt){
            int mid = (lt + rt) / 2;
            
        }
        //if(idx != -1) cout << "yes "<< a[idx] << " " << a[idx+1] << '\n';
        //else cout << "danger" << '\n';
    }
    return 0;
}