#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt","rt",stdin);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int cnt=0; int max_cnt=0; 
    long long val = -(1ll << 62)-1;
    for(int i=0;i<n;i++){
        if(i==0 || arr[i-1] == arr[i]){
            cnt++;
        }else{
            if(max_cnt < cnt) {
                max_cnt= cnt;
                val = arr[i-1];
            }
            cnt = 1;
        }
    }
    if(max_cnt < cnt) val = arr[n-1];
    cout << val << '\n';

    return 0;
}