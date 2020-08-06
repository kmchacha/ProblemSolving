/*
'******************************************************************************
' 파일명    : pps86.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/28
' 문제      : 피자 배달 거리
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ch[20], m, dis ,res=2147000000, sum;
vector<pair<int, int> > hs;
vector<pair<int, int> > pz;
void dfs(int s, int L){
	if(L==m){
        sum=0;
        for(int j=0;j<hs.size();j++){
            int x1=hs[j].first;
            int y1=hs[j].second;
            dis=2147000000;
            for(int i=0; i<m; i++){
                int x2=pz[ch[i]].first;
                int y2=pz[ch[i]].second;
                dis=min(dis, abs(x1-x2)+abs(y1-y2));
            }
            sum += dis;
        }
        if(sum<res) res = sum;
	}
	else{
		for(int i=s; i<pz.size(); i++){
			ch[L]=i;
			dfs(i+1, L+1);
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, k;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> k;
            if(k==1){
                hs.push_back(make_pair(i, j));
            }else if(k==2){
                pz.push_back(make_pair(i, j));
            }
        }
    }
	dfs(0, 0);
    cout << res << endl;
	return 0;
}