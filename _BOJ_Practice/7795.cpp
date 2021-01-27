#include <iostream>
#include <algorithm>

using namespace std;

int arr1[20001], arr2[20001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt" , stdin);
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> arr1[i];
        for(int i=0;i<m;i++) cin >> arr2[i];

        sort(arr1, arr1+n);
        sort(arr2, arr2+m);

        int cnt = 0;
        for(int i=0;i<n;i++){
            int c = m;
            for(int j=m-1;j>=0;j--){
                if(arr1[i] > arr2[j]) break;
                c--;
            }
            cnt += c;
        }

        cout << cnt << '\n';
    }

    return 0;
}