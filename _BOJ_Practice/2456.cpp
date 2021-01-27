#include <iostream>
#include <algorithm>

using namespace std;

int cnt[4][4];   // cnt[i][j] i번쨰 학생 j점수의 개수
int sum[4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","rt",stdin);
    int n, max_idx=1;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        cnt[1][a]++;    cnt[2][b]++;    cnt[3][c]++;
        sum[1] += a;    sum[2] += b;    sum[3] += c;

        max_idx = (sum[1]>sum[2])?((sum[1]>sum[3])?1:3):((sum[2]>sum[3])?2:3);
    }

    // 최고점이 한명이냐 여러명이냐
    int c=0;
    for(int i=1;i<=3;i++) {
        if(sum[max_idx] == sum[i]) c++;
    }

    if(c==1){
        // 최고점이 한 명인 경우
        cout <<  max_idx << " " << sum[max_idx]<<'\n';
    }else{
        // 최고점이 두 명이상인 경우
        int flag=0;
        for(int i=3;i>=1;i--){
            if(sum[1]==sum[max_idx] && sum[2]==sum[max_idx]){
                if(cnt[1][i]==cnt[2][i]){
                    flag = 0;
                }else if(cnt[1][i]>cnt[2][i]){
                    flag = 1;
                }else {
                    flag = 2;
                }
            }
            if(flag!=0) break;

            if(sum[1]==sum[max_idx] && sum[3]==sum[max_idx]){
                if(cnt[1][i]==cnt[3][i]){
                    flag = 0;
                }else if(cnt[1][i]>cnt[3][i]){
                    flag = 1;
                }else {
                    flag = 3;
                }
            }
            if(flag!=0) break;

            if(sum[2]==sum[max_idx] && sum[3]==sum[max_idx]){
                if(cnt[2][i]==cnt[3][i]){
                    flag = 0;
                }else if(cnt[2][i]>cnt[3][i]){
                    flag = 2;
                }else {
                    flag = 3;
                }
            }
            if(flag!=0) break;

        }
        if(flag==0) cout << flag << " " << sum[max_idx] << '\n';
        else cout << flag << " " << sum[flag] << '\n';
    }

    return 0;
}