#include <bits/stdc++.h>

using namespace std;

int arr[1005], ch[1005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, K;
    cin >> N >> K;
    for(int i=1;i<=N;i++) arr[i] = i;
    cout << "<";
    int cnt = 0, idx = 1, answerCnt=0;
    while(answerCnt < N) {
        if(ch[idx] == 0) {
            cnt++;

            if(cnt == K) {
                cnt = 0;
                ch[idx] = 1;
                answerCnt++;
                
                if(answerCnt<N) cout << idx << ", ";
                else cout << idx << ">";
            }
        }
        idx++;
        if(idx == N+1) idx = 1;
    }
    return 0;
}