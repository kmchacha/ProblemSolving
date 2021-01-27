#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// 쉬운 문제 100점, 어려운 문제 140점

// 전략
// 어려운 문제에 대해서 정렬을 수행하고 문제를 푼 후
// 쉬운문제에 대해서 정렬을 수행하고 문제를 푼다. 

priority_queue<pair<int, int> > pQ;
priority_queue<pair<int, int> > pQ2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, l, k, score=0, cnt=0; // score 점수, cnt 문제를 푼 개수
    cin >> n >> l >> k; // n 문제의 개수, l 역량, k 풀 수 있는 문제의 최대 개수

    for(int i=1;i<=n;i++){
        int easy, hard;
        cin >> easy >> hard;
        pQ.push(make_pair(-hard,-easy));
    }

    while(!pQ.empty()){
        int cur_hard = -pQ.top().first;
        int cur_easy = -pQ.top().second;
        pQ.pop();
        if(cur_hard <= l && cnt < k){
            score += 140;
            cnt++;
            continue;
        }

        pQ2.push(make_pair(-cur_easy,-cur_hard));
    }

    while(!pQ2.empty()){
        int cur_easy = -pQ2.top().first;
        pQ2.pop();
        if(cur_easy <= l && cnt < k){
            score += 100;
            cnt++;
        }
    }

    cout << score << '\n';
    return 0;
}