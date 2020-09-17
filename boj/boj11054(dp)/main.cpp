//
//  main.cpp
//  boj11054
//
//  Created by 김병수 on 2020/09/16.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000];
int dp[1000][2];

int main(int argc, const char * argv[]) {
    
    int N;
    vector<int> v;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
        dp[i][0]=1;
        dp[i][1]=1;
    }
    
    for(int i=0;i<N;i++){
        for(int j=i;j>=0;j--){
            if(arr[j] < arr[i]){
                dp[i][0] = max((dp[j][0])+1,dp[i][0]);
            }
        }
    }
    
    for(int i=N-1;i>=0;i--){
        for(int j = i;j<N;j++){
            if(arr[i] > arr[j])
                dp[i][1] = max((dp[j][1])+1,dp[i][1]);
        }
    }
    
    for(int i=0;i<N;i++){
        v.push_back(dp[i][0] + dp[i][1]);
    }
    
    sort(v.begin(),v.end());
    
    cout << v[N-1] - 1;
    
    return 0;
}
