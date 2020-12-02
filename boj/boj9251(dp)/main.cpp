//
//  main.cpp
//  boj9251
//
//  Created by 김병수 on 2020/11/29.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int dp[1111][1111];

int main(int argc, const char * argv[]) {
    
    string str1,str2; cin >> str1 >> str2;
    
    for(int i=0;i<str1.size();i++){
        for(int j=0;j<str2.size();j++){
            if(str1[i] == str2[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    
    cout << dp[str1.size()][str2.size()];
    
    return 0;
}
