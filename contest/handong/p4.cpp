#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct AA{
    string d;
    int c;
    AA(string a, int b){
        d=a;
        c=b;
    }
    bool operator < (AA &b) {
        return c > b.c;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int T, n;
    cin >> T;
    cin >> n;
    queue<pair<AA, AA> > Q, Q1;
    // 요일 교시 요일 교시
    for(int i=1;i<=n;i++){
        string d1, c1, d2, c2;
        cin >> d1 >> c1 >> d2 >> c2;
        int tmp1, tmp2;
        if(c1 == "A") tmp1=1;
        else if(c1 == "B") tmp1=2;
        else if(c1 == "C") tmp1=3;
        else if(c1 == "D") tmp1=4;
        else if(c1 == "E") tmp1=5;
        else if(c1 == "F") tmp1=6;

        if(c2 == "A") tmp2=1;
        else if(c2 == "B") tmp2=2;
        else if(c2 == "C") tmp2=3;
        else if(c2 == "D") tmp2=4;
        else if(c2 == "E") tmp2=5;
        else if(c2 == "F") tmp2=6;
        
        for(int i=0;i<Q.size();i++){
            Q1.push(make_pair(AA(d1,tmp1), AA(d2,tmp2)));
        }
        while(!Q1.empty()){
            AA temp1 = Q1.front().first;
            AA temp2 = Q1.front().second;
            Q1.pop();

            cout << temp1.c << " " << temp1.d << " " << temp2.c <<" " << temp2.d << endl;;
            if(temp1.c == )
        }
        Q.push(make_pair(AA(d1,tmp1), AA(d2,tmp2)));
    }

    return 0;
}
