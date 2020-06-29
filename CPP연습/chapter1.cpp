//
//  chapter1.cpp
//  LearningCpp
//
//  Created by 차경민 on 2020/06/26.
//  Copyright © 2020 rudals. All rights reserved.
//

#include <iostream>
#include <bitset>

int main(int argc, const char * argv[]) {
    
    using namespace std;
    //std::cout << "This is chapter11\n" << std::endl;

    int j = 256;
    int i = -1;
    int k  = 123;
    char a = 'H';

    cout << j << endl;
    cout << (uintptr_t)static_cast<void*>(&i) << endl;

    return 0;
}
