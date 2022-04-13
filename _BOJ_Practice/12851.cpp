#include <bits/stdc++.h>

using namespace std;

int answerT, answerCnt;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int N, K, flag=0;
    cin >> N >> K;
    queue<pair<int, int> > Q;
    Q.push(make_pair(N, 0));
    while(!Q.empty()){
        pair<int, int> curNode = Q.front();
        int curPos = curNode.first;
        int curCnt = curNode.second;
        Q.pop();

        if(curPos == K) {
            answerCnt++;
            flag = curCnt;
            answerT = curCnt;
            continue;
        }

        if(flag <= curCnt && curPos + 1 <=100000) {
            Q.push(make_pair(curPos + 1, curCnt + 1));
        }

        if(flag <= curCnt && curPos - 1 >= 0) {
            Q.push(make_pair(curPos - 1, curCnt + 1));
        }

        if(flag <= curCnt && curPos * 2 <=100000) {
            Q.push(make_pair(curPos * 2, curCnt + 1));
        }

    }
        
    cout << answerT << '\n' << answerCnt << '\n';
    return 0;
}