/*
'******************************************************************************
' 파일명    : dp6.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/30
' 문제      : 가장 높은 탑 쌓기
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct block {
    int x,h,w;

    block(int a, int b, int c){
        x=a;
        h=b;
        w=c;
    }

    bool operator < (const block &b) const{
        return x > b.x; // 내림차순
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    
    int n, a, b, c, res=0, max_h=0;
    cin >> n;
    vector<block> blocks;
    vector<int> dp(n,0);
    for(int i=1;i<=n;i++){
        cin >> a >> b >> c;
        blocks.push_back(block(a,b,c));
    }

    sort(blocks.begin(), blocks.end()); // **
    dp[0]=blocks[0].h;
    res=dp[0];
    for(int i=1;i<n;i++){
        max_h=0;
        for(int j=i-1;j>=0;j--){
            if(blocks[j].w > blocks[i].w && dp[j] > max_h){
                max_h = dp[j];
            }
        }
        dp[i] = max_h + blocks[i].h;
        res=max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}