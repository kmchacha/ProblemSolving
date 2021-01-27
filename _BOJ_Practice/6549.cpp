#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];

void divide(int s, int e){
    int mid = (s + e) / 2, min_value=2147000000, min_loc=s;
    for(int i=s;i<=e;i++){
        if(min_value > a[i]) {
            min_value = a[i];
            min_loc = i;
        }
    }
    int value, minn=2147000000;
    while(s<=e){
        divide(s, min_loc);
        divide(min_loc+1, e);
        for(int i=s;i<=e;i++){
            minn = min(a[i], minn);
        }
        value = (e-s+1) * minn;
        cout << value << endl;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt","rt",stdin);

    while(1){
        int n;
        cin >> n;
        if(n==0) break;

        for(int i=1;i<=n;i++)   cin >> a[i];
        divide(1,n);

    }

    return 0;
}