//
//  main.cpp
//  boj10870
//
//  Created by 김병수 on 2020/07/15.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int fi(int n){
    
    if(n==0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fi(n-1)+fi(n-2);
    }
    
}

int main(int argc, const char * argv[]) {
    
    int n;
    
    cin >> n;
    
    cout << fi(n);
    
    return 0;
}
