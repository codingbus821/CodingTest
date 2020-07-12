//
//  main.cpp
//  boj5585
//
//  Created by 김병수 on 2020/07/11.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

bool desc(int a,int b){
    return a>b;
}

int main(int argc, const char * argv[]) {
    
    string N;
    int tmp;
    int sum = 0;
    
    cin >> N;
    
    vector<int> v;
    
    for(int i=0;i<N.size();i++){
        tmp = (int)N[i]-'0';
        v.push_back(tmp);
    }
    
    sort(v.begin(),v.end(),desc);
    
//    for(int i = 0;i<v.size();i++){
//        if(max < v[i]*(N-i))
//            max = v[i]*(N-i);
//    }
    
    string str="";
    
    for(int i = 0;i<v.size();i++){
        str = str + (char)(v[i]+48);
        sum += (int)(char)v[i]+48;
    }
    
//    cout << str;
    
    if(sum % 3 == 0 && v[v.size()-1]==0){
        cout << str;
    }else{
        cout << -1;
    }
    
    
    return 0;
}
