#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;
int map[26][26], ans[26], cnt;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int main(){
    // ios_base::sync_with_stdio(false); => printf scanf 사용시, 주석처리한다
    // cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    queue<pair<int, int> > Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(map[i][j]==1){
                Q.push(make_pair(i,j));
                map[i][j]=0;
                int w=1;
                while(!Q.empty()){
                    pair<int, int> tmp = Q.front();
                    Q.pop();
                    for(int k=0;k<4;k++){
                        int xx = tmp.x + dx[k];
                        int yy = tmp.y + dy[k];
                        if(map[xx][yy]==1){
                            map[xx][yy]=0;
                            Q.push(make_pair(xx,yy));
                            w++;
                        }
                    }
                }
                ans[cnt]=w;
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    sort(ans, ans+cnt);
    for(int i=0;i<cnt;i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}