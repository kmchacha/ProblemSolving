#include <iostream>
#include <algorithm>

using namespace std;

int recur(long long a, int b, int c){
    if(b==0) return 0;

    a *= a;
    recur(a, b-1, c);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  long long A, B, C;
  cin >> A >> B >> C;
  cout << recur(A, B, C);


  return 0;
}