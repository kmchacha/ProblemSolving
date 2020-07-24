#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> a; // vector<int> a(10); -> 10이라는 SIZE, 원소 값은 기본적으로 0 이다 
    // a[1]=5; (x)
    a.push_back(6);
    a.push_back(8);
    a.push_back(11);
    cout << a.size() << endl; // 3
    cout << a[1] << endl; // 8

    vector<int> c[3]; // c라는 빈 vector가 3개 생기는 것이다
    c[0].push_back(1);
    c[0].push_back(3);
    c[0].push_back(5);
    c[1].push_back(2);
    c[1].push_back(4);
    c[1].push_back(6);
    c[2].push_back(7);
    cout << c[1][1] << endl; // 4
    cout << c[2][0] << endl; // 7

    vector<pair<int, int> > g[3];
    g[1].push_back({3, 5});
    g[1].push_back({4, 7});
    g[1].push_back({5, 9});
    g[2].push_back(make_pair(6, 7));
    cout << g[2][0].first << " " << g[2][0].second << endl;

    return 0;
}