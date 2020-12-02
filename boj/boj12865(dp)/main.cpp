//
//  main.cpp
//  boj12865
//
//  Created by 김병수 on 2020/12/02.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int w[111];
int v[111];
int dp[111][111111];

int main(int argc, const char * argv[]) {
    
    int N, K; cin >> N >> K;
    int ans=0;
    
    for(int i=1;i<=N;i++){
        cin >> w[i] >> v[i];
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(w[i] <= j)
                dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-w[i]]);
            else
                dp[i][j] = dp[i-1][j];
            
            ans = max(ans,dp[i][j]);
        }
    }
    
    cout << ans;
    
    return 0;
}
