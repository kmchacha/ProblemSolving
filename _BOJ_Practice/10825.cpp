#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
struct people{
    string name;
    int math, eng, kor;
    people(string n, int a, int b , int c){
        name = n;
        kor = a;
        eng = b;
        math = c;
    }
};

bool compare(people& p1, people& p2){
    if(p1.kor != p2.kor) return p1.kor > p2.kor;
    else if(p1.eng != p2.eng) return p1.eng < p2.eng;
    else if(p1.math != p2.math) return p1.math > p2.math;
    else {
        int n = min(p1.name.length(), p2.name.length());
        for(int i=0; i<n; i++){
            if(p1.name[i] != p2.name[i]) return p1.name[i] < p2.name[i];
        }

        return p1.name < p2.name;
    }
}
vector<people> p;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string n;
        int k, e, m;
        cin >> n >> k >> e >> m;
        p.push_back(people(n,k,e,m));
    }
    sort(p.begin(), p.end(), compare);
    for(int i=0;i<n;i++)    cout <<p[i].name << '\n';
    return 0;
}