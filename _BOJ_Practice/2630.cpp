#include <iostream>

using namespace std;

int map[130][130], ans[2];

void divide(int s, int e){
    cout << s << " " << e << endl;
    int flag = 0, temp = map[s][e];
    for (int i = s; i <= e; i++) {
        for (int j = s; j <= e; j++) {
            if (map[i][j] != temp)  flag = 1;
        }
    }
    if (flag == 0) {
        ans[temp] += ((e - s + 1) * (e- s +1));
        return;
    }
    if(s<e){
        int mid = (s + e) / 2;
        divide(s, mid);
        divide(mid+1, e);
    }
    //cout << s1 << " " << e1 << " " << s2 << " " << e2 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt","rt",stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }  
    }
    divide(1, n);
    cout << ans[0] << "\n"<< ans[1];
    return 0;
}