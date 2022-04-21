#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int a[201][4], score[201];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            int flag=0;
            for(int k=1;k<=n;k++){
                if(j==k) continue;
                
                if(a[j][i] == a[k][i]) { 
                    flag=1; 
                    break;
                }
            }
            if(flag==0) score[j]+=a[j][i];
        }
    }
    for(int i=1;i<=n;i++){
        cout << score[i] << '\n';
    }
    return 0;
}