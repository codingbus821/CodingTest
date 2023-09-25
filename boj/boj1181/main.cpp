//
//  main.cpp
//  boj1181
//
//  Created by 김병수 on 2021/02/25.
//  Copyright © 2021 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareWith(string a, string b){
    if(a.length() == b.length())
        return a<b;
    return a.length()<b.length();
}

int main(int argc, const char * argv[]) {
    
    int num;
    vector<string> vec;
    
    cin >> num;
    for(int i=0;i<num;i++){
        string str;
        cin >> str;
        if(find(vec.begin(),vec.end(),str) == vec.end())
            vec.push_back(str);
    }
    sort(vec.begin(),vec.end(),compareWith);
    
    for(int i=0;i<vec.size();i++){
        cout << vec[i] <<'\n';
    }
    
    return 0;
}
