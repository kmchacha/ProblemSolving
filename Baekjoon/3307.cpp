#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
/*
3
0 9
8 1
13 7
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n; // 풍선의 개수
    int x, r; // x 좌표, 최대 가질 수 있는 반지름의 길이
    vector<pair<int, float> > q;
    cin >> n;

    cin >> x >> r;
    q.push_back(make_pair(x,r));

    for(int i=2;i<=n;i++){
        cin >> x >> r;
        
        for(int k=0;k<q.size();k++){
            int pre_x = q[k].first;
            float pre_r = q[k].second;


            float d = sqrt(pow(abs(x-pre_x),2) + pow(abs(r-pre_r), 2));
           //if()
                
        }
        
    }
    return 0;
}