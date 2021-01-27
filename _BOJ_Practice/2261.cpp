#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.first!=b.first) return a.first > b.first;
    else return a.second < b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt","rt",stdin);
    int n;
    cin >> n;
    vector<pair<int, int> > loc(n+1, make_pair(0,0));
    vector<pair<int, int> > loc1(n+1, make_pair(0,0));

    for(int i=1;i<=n;i++)   cin >> loc[i].first >> loc[i].second;

    loc1 = loc;
    sort(loc.begin()+1, loc.end());
    sort(loc1.begin()+1, loc1.end(), compare);
    
    //for(int i=1;i<=n;i++) cout << loc[i].first << " "<< loc[i].second << endl;
    cout << endl;
    for(int i=1;i<=n;i++) cout << loc[i].first << " "<< loc[i].second << endl;


    long long min1 = 9223372036800000000; long long min2 = 9223372036800000000;
    
    long long pre_x1 = loc[1].first;  long long pre_y1 = loc[1].second;
    //long long pre_x2 = loc1[1].first; long long pre_y2 = loc1[1].second;
    for(int i=2;i<=n;i++){
        long long x1 = loc[i].first;  long long y1 = loc[i].second;
        //long long x2 = loc1[i].first; long long y2 = loc1[i].second;

        if (min1 > (pow(abs(x1-pre_x1),2) + pow(abs(y1-pre_y1),2))) min1 = pow(abs(x1-pre_x1),2) + pow(abs(y1-pre_y1),2);
        //if (min2 > (pow(abs(x2-pre_x2),2) + pow(abs(y2-pre_y2),2))) min2 = pow(abs(x2-pre_x2),2) + pow(abs(y2-pre_y2),2);

        pre_x1 = x1; pre_y1 = y1;
        //pre_x2 = x2; pre_y2 = y2;
        if(min1 ==0 || min2 == 0) break;
    }

    long long ans = min(min1,min2);
    cout << ans;
    return 0;
}