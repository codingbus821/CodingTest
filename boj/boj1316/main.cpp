//
//  main.cpp
//  boj11654
//
//  Created by 김병수 on 2020/07/12.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    string str;
    vector<char> v;
    int result=0;
    int ch = 0;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> str;
        
        char ex=str[0];
        v.clear();
        ch = 0;
        
        for(int j=0;j<str.size();j++){
            for(int k=0;k<v.size();k++){
                if(v[k] == str[j]){
                    ch = 1;
                    break;
                }
            }
            if(ch == 1){
                break;
            }
            if(str[j] != ex){
                v.push_back(ex);
            }
            ex = str[j];
        }
        if(ch != 1)
            result++;
    }
    
    cout << result;
    
    return 0;
}
