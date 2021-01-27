#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n = 8;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int a[10];
    for(int i=1;i<=n;i++)   cin >> a[i];
    int flag=0;
    if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5&&a[6]==6&&a[7]==7&&a[8]==8) flag=1;
    else if(a[1]==8&&a[2]==7&&a[3]==6&&a[4]==5&&a[5]==4&&a[6]==3&&a[7]==2&&a[8]==1) flag=2;

    if(flag==0) cout << "mixed";
    else if(flag==1) cout << "ascending";
    else cout << "descending";
    return 0;
}