//
//  main.cpp
//  boj2748
//
//  Created by 김병수 on 2020/08/31.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

long long arr[91];

long long dp(int x){
    if(x<=1)
        return x;
    if(arr[x] != 0)
        return arr[x];
    
    return arr[x] = dp(x-2) + dp(x-1);
}

int main(int argc, const char * argv[]) {
    
    int n;
    
    cin >> n;
    
    cout << dp(n);
    
    return 0;
}
