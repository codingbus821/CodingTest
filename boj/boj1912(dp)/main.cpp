//
//  main.cpp
//  boj1912
//
//  Created by 김병수 on 2020/11/29.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int dp[111111];

int main(int argc, const char * argv[]) {
    
    int n; cin >> n;
    int max=0;
    
    for(int i=0;i<n;i++){
        cin >> dp[i];
    }
    max = dp[0];
    
    for(int i=1;i<n;i++){
        if(dp[i-1]>0 && (dp[i]+dp[i-1])>0)
            dp[i] += dp[i-1];
        if(max < dp[i])
            max = dp[i];
    }
    
    cout << max;
    
    return 0;
}
