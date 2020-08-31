//
//  main.cpp
//  boj1904
//
//  Created by 김병수 on 2020/08/31.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

long long arr[1000001];

long long dp(int x){
    
    if(x == 1)
        return 1;
    if(x == 2)
        return 2;
    if(arr[x] != 0)
        return arr[x];
    
    return arr[x] = (dp(x-2) + dp(x-1)) % 15746;
    
}

int main(int argc, const char * argv[]) {
    
    int N;
    
    cin >> N;
    
    cout << dp(N);
    
    return 0;
}
