#include <iostream>
#include <algorithm>

using namespace std;

int a[301];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt","rt",stdin);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    
    return 0;
}