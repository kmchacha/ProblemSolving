#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i, j, a, ch[11], flag;
    cin >> n;
    for(i=1;i<=n;i++){
        flag = 0;
        for(j=1;j<=10;j++){
            cin >> a;
            if(a == ((j-1)%5+1)) {
                ch[j] = 1;
            }
        }
        
        for(j=1;j<=10;j++){
            if(!ch[j]) flag = 1;
            ch[j] = 0; 
        }
        if(!flag) cout << i << endl;
    }
    return 0;
}