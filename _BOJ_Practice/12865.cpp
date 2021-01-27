#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int goods[100001][2];
int dp[101][100001]; // dp[a][b] = a번째 아이템 까지 고려하고, 무게 b까지 고려했을때 최대 얻을 수 있는 가치의 합

int DFS(int n, int v){ // n번째 아이템까지 고려하고, 배낭의 무게
   if(v > K || n==N) return 0;
   if(dp[n][v] > 0) return dp[n][v];

   if(goods[n][0] + v <= K) {
      dp[n][v] = max(DFS(n+1, v), DFS(n+1, v + goods[n][0]) + goods[n][1]);
   }else{
      dp[n][v] = max(DFS(n+1, v) ,0);
   }
   return dp[n][v];
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   //freopen("input.txt", "rt", stdin);
   cin >> N >> K;
   for(int i=0;i<N;i++){
      int w, v;
      cin >> w >> v;
      goods[i][0] = w;
      goods[i][1] = v; // for visualization
   }
   cout << DFS(0, 0);
   return 0;
}