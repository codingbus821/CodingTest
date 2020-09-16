//
//  main.cpp
//  dfs
//
//  Created by 김병수 on 2020/09/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int a=INT_MAX;
string b;

void dfs(string str,int cnt){
    
    if(str.length() == 1){
        if(cnt < a){
            a=cnt;
            b=str;
        }
        return;
    }
    
    for(int i=1;i<str.length();i++){
        string fronts,backs,results;
        int front,back,result;
        
        fronts = str.substr(0,i);
        backs = str.substr(i);
        
        if(fronts[0] == '0' || backs[0] == '0')
            continue;
            
        
        front = stoi(fronts);
        back = stoi(backs);
        
        result=front+back;
        
        dfs(to_string(result),cnt+1);
    }
    
}

int main(int argc, const char * argv[]) {
    int n=9;
    vector<int> answer;
    
    string str = to_string(n);
    
    dfs(str,0);
    
    cout << a << b;
    
    answer.push_back(a);
    answer.push_back(stoi(b));
    
    return 0;
}
