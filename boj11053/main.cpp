//
//  main.cpp
//  boj11053
//
//  Created by 김병수 on 2020/09/16.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int dp[1000];

int main(int argc, const char * argv[]) {
    
    int A;
    
    cin >> A;
    
    for(int i=0;i<A;i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    
    for(int i=0;i<A;i++){
        for(int j = i;j>=0;j--){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[j] + 1,dp[i]);
            }
        }
    }
    
    sort(dp,dp+A);
    
    cout << dp[A-1];
    
    return 0;
}
