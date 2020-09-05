//
//  main.cpp
//  boj2579
//
//  Created by 김병수 on 2020/08/31.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

long long arr[300];
long long dp[300];

int main(int argc, const char * argv[]) {
    
    int n;
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    dp[1] = arr[0]+arr[1];
    dp[2] = max(arr[0]+arr[2],arr[1]+arr[2]);
    
    for(int i=3;i<n;i++){
        dp[i] = max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]);
    }
    
    cout << dp[n-1];
    
    return 0;
}
