//
//  main.cpp
//  boj10573
//
//  Created by 김병수 on 2020/11/24.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

long long d[82][11];

int main(int argc, const char * argv[]) {
    
    int n;
    string s;
    
    cin >> n;
    
    for (int i = 0; i < 10; i++) d[1][i] = 1;
        for (int i = 1; i < 82; i++)
            for (int j = 0; j < 10; j++)
                for (int k = j; k < 10; k++)
                    d[i][j] += d[i - 1][k];
    
    while(n--){
        cin >> s;
        char prv = '0';
        
        bool lowch = false;
        for(auto i:s){
            if(prv > i){
                lowch = true;
                break;
            }
            prv = i;
        }
        if(lowch) cout << -1 << "\n";
        else{
            long long res = 0;
            res += d[s.length()+1][0];
            for(int i=0;i<s.length();i++){
                int num = s[i]-'0';
                for(int j=num+1;j<10;j++){
                    res -= d[s.length()-i][j];
                }
            }
            cout << res-1 << "\n";
        }
    }
    
    return 0;
}
