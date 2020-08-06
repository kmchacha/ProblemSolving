// 사탕 게임 3085
#include <iostream>

int
main(int argc, const char* argv[])
{   
    using namespace std;
    int E, S, M,i;
    cin >> E >> S >> M;
    int e=1, s=1, m=1;

    for(i=1;;i++){
        if(e==E && s==S && m==M){
            cout << i << '\n';
            break;
        }
        e += 1;
        s += 1;
        m += 1;
        if(e==16){
            e=1;
        }
        if(s==29){
            s=1;
        }
        if(m==20){
            m=1;
        }
    }
    
    return 0;
}