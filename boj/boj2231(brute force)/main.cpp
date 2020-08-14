//
//  main.cpp
//  boj2231
//
//  Created by 김병수 on 2020/07/20.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string N;
    int ans = -1;
    
    cin >> N;
    
    for(int i=stoi(N);i>=0;i--){
        int full;
        
        full = i;
        for(int j=0;j<to_string(i).size();j++){
            full += to_string(i)[j]-'0';
        }
        
        if(full == stoi(N)){
            ans = i;
        }
    }
    
    if(ans == -1){
        cout << 0;
    }else{
        cout << ans;
    }
    
    return 0;
}
