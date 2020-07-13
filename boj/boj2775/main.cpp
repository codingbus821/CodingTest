//
//  main.cpp
//  boj1193
//
//  Created by 김병수 on 2020/07/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int getNum(int k, int n){
    if(n==1){
        return 1;
    }else if(k==0){
        return n;
    }else{
        return getNum(k-1, n)+getNum(k, n-1);
    }
}

int main(int argc, const char * argv[]) {
    
    int T,k,n;
    
    cin >> T;
    
    for(int i=0;i<T;i++){
        cin >> k >> n;
        cout << getNum(k,n) << "\n";
    }
    return 0;
}
