//
//  main.cpp
//  boj10872
//
//  Created by 김병수 on 2020/07/15.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int fac(int n){
    
    if(n == 1){
        return 1;
    }else{
        return n*fac(n-1);
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    
    cin >> N;
    
    if(N == 0){
        cout << 1;
    }else{
        cout << fac(N);
    }
    
    return 0;
}
