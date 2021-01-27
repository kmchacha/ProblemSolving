#include <iostream>

using namespace std;

int a[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        int k;
        cin >> k;
        a[k]++;
    }
    for(int i=1;i<=10000;i++){
        while(a[i]>0){
            cout << i << '\n';
            a[i]--;
        }
    }
    return 0;
}