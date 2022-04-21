#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int a[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    // 동전의 종류 : 1 2 5 7
    for(int i=1;i<=7;i++){
        a[i] = i; 
    }
    a[1] = 1;
    a[2] = 1;
    a[5] = 1;
    a[7] = 1;
    for(int i=1;i<=7;i++){
        if(i-2>=0) a[i] = a[i-2]+1;
        if(i-5>=0) a[i] = a[i-5]+1;
        if(i-7>=0) a[i] = a[i-7]+1;
    }
    for(int i=8;i<=n;i++){
        a[i] = min(a[i-1]+1, min(a[i-2]+1, min(a[i-5]+1, a[i-7]+1)));
    }
    cout << a[n] << '\n';
    return 0;
}