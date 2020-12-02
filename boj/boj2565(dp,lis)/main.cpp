//
//  main.cpp
//  boj2565
//
//  Created by 김병수 on 2020/11/28.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[111];

int main(int argc, const char * argv[]) {
    
    int n;
    int a, b;
    vector<pair<int, int>> v;
    int res=0;
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<v.size();i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(v[i].second > v[j].second && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
                if(res<dp[i])
                    res = dp[i];
            }
        }
    }
    
    cout << n-res;
    
    return 0;
}
