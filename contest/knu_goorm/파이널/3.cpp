#include <bits/stdc++.h>

using namespace std;

string str[30][30];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> str[i][j];
            cout << str[i][j] << " ";
        }
        cout << endl;
    }
    string s1, s2;
    cin >> s1 >> s2;
    
    int x1=-1, y1=-1, x2=-1, y2=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(str[i][j] == s1) {
                x1 = i;
                y1 = j;
            }
            if(str[i][j] == s2) {
                x2 = i;
                y2 = j;
            }
        }

        if(x1 != -1 && x2 != -1 && y1 != -1 && y2 != -1) break;
    }

    cout << abs(x1-x2) + abs(y1-y2) << '\n';

    return 0;
}